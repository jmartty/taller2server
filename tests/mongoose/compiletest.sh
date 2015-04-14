#!/bin/bash

g++ -W -Wall -I../../libs/mongoose -pthread -o compiletest.app compiletest.cpp ../../libs/mongoose/mongoose.c
