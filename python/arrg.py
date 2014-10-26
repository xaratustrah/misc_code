#!/usr/bin/env python

import argparse
import logging as log

parser = argparse.ArgumentParser()
parser.add_argument("filename", type=str, help = "Name of the input file.")
parser.add_argument("-v", "--verbose", help="increase output verbosity", action="store_true")
args = parser.parse_args()
if args.verbose:
    log.basicConfig(level=log.DEBUG)
log.info("File name {0} passed for processing.".format(args.filename))
print("The file name is {0}".format(args.filename))



