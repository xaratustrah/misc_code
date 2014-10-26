
#import numpy as np

#import pylab as pl


import numpy 

# import numpy as np
 import matplotlib.pyplot as plt


# Use numpy to load the data contained in the file
# "fakedata.txt" into a 2-D array called data
data = loadtxt("fakedata.txt")



# plot the first column as x, and second column as y
pl.plot(data[:,0], data[:,1], "ro")
pl.xlabel("x")
pl.ylabel('y')
pl.show()
