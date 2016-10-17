#!/usr/bin/env python
"""
CGI Plot example with bokeh

Xaratustrah
2016

"""

import numpy as np
from bokeh.plotting import figure
from bokeh.embed import file_html
from bokeh.resources import CDN

# prepare some data
x = np.arange(100)
y0 = np.random.randint(1, high=1024, size=100)
y1 = np.random.randint(1, high=1024, size=100)
y2 = np.random.randint(1, high=1024, size=100)

# create a new plot
p1 = figure(
    tools="pan,box_zoom,reset,save",
    y_axis_type="log", y_range=[0.001, 10 ** 11], title="Log axis",
    x_axis_label='Frequency [Hz]', y_axis_label='Power [a.u.]'
)

# add some renderers
p1.line(x, x, legend="y=x")
p1.circle(x, x, legend="y=x", fill_color="white", size=8)
p1.line(x, y0, legend="y=x^2", line_width=3)
p1.line(x, y1, legend="y=10^x", line_color="red")
p1.circle(x, y1, legend="y=10^x", fill_color="red", line_color="red", size=6)
p1.line(x, y2, legend="y=10^x^2", line_color="orange", line_dash="4 4")

# show the results
# show(p)

html = file_html(p1, CDN, "Test plot")
print(html)

# script, div = components(p1)
# print(script)
# print(div)
