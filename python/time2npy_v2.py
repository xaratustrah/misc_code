#!/usr/bin/env python

"""
This code converts data in TIQ format and extracts the data in numpy format
"""

import os, sys
import xml.etree.ElementTree as et
import numpy as np
import argparse
import logging as log

verbose = False

def tiq2npy(filename, nframes = 10, lframes = 1024, sframes = 1):
    """
    Process the input file and return a numpy array.
    """
    
    filesize = os.path.getsize(filename)
    log.info("File size is {} bytes.".format(filesize))
    filename_wo_ext = os.path.splitext(filename)[0]
    
    with open (filename) as f:
        line = f.readline()
    data_offset = int(line.split("\"")[1])

    with open(filename, 'rb') as f:
        ba = f.read(data_offset)

    xmltree = et.fromstring(ba)
    for elem in xmltree.iter(tag='{http://www.tektronix.com}Frequency'):
        center=float(elem.text)
    for elem in xmltree.iter(tag='{http://www.tektronix.com}MaxSpan'):
        span=float(elem.text)
    for elem in xmltree.iter(tag='{http://www.tektronix.com}Scaling'):
        scale=float(elem.text)
    for elem in xmltree.iter(tag='{http://www.tektronix.com}SamplingFrequency'):
        fs=float(elem.text)

    log.info("Center {0} Hz, span {1} Hz, sampling frequency {2} scale factor {3}.".format(center, span, fs, scale))
    log.info("Header size {} bytes.".format(data_offset))

    with open (filename_wo_ext + '.xml', 'wb') as f3 : 
        f3.write(ba)
    log.info("Header saved in an xml file.")
        
    total_nbytes = 8 * nframes * lframes # 8 comes from 2 times 4 byte integer for I and Q
    start_nbytes = 8 * (sframes - 1 ) * lframes
    log.info("Proceeding to read binary section, 32bit (4 byte) little endian.")
    log.info("Total number of frames: {0} = {1}s".format((filesize-data_offset)/8/lframes, (filesize-data_offset)/8/fs))
    log.info("Frame length: {0} data points = {1}s".format(lframes, lframes/fs))
    log.info("Frame offset: {0} = {1}s".format(sframes, start_nbytes/fs))
    log.info("Reading {0} frames = {1}s.".format(nframes, total_nbytes/fs))

    with open (filename, 'rb') as f:
        f.seek(data_offset + start_nbytes)
        ba = f.read(total_nbytes)

    ar = np.array([], dtype=complex)
    for i in range (0, len(ba), 8):
        I = int.from_bytes(ba[i:i+4], byteorder = 'little')
        Q = int.from_bytes(ba[i+4:i+8], byteorder = 'little')
        ar = np.append(ar, scale * complex(I, Q))
        if verbose :
            sys.stdout.write('\rProgress: ' + str(int(i*100/len(ba)+1))+'% ')
            sys.stdout.flush()

    if verbose : print('Done.\n')
    log.info("Output complex array has a size of {}.".format(ar.size))
    dic = {'center': center, 'span': span, 'fs': fs, 'lframes': lframes, 'data': ar}
    np.save(filename_wo_ext + '.npy', dic)
    # in order to read use: data = x.item()['data'] or data = x[()]['data'] other wise you get 0-d error
    return dic


if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("filename", type=str, help = "Name of the input file.")
    parser.add_argument("-v", "--verbose", help="Increase output verbosity", action="store_true")
    parser.add_argument("-n", "--nframes", nargs = '?', type=int, const = 10, help = "Number of frames, default is 10.")
    parser.add_argument("-l", "--lframes", nargs = '?', type=int, const = 1024, help = "Length of frames, default is 1024.")
    parser.add_argument("-s", "--sframes", nargs = '?', type=int, const = 1, help = "Starting frame, default is 1.")
    
    args = parser.parse_args()
    if args.verbose:
        log.basicConfig(level=log.DEBUG)
        verbose = True
        
    nframes = 10 if not args.nframes else args.nframes
    lframes = 1024 if not args.lframes else args.lframes
    sframes = 1 if not args.sframes else args.sframes
    
    log.info("File {} passed for processing.".format(args.filename))
    
    tiq2npy(args.filename, nframes, lframes, sframes)

