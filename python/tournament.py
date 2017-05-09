#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Cleanup tournament results in HTML for Wordpress

May 2017

Xaratustrah

"""

import sys
from bs4 import BeautifulSoup

script, filenames = sys.argv[0], sys.argv[1:]

for file in filenames:
    invalid_tags = ['font', 'script', 'a', 'b', 'p']
    soup = BeautifulSoup(open(file), 'lxml')

    for tag in invalid_tags:
        for match in soup.findAll(tag):
            match.replaceWithChildren()  # removes (flattens) the tag
    for tag in soup.findAll():  # --> for tag in soup():
        for attribute in ["bgcolor", "align", "href", "style"]:
            del tag[attribute]
    for tag in soup.findAll('tr'):
        kids = tag.findChildren()
        for kid in kids:
            if 'ausgew' in str(kid.string):
                tag.extract()

    for tag in soup.findAll('td'):
        for blah in ['Frankfurt', 'GER']:
            if blah in str(tag):
                tag.extract()

    for tag in soup.findAll('th'):
        for blah in ['Nation', 'Verein']:
            if blah in str(tag):
                tag.extract()

    table = soup.find_all('table')
    title = table[0].get_text()
    title = title.replace('Kategorie  AthletVerein', '')
    title = title.replace('für', '').strip()
    print('<h4>{}</h4>'.format(title))
    print(table[1])
