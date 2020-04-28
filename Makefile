# basic makefile
all: jvav
.PHONY: all jvav
CLEAN_FILES = jvav
REQUIRED_CPP = $(wildcard cpr/cpr/*.cpp) Jvav.cpp
OPTIONS = -O2 -Wall -Icpr/include
# special, see some SO answer for ref
ENDING_OPTIONS = -lcurl
jvav:
	$(CXX) $(OPTIONS) -o $@ $(REQUIRED_CPP) $(ENDING_OPTIONS)
clean:
	rm $(CLEAN_FILES)