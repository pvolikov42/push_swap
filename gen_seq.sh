#!/bin/bash
#
LEN=20
[ "x$1" != "x" ] && LEN=$1
for i in `seq 1 $LEN`
do 
	S="$S $((RANDOM / 100))"
done
echo $S
