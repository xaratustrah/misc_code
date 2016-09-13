#!/usr/bin/env python
# Rest gas monitor data exporter
#
# 2016 Xaratustrah
#

import matplotlib.pyplot as plt
import numpy as np
import xml.etree.ElementTree as et
from io import BytesIO

filename = 'ipmData-20160711_145902_Ver.xml'

with open(filename, 'rb') as f:
    ba = f.read()
str = '<xml>' + ba.decode("utf-8") + '</xml>'
str = str.replace('ProfileReadoutTime_yyyyMMdd_hhmmss_zzz', 'ProfileReadoutStartTime')
xml_tree_root = et.fromstring(str)

i = 0
for elem in xml_tree_root.iter(tag='ProfileData'):
    b = np.genfromtxt(BytesIO(elem.text.encode()), delimiter=";", autostrip=True)
    # here comes the actual calculation
    break

plt.plot(b, 'g')
plt.xlabel('Pixel')
plt.ylabel('Photon Intensity [a.u.]')
plt.title('Rest gas monitor plot')
plt.grid(True)
plt.savefig('{}.pdf'.format(filename))
