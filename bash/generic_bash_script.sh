#!/bin/bash
echo $@
echo $1
echo $2

dummy=`find $1 -iname *.$2`
# dummy=`find $@ -iname '*html'`
# for d in *.html; do 
for d in $dummy; do 
echo $d;
echo ${d%*.$2};
# echo ${d#*.$2};

done

