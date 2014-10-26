#!/usr/bin/env python
# sort query results from gStore

import re
import sys

def main(argv):
    with open(argv[0], 'r') as f:
        data = f.readlines()
    out=[]
    for line in data[1:]:
        words=line.split()
        out.extend(re.split('^[0-9]+:', words[0])[1:])
    out.sort()
    print ('%s' % '\n'.join(map(str, out)))


if __name__ == "__main__":
    if (len(sys.argv) == 2):
        main(sys.argv[1:])
    else:
        print ('Wrong number of argumetns!')
