#!/bin/bash

g++ -Wall -g -o compiletest.app compiletest.cpp ../../libs/jsoncpp/jsoncpp.cpp -I../../libs/jsoncpp -std=c++11
