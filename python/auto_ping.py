#!/usr/bin/env python3
"""
Auto ping.

Nov 2016 - xaratustrah

"""

import sys, datetime, time, subprocess, random

SLEEP_TiME = 5

site_list = ['8.8.8.8',
             '213.46.237.24',
             '140.181.3.31',
             '178.236.7.219',
             '66.211.181.235',
             '172.217.16.163',
             '62.153.159.92',
             ]


def main(filename):
    try:
        while True:
            current_time = datetime.datetime.now().strftime('%Y-%m-%d@%H:%M:%S.%f')
            site = site_list[random.randrange(len(site_list))]
            with open(filename, 'a') as f:
                res = subprocess.call(['ping', '-c', '1', '-W', '100', '-n', site])
                strr = '{} {} {}\n'.format(res, current_time, site)
                f.write(strr)
                print(strr)
            time.sleep(SLEEP_TiME)
    except(EOFError, KeyboardInterrupt):
        print('\nUser input cancelled. Aborting...')


# ------------------

if __name__ == '__main__':
    if len(sys.argv) != 2:
        print('Please enter filename and sleep time.')
    main(sys.argv[1])
