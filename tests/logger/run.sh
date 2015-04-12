#!/bin/bash

g++ ../../modules/logger.cpp loggertest.cpp -o loggertest.app
./loggertest.app
cat event.log
rm event.log
