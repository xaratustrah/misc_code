#!/usr/bin/env python
"""
Android Barcode Scanner --> Zotero Library

You can use Barcode Scanner App for Android: https://en.wikipedia.org/wiki/Barcode_Scanner_(application)
Set to bulk mode. Activate the duplicate detection mode and start scanning all your book. Then send the list to your
desktop (e.g. via email etc...). The attachment of this email can be fed into this small code, it will open all books
in a separate browser tab.

Now you can use the Zotero bottom on every tab, then you are done!


2016 Xaratustrah

"""

import csv, webbrowser, sys


def fetch(file_name):
    print(file_name)
    with open(file_name, 'r') as f:
        rd = csv.reader(f, delimiter=',', quotechar='"')
        for row in rd:
            url = 'https://www.worldcat.org/search?q={0}&qt=owc_search'.format(row[0])
            print('Opening {} ...'.format(url))
            webbrowser.open_new_tab(url)


def main():
    fetch(sys.argv[1])


# ----------------------------

if __name__ == '__main__':
    main()
