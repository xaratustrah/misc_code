#!/usr/bin/ruby
# This script is a converter between dBm and mW power levels.
#

begin 
        raise 'Please specify value and its unit: dBm or mW.' if not ARGV.size == 2
        val=ARGV[0].to_f
        unit=ARGV[1].to_s
        if unit =~ /[dD][bB][mM]/ then 
                result = 10**(val/10)
                old_unit = 'dBm'
                new_unit = 'mW'
        elsif
                unit =~ /[mM][wW]/ then 
                result = 10*Math.log10(val)
                old_unit = 'mW'
                new_unit = 'dBm'
        else
                raise 'Please specify valid units: dBm or mW'
        end
        puts val.to_s + " " + old_unit + " is equal to " + result.to_s + " " + new_unit
rescue Exception => err
        puts "#{err}"
end
