SOURCES=$(wildcard *.cc)
OBJECTS=$(SOURCES:.cc=.o)
BINS=$(SOURCES:.cc=)

CXXFLAGS+= -Wall -std=c++11

all: $(BINS)

clean:
	$(RM) $(OBJECTS) $(BINS)

