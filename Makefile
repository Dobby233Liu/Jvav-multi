# basic makefile
all: jvav
.PHONY: all jvav
CLEAN_FILES = jvav
REQUIRED_CPP = Jvav.cpp
OPTIONS = -O2 -Wall
jvav:
	$(CXX) $(OPTIONS) -o $@ $(REQUIRED_CPP)
clean:
	rm $(CLEAN_FILES)