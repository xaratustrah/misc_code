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
    invalid_tags = ['font', 'script']
    soup = BeautifulSoup(open(file), 'lxml')

    for tag in invalid_tags:
        for match in soup.findAll(tag):
            match.replaceWithChildren()
    for tag in soup():
        for attribute in ["bgcolor", "align", "href", "style"]:
            del tag[attribute]
    table = soup.find_all('table')
    title = table[0].get_text()
    title = title.replace('Kategorie  AthletVerein', '')
    title = title.replace('für', '').strip()
    print('<h4>{}</h4>'.format(title))
    print(table[1])
