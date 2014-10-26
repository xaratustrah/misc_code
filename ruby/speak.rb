#! /usr/bin/env ruby

require 'osx/cocoa'
include OSX

def speak(str)
    str.gsub!(/"/, '\"')        # Put backslash before quotes
    src = %(say "#{str}")
    # Call Objective-C code
    script = NSAppleScript.alloc.initWithSource(src)
    script.executeAndReturnError(nil)
end

speak "Hi Nicola! Can you do this with see plus plus?"
