#!/usr/bin/ruby
# test ruby-ogg gem

require 'ogg'
packet = ''
open("file.ogg", "rb") do |file|
  dec = Ogg::Decoder.new(file)
  packet = dec.read_packet
  # Do something with the packet...
end
