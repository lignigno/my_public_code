#!/bin/bash

# this is beauty_print
# arg 1 - string
# arg 2 - sleep
# arg 3 - color new char
# arg 4 - color text

STR=""
for (( i=0; $i<${#1}; i=$(($i+1)) ))
do
	STR=${STR}${1:$i:1};
	echo -en "$3${1:$i:1}\033[m";
	sleep $2;
	echo -en "\b$4${1:$i:1}\033[m";
done
