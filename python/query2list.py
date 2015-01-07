#!/usr/bin/env python
# sort query results from gStore or make a delete script
#
# Jan 2015 xaratustrah

import re
import sys

GSTORE = '/cvmfs/it.gsi.de/gstore/gstore64'


def make_list(for_delete=False):
    data = sys.stdin.readlines()
    flat_list = []
    delete_list = []
    for line in data[1:]:
        count = 0
        index = line.find('STAGE') & line.find('CACHE') & line.find('TAPE') - 22
        while line[index - count] != ' ':
            count += 1
        count += 1
        line = line[0:index - count]
        full_path = re.split('^[0-9]+:', line)[1:]
        full_path[0] = full_path[0].replace(' ', '?')

        flat_list.extend(full_path)
        separated_full_path = full_path[0].split('/')
        delete_list.append(
            GSTORE + " delete '" + separated_full_path[-1] + "' " + separated_full_path[1] + " '/" + '/'.join(
                map(str, separated_full_path[2:-1])) + "'")

    flat_list.sort()
    delete_list.sort()
    if for_delete:
        print('%s' % '\n'.join(map(str, delete_list)))
    else:
        print('%s' % '\n'.join(map(str, flat_list)))


if __name__ == "__main__":
    if len(sys.argv) == 1:
        make_list()
    if len(sys.argv) == 2:
        if sys.argv[1] == '-d':
            make_list(True)
        else:
            print('No arguments for simple sorted list or -d for sorted delete list.')
    if len(sys.argv) > 2:
        print('No arguments for simple sorted list or -d for sorted delete list.')
