# basic makefile
all: jvav
.PHONY: all jvav
CLEAN_FILES = jvav
REQUIRED_CPP = $(wildcard cpr/cpr/*.cpp) Jvav.cpp

#choices: -O3 -Ofast -Os
OPTIONS = -Os -flto -Icpr/include
# -O3 stuff with size-expander removed, only use if you're using -Os
# -fversion-loops-for-strides is unavaliable
OPTIONS += -fgcse-after-reload -floop-interchange -floop-unroll-and-jam -fpeel-loops -fpredictive-commoning -fsplit-loops -fsplit-paths -ftree-loop-distribution -ftree-loop-vectorize -ftree-partial-pre -ftree-slp-vectorize -funswitch-loops -fvect-cost-model -fvect-cost-model=dynamic
#OPTIONS += -ffast-math

# special, see some SO answer for ref
ENDING_OPTIONS = -lcurl
jvav:
	$(CXX) $(OPTIONS) -o $@ $(REQUIRED_CPP) $(ENDING_OPTIONS)
PREFIX = /usr
install: jvav
	# coreutils required
	install -m755 jvav "$(PREFIX)/bin"
clean:
	rm -f $(CLEAN_FILES)