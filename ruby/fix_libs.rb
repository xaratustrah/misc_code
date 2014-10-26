# Fix dependencies

begin
  output = IO.popen('echo $LD_LIBRARY_PATH')
ldlibpath = output.readlines
  raise 'Please run the thisroot.sh script in the root directory.' if ldlibpath[1] == "\n"
  libpath = ldlibpath[0].gsub("\n","") 
 puts "#{libpath}"
 raise 'Please specify the makefile target.' if not ARGV.size == 1
  target=ARGV[0].to_s
  app = "application"
  libs = ["Core", "Cint", "RIO", "Net", "Hist", "Graf", "Graf3d", "Gpad", "Tree", "Rint", "Postscript", "Matrix", "Physics", "MathCore", "Thread", "Gui", "Spectrum"]
  libs.sort!
  libs.each do |name|
    system("cp #{libpath}/lib#{name}.so #{app}.app/Contents/libs/")
    system("install_name_tool -id '@executable_path/../libs/lib#{name}.so' #{app}.app/Contents/libs/lib#{name}.so")
    system("install_name_tool -change '@rpath/lib#{name}.so' '@executable_path/../libs/lib#{name}.so' #{app}.app/Contents/MacOS/#{app}")
  end

  libs.permutation(2).each do |first, second|
    system("install_name_tool -change '@rpath/lib#{first}.so' '@executable_path/../libs/lib#{first}.so' #{app}.app/Contents/libs/lib#{second}.so")
  end
rescue Exception => err
  puts "#{err}"
end

