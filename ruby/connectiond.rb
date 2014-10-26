# This daemon checks the internet connection
# you can start/stop/restart it or use run to test it

require 'daemons'
PATH="/path/to/logfile/"
SLEEPTIME = 5
sites=["8.8.8.8","8.8.4.4", "yahoo.de", "spiegel.de", "faz.de", "wikipedia.org", "sf.net", "bbc.co.uk", "mit.edu", "youtube.com", "adobe.com", "linkedin.com", "amazon.de", "google.de"]

Daemons.run_proc('connectiond.rb') do
  loop do
    sleep SLEEPTIME
    next if system("ping -c 1 #{sites.sample}")
    t1 = Time.now
    until system("ping -c 1 #{sites.sample}") do
      sleep 1
      t2 = Time.now
    end
    delta = t2 - t1
    str = t2.strftime("%Y-%d-%m %H:%M").to_s
    file = File.open("#{PATH}connectiond.log", "a")
    file.write(str + ", " + delta.to_s + " sec\n")
    file.close unless file == nil
  end
end
