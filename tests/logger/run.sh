#!/bin/bash

g++ -I../../modules ../../modules/logger.cpp loggertest.cpp -o loggertest.app
./loggertest.app
cat event.log
rm event.log
#rm loggertest.app
