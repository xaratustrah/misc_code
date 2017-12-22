#!/usr/bin/env python
# -*- coding: utf-8 -*-

"""
Test plot without display

2017 Xaratustrah

"""

import string
import random
# change the display that does not need a display, based on https://stackoverflow.com/a/15713545/5177935
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt

# make a random filename, based on https://stackoverflow.com/a/2257449/5177935
filename = ''.join(random.SystemRandom().choice(
    string.ascii_uppercase + string.digits) for _ in range(6)) + '.png'


plt.plot(1, 'ro')
plt.grid()
plt.savefig(filename)
