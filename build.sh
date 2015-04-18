#!/bin/bash
if [ "$1" == "clean" ]; then
	rm -r bin
else
	mkdir -p bin
	cd bin
	pwd
	cmake ..
	make
fi
