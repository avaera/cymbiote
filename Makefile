# Basic makefile to compile the Cymbiote MUD server in Linux

# Include warnings
CPPFLAGS += -Wall -g

# Files to compile
SOURCES = $(wildcard *.cpp)
HEADERS = $(SOURCES:.cpp=.hpp)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean

all: cymbiote-server

cymbiote-server: $(OBJECTS)
	$(LINK.cc) $(OBJECTS) -o cymbiote-server

clean:
	@- $(RM) cymbiote-server
	@- $(RM) $(OBJECTS)
	
