#!/usr/bin/env python
# -*- coding: utf-8 -*-

'''
Lunar month Calculator
Finds which months in the lunar calender start and end with a Friday.

2017 Xaratustrah

'''

import numpy as np
import jdcal

# begin= 1948439.5 -1 # Friday 19 Jul 622 Julian
begin = sum(jdcal.gcal2jd(622, 7, 19)) - 1

# first day of lunar month
month_start = 4 * (30 + 29) + 1

# calculate over how many years
total_days = 1500 * 355

year_cnt = 1
friday = True
dayofyear = 0
for ii in range(1, total_days):

    dayofyear += 1

    jd = begin + ii
    # convert MJD
    gdate = jdcal.jd2gcal(2400000.5, -(2400000.5 - jd))

    if ii % 7 == 1:
        friday = True
    else:
        friday = False

    if year_cnt % 30 in [1, 5, 7, 10, 13, 16, 18, 21, 24, 26, 29]:
        if dayofyear == 356:
            year_cnt += 1
            dayofyear = 1
    else:
        if dayofyear == 355:
            year_cnt += 1
            dayofyear = 1

    if friday and dayofyear == month_start:

        if 2100 > gdate[0] > 2016:
            # print(jd, ii, dayofyear, year_cnt, friday,
            #      '-'.join(map(str, gdate[0:3])))
            print('-'.join(map(str, gdate[0:3])))
