#!/usr/bin/ruby
#

Fixnum.class_eval do
  def even?
    self%2 == 0
  end
end

begin
  raise "Binner Usage:\n         ./binner.rb filename \nExample: ./binner.rb input.data  > output.data" if not ARGV.size == 1
  
  input_file = File.new(ARGV[0], "r")


# arr.inject{ |sum, el| sum + el }.to_f / arr.size


  y = Array.new
  
  while line = input_file.gets
    next if line.empty? or line =~/\#(.*)/     
    line.each do |x|
      y << x.to_f if x.to_f > chmin and x.to_f < chmax
    end
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
