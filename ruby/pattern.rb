#!/usr/bin/ruby
# search for lines beginning with ==== EPXR
# and replace them with ===== EPXR =====
# leave other lines untouched


if ARGV.size > 1 or ARGV.size == 0
  puts 'Please specify only file.'
else
  begin
    file = File.new(ARGV[0], "r")
    while (line = file.gets)
      if  line =~ /^={4}\s/
        # nice try with awk here, works only in irb not as code, but better use ruby itself
        # col=`echo #{line} | awk  \'{for (i=2; i<=NF; i++) {printf("%s",$i);if (i != NF) printf(" ")}}\'`
        col=line.gsub!("==== ", "").gsub!("\n","")
        puts "===== #{col} ====="
      else
        puts "#{line}"
      end
    end
    file.close
  rescue Exception => err
    puts "#{err}"
  end
end