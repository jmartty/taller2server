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

# compilamos gmock y gtest si no estan presentes (mismo bundle)
if [ ! -f libs/gmock/libgmock.a ]; then
        echo "Compilando gmock-gtest bundle..."
        cd libs/gmock
	cmake .
	make
        # volvemos al dir base
        cd ../..
fi


# clean o build
if [ "$1" == "clean" ]; then
	echo -n "Limpiando build..."
	rm -rf bin
	echo "OK"
else
	echo -n "Build..."
	mkdir -p bin
	cd bin
	pwd
	cmake ..
	make
	if [ "$1" == "run" ] && [ -f server ]; then
		echo "Ejecutando bin/server..."
		echo "----------------------------------------------"
		cd ..
		bin/server
		echo "----------------------------------------------"
	elif [ "$1" == "test" ]; then
		echo "Ejecutando tests..."
		ctest .
	fi
fi
