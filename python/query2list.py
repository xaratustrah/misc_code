#!/usr/bin/env python
# sort query results from gStore or make a delete script
#
# Jan 2015 xaratustrah

import re
import sys

GSTORE = '/cvmfs/it.gsi.de/gstore/gstore64'


def make_list(for_delete=False):
    data = sys.stdin.readlines()
    flatlist = []
    delete_list = []
    out = []
    for line in data[1:]:
        count = 0
        index = line.find('STAGE') & line.find('CACHE') & line.find('TAPE') - 22
        while line[index - count] != ' ':
            count += 1
        count += 1
        line = line[0:index - count]
        fullpath = re.split('^[0-9]+:', line)[1:]
        fullpath[0] = fullpath[0].replace(' ', '\ ')

        flatlist.extend(fullpath)
        separated = fullpath[0].split('/')
        delete_list.append(GSTORE + " delete '" + separated[-1] + "' " + separated[1] + " '/" + '/'.join(
            map(str, separated[2:-1])) + "'")

    flatlist.sort()
    delete_list.sort()
    if for_delete:
        out = delete_list
    else:
        out = flatlist

    print('%s' % '\n'.join(map(str, out)))


if __name__ == "__main__":
    if len(sys.argv) == 1:
        make_list()
    if len(sys.argv) == 2:
        if (sys.argv[1] == '-d'):
            make_list(True)
        else:
            print('No arguments for simple sorted list or -d for sorted delete list.')
    if len(sys.argv) > 2:
        print('No arguments for simple sorted list or -d for sorted delete list.')
