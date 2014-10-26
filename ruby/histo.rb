#!/usr/bin/ruby
# This code makes a histogram from exoerimental or simulation data
#

Fixnum.class_eval do
  def even?
    self%2 == 0
  end
end

begin
  raise "Histogram Usage:\n         ./histogram.rb filename chmin chmax nbins delta_t\n\ 
  	Example: ./histogram.rb experiment.data 125 2000 125 0.032 > plot.data" if not ARGV.size == 5
  chmin = ARGV[1].to_i
  chmax = ARGV[2].to_i
  nbins = ARGV[3].to_i
  binw = (chmax- chmin)/nbins
  delta_t = ARGV[4].to_f
  
  input_file = File.new(ARGV[0], "r")
  y = Array.new
  
  while line = input_file.gets
    next if line.empty? or line =~/\#(.*)/     
      y << line.to_f if line.to_f > chmin and line.to_f < chmax
  end
  input_file.close
  y.sort!
  
  occurances = Array.new
  bincenters = Array.new
  times = Array.new
  errors = Array.new

  count = 0
  j = 1
  for i in 0..y.size-1
    if y.at(i) < chmin + j * binw
      count +=1
    else
      occurances << count
      errors << Math.sqrt(count)
      count = 1 # at list this point was there.
      tmpval = ((chmin + j * binw)+(chmin + (j-1) * binw))/2
      bincenters << tmpval
      times << tmpval * delta_t
      j+=1
    end
  end

  print "\#Bin   Time   Occurance   Errors\n"

  for m in 0 .. occurances.size - 1
    print bincenters[m], "   ", times [m],"   ", occurances[m], "   ", errors[m], "\n"
  end

rescue Exception => err
  puts "#{err}"
end
