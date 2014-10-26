#!/usr/bin/ruby

require 'rubygems'
require 'exifr'

input_file = ARGV[0]

jpg=EXIFR::JPEG.new(input_file)

raise 'exif data not available' if not jpg.exif?

weakday, month, day, time ,gmt , year = jpg.date_time
width=jpg.width
height=jpg.height
puts width.to_s
puts height.to_s
