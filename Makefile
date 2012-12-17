# Basic makefile to compile the Cymbiote MUD server in Linux

# Include warnings
CPPFLAGS += -Wall -g -fPIC
LIBS = -lboost_system -lboost_thread

# Files to compile
SOURCES = $(wildcard *.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

.PHONY: all clean

all: cymbiote-server

cymbiote-server: $(OBJECTS)
	$(LINK.cc) $(OBJECTS) $(LIBS) -o cymbiote-server

clean:
	@- $(RM) cymbiote-server
	@- $(RM) $(OBJECTS)
	
