#!/usr/bin/ruby

if ARGV.size > 1 or ARGV.size == 0
  puts 'Please specify only/at least one file.'
else
  begin
    file = File.new(ARGV[0], "r")
    out=''
    while (line = file.gets)
      if  line =~ /^SUMMARY/
		blah, date=line.split(':')
		print "SUMMARY:"
		date.each_char do |item|
		
			case item
				when item='/'
				print ","
				when item='1'
				print '۱'
				when item='2'
				print '۲'
				when item='3'
				print '۳'
				when item='4'
				print '۴'
				when item='5'
				print '۵'
				when item='6'
				print '۶'
				when item='7'
				print '۷'
				when item='8'
				print '۸'
				when item='9'
				print '۹'
				when item='0'
				print '۰'
			end
		end
		print "\r\n"		
      else
        puts "#{line}"
      end
    end
    file.close
  rescue Exception => err
    puts "#{err}"
  end
end
