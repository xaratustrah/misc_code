#!/usr/bin/env python
"""
Downloads videos from Apart extracted from Emails. Save your emails as eml files. then use them either as
command line arguments, or use pipe from stdin.

python aparat.py *.eml
cat *.eml | python aparat.py

Feb 2015

Xaratustrah

"""
import fileinput, re
from bs4 import BeautifulSoup
import urllib.request as ur


def download_file(url, folder, name, download=True):
    if not download:
        print('{}./{}/{}.mp4'.format(url, folder, name))
        return
    g = ur.urlopen(url)
    with open('./{}/{}.mp4'.format(folder, name), 'b+w') as f:
        f.write(g.read())
    return


if __name__ == '__main__':
    cnt = 0
    for line in fileinput.input():
        # regexp from: http://stackoverflow.com/questions/6883049/regex-to-find-urls-in-string-in-python
        urls = re.findall('http[s]?://(?:[a-zA-Z]|[0-9]|[$-_@.&+]|[!*\(\),]|(?:%[0-9a-fA-F][0-9a-fA-F]))+', line)
        if urls:
            print('Downloading from: ' + urls[0])
            page = ur.urlopen(urls[0])
            soup = BeautifulSoup(page)
            for tag in soup.findAll('a', href=True):
                if tag['href'].endswith('.mp4'):
                    file_url = (tag['href'])
                    print('--> movie_{}.mp4'.format(cnt))
                    download_file(file_url, '.', 'movie_{}'.format(cnt), download=False)
                    cnt += 1
