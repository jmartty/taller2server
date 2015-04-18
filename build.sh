#!/bin/bash

# compilamos rocksdb si no esta presente
if [ ! -f libs/rocksdb/librocksdb.a ]; then
	echo "Compilando rocksdb..."
	# compilamos rocksdb como libreria estatica
	cd libs/rocksdb
	PORTABLE=1 make static_lib
	# volvemos al dir base
	cd ../..
fi

# clean o build
if [ "$1" == "clean" ]; then
	rm -r bin
else
	mkdir -p bin
	cd bin
	pwd
	cmake ..
	make
fi
