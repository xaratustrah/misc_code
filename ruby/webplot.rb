#!/usr/bin/ruby
# web based gnuplot plotter
# gets requists from http server
# plots the results in a file and displays in a html
#
#
#--------------------------------------------------------------

require 'cgi'

# Create a cgi object, with HTML 4 generation methods.

cgi = CGI.new('html4')
h=cgi.params
exp=h['exp'].to_s

if h['grid'].to_s=='on'
  grid="set grid;"
  grid_on_flag=true
  grid_off_flag=false
else
  grid=""
  grid_off_flag=true
  grid_on_flag = false
end

if exp.empty?
  system("cp blank.png plot.png")
  system("chmod 644 plot.png")
else
  system("echo \"set term png;set output 'plot.png';#{grid}plot #{exp}\" | gnuplot")
  system("chmod 644 plot.png")
end

# CGI output to the browser

cgi.out{
  cgi.html{
    cgi.head{ "\n"+cgi.title{"Web GNUPLOTter"} + "<link rel=\"stylesheet\"
type=\"text/css\" href=\"./webplot.css\">"} +
    cgi.body{ "\n"+
      cgi.form{"\n"+
        cgi.hr +
        cgi.h1 { "Web based GNUPLOTter"} + 
        "Expression:" + cgi.text_field("exp","#{exp}") +
        cgi.br + cgi.br +
        "Grid " +
        cgi.radio_button("grid","on",grid_on_flag)+ "On" +
        cgi.radio_button("grid","off",grid_off_flag)+ "Off" + 
        cgi.br + cgi.br +
        cgi.submit +
        cgi.hr+
        "<p><img src=\"plot.png\" alt=\"Expression Plot\" title=\"Plot of #{exp}\" longdesc=\"Plot of #{exp}\" /></p>"
      }
    }
  }
}
