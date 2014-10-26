# RLC calculator
require 'facets'

begin
  raise 'Please specify a frequency in Hz and number of suggestions.' if not ARGV.size == 2
  freq = ARGV[0].to_f
  num = ARGV[1].to_i

  range = [1.0, 4.7]
  expo = [1.0e-12, 1.0e-9, 1.0e-6, 1.0e-3]

  vals = final = Array.new

  expo.each{|mult| vals += range.ewise * mult}

  vals.permutation(2).each do |x,y|
    resline = Array.new
    resline << 1.0/2.0/Math::PI/Math::sqrt(x * y) <<  x << y
    final << resline
  end

  final.sort_by{|item| (freq - item[0]).abs}.first(num).each{|item| puts "f0=#{item[0]} with L=#{item[1]} H and C=#{item[2]} F\n"}

rescue Exception => err
  puts "#{err}"
end
