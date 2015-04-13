#!/bin/bash

g++ -Wall compiletest.cpp -o compiletest.app -L../../libs/rocksdb-master/ -lrocksdb -I../../libs/rocksdb-master/include -std=c++11 -lpthread -lrt -lsnappy -lgflags -lz -lbz2
chmod +x compiletest.app
touch testdb.rocksdb
rm -r testdb.rocksdb
