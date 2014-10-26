#!/usr/bin/env python
#from pylab import *
import matplotlib.pyplot as plt
import numpy as np
import numpy.random as rnd

dt = 0.0005                             # The sampling time
t = np.arange(0.0, 20.0, dt)               # The time vector
s1 = np.sin(2 * np.pi * 100 * t)                    # signal
s2 = 2 * np.sin(2 * np.pi * 100 * t + 0.01)                  # signal

# create a transient "chirp"
mask = np.where(np.logical_and(t>10, t<12), 1.0, 0.0)
s2 = s2 * mask

# add some noise into the mix
nse = 0.01 * rnd.randn(len(t))

x = s1 + s2 + nse # the signal
NFFT = 1024       # the length of the windowing segments
Fs = int(1.0/dt)  # the sampling frequency

# Pxx is the segments x freqs array of instantaneous power, freqs is
# the frequency vector, bins are the centers of the time bins in which
# the power is computed, and im is the matplotlib.image.AxesImage
# instance

fig1 = plt.figure()
ax1 = plt.subplot(211)
plt.plot(t, x)
plt.subplot(212, sharex=ax1)
Pxx, freqs, bins, im = plt.specgram(x, NFFT=NFFT, Fs=Fs, noverlap=900,
                                cmap=plt.cm.gist_heat)

fig2 = plt.figure()

xcor = np.correlate(s1, s2)
plt.plot(t, s1)

plt.show()
