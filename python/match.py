#!/usr/bin/env python
"""
Matches LaTeX tags

June 2015
Xaratustrah
"""
import fileinput, re
import sys

if __name__ == '__main__':

    with open(sys.argv[1], 'r') if sys.argv[1] is not "-" else sys.stdin as f:
        data = f.read()
        found = re.findall('(?s)\\begin\{figure\}(.*?)\\end\{figure\}',data)
        print(found)
