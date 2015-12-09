#!/usr/bin/env python
# test tcap files
#
# Dec 2015 xaratustrah
#

import struct, sys

if __name__ == '__main__':
    with open(sys.argv[1], 'rb') as f:
        version_ba = f.read(8)
        #    center_freq_ba = np.fromstring(f.read(8), dtype='>f8')[0]
        center_freq = struct.unpack('>d', f.read(8))[0]
        adc_range = struct.unpack('>d', f.read(8))[0]
        data_scale = struct.unpack('>d', f.read(8))[0]
        block_count = struct.unpack('>Q', f.read(8))[0]
        block_size = struct.unpack('>I', f.read(4))[0]
        frame_size = struct.unpack('>I', f.read(4))[0]
        decimation = struct.unpack('>H', f.read(2))[0]
        config_flags = struct.unpack('>H', f.read(2))[0]
        f.seek(448, 1) # skip this section!
        trigger_time = f.read(12)

    print(block_count)
