#!/bin/bash

while :
do
	cat /proc/meminfo | grep MemFree
	sleep 1
done
