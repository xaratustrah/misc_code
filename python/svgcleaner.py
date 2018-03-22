#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Cleanup PDF / SVG

First install **pdf2svg** (from https://github.com/dawbarton/pdf2svg):

pdf2svg input.pdf input_%04d.svg all
python svgcleaner.py *.svg


then merge using of the tools below:

pdfunite from from [Poppler](http://poppler.freedesktop.org/):
pdfunite *.pdf output.pdf


pdfjam from [pdfpages](http://www.ctan.org/tex-archive/macros/latex/contrib/pdfpages/):
pdfjam *.pdf -o output.pdf

pdftk from [Ghostscript](http://www.ghostscript.com/):
pdftk *.pdf cat output output.pdf



Have a nice reading!


2018 Xaratustrah

"""

from bs4 import BeautifulSoup
import subprocess
import sys

# file = 'asd21.svg'
# use xml parser, not lxml


def main(filename):
    soup = BeautifulSoup(open(filename), 'xml')
    lst = []

    # find the id of the elements to be deleted

    def has_xlink(tag):
        return tag.has_attr('xlink:href')
    for tag in soup.findAll(has_xlink):
        if 'image' not in tag['xlink:href']:
            lst.append(tag['xlink:href'].strip('#'))
            tag.decompose()
    for tag in soup.findAll('image'):  # , {"height": "41"}):
        if 'jpeg' in tag['xlink:href']:
            lst.append(tag['id'])
            tag.decompose()

    def has_id(tag):
        return tag.has_attr('id') and any(x in tag['id'] for x in lst)
    for tag in soup.findAll(has_id):
        tag.decompose()

    # the ones with opaque watermark
    def has_opacity(tag):
        return tag.has_attr('style') and 'opacity:0.' in tag['style']
    for tag in soup.findAll(has_opacity):
        tag.decompose()

    # Writing back to file
    with open("{}.svg".format(filename), "w") as file:
        file.write(soup.prettify())

    subprocess.call(['svg2pdf', "{}.svg".format(
        filename), '{}.pdf'.format(filename)])

    subprocess.call(['rm', '-rf', filename, "{}.svg".format(
        filename)])


if __name__ == '__main__':
    script, filenames = sys.argv[0], sys.argv[1:]
    for filename in filenames:
        main(filename)


"""
# old code
# pipe SVG file into this script:
# cat input.svg | ./svgcleaner.py > output.svg

import sys

data = sys.stdin.readlines()

for line in data:
    if '<use' in line:
        if 'gly' in line or 'matrix(0.9' in line:
            continue
    print(line)
"""
