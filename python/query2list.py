#!/usr/bin/env python
# sort query results from gStore or make a delete script
#
# Jan 2015 xaratustrah
#
# Please pipe the contents into the script
#

import re, sys

GSTORE = '/cvmfs/it.gsi.de/gstore/gstore64'


def make_list(for_delete=False):
    data = sys.stdin.readlines()
    flat_list = []
    delete_list = []
    for line in data[1:]:
        line = line.split()
        full_path = re.split('^[0-9]+:', line[0])[1:]
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


# -------------

if __name__ == "__main__":
    if len(sys.argv) == 1:
        make_list()
    if len(sys.argv) == 2:
        if sys.argv[1] == '-d':
            make_list(True)
        else:
            print(
                'Pipe the output of gStore into the script. No arguments for simple sorted list or -d for sorted delete list.')
    if len(sys.argv) > 2:
        print(
            'Pipe the output of gStore into the script. No arguments for simple sorted list or -d for sorted delete list.')
