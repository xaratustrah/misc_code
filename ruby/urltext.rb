#!/usr/bin/ruby

require 'uri'
	
if ARGV.size > 1 or ARGV.size == 0
  puts 'Please specify only/at least one file.'
else
  begin
    file = File.new(ARGV[0], "r")
    while (line = file.gets)
		myurl=URI.extract(line) 
		puts myurl		
    end
    file.close
  rescue Exception => err
    puts "#{err}"
  end
end
