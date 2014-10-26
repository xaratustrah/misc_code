#!/opt/local/bin/octave -q

if (length(argv()) == 4)
framelength = str2num(argv(){1})
nframes = str2num(argv(){2})
iqt_filename = argv(){3}
basename = argv(){4}

else
disp "\nPlease provide:\n		framelength nframes iqt_filename basename"
endif
