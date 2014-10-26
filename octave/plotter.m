fh=fopen('adc_adt.txt', 'rt');
for i = 1: 4000
sp= hex2num(fscanf (fh, '%s', [1 i]))
end
fclose(fh);
