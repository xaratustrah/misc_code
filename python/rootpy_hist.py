#!/usr/bin/env python
"""
Example plotting with rootpy

type:
source `which thisroot.sh`

before running this code.


"""

import rootpy.plotting as rpplt
from rootpy.interactive import wait
import random
import numpy as np

# create a simple 1D histogram with 10 constant-width bins between 0 and 1

h = rpplt.Hist(10, 0, 1, name='my hist', title='Some Data',
               drawstyle='hist',
               legendstyle='F',
               fillstyle='/')

# fill the histogram
for i in range(1000):
    # all ROOT CamelCase methods are aliased by equivalent snake_case methods
    # so you can call fill() instead of Fill()
    # h.Fill(random.gauss(4, 3))
    h.Fill(np.random.random())

# easily set visual attributes
h.linecolor = 'blue'
h.fillcolor = 'green'
h.fillstyle = '/'

# attributes may be accessed in the same way
print(h.name)
print(h.title)
print(h.markersize)

# plot
c = rpplt.Canvas(width=700, height=500)
c.SetLeftMargin(0.15)
c.SetBottomMargin(0.15)
c.SetTopMargin(0.10)
c.SetRightMargin(0.05)
c.ToggleEditor()
# c.SetCrosshair()
c.ToggleEventStatus()
c.ToggleToolBar()

h.Draw()

# create the legend
legend = rpplt.Legend([h], pad=c,
                      header='Header',
                      leftmargin=0.05,
                      rightmargin=0.5)
legend.Draw()

# wait for you to close all open canvaces before exiting
# wait() will have no effect if ROOT is in batch mode:
# ROOT.gROOT.SetBatch(True)
wait()
