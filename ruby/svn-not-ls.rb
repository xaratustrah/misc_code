#!/usr/bin/ruby
# See what files are not in subversion under version control.
# Parameters: none
#

list = Array.new
listsvn = []
input=`ls -A`
input.gsub("\n"," ")
input.split(/\s/).each{|x| list << x.to_s}
begin
raise 'No version control in this directory.'   if not input.include?(".svn\n")
input=`svn ls`
input.gsub!("\n"," ")
input.gsub!("/","")
input.split(/\s/).each{|x| listsvn << x.to_s}
list.each{|x| puts x if not listsvn.include?(x) and not x == ".svn"}
rescue Exception => err
  puts "#{err}"
end
