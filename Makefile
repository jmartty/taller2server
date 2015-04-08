CC=g++
CFLAGS=-Wall -pedantic -pedantic-errors -g -ggdb -DDEBUG
LDFLAGS=

MODULES_SOURCES := $(shell find modules/* -name '*.cpp')
MODULES_OBJ=$(MODULES_SOURCES:.cpp=.o)

SERVER_SOURCE=src/server.cpp
SERVER_OBJ=$(SERVER_SOURCE:.cpp=.o)
SERVER_BIN=bin/server.app

all: server

server: $(SERVER_OBJ) $(MODULES_OBJ)
	$(CC) $(MODULES_OBJ) $(SERVER_OBJ) -o $(SERVER_BIN) -Imodules

.cpp.o:
	$(CC) $(CFLAGS) -Imodules -c $< -o $@

clean:
	$(RM) $(SERVER_BIN) $(SERVER_OBJ) $(MODULES_OBJ)
