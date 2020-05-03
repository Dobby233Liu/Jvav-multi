# basic makefile
all: jvav
.PHONY: all jvav
CLEAN_FILES = jvav
REQUIRED_CPP = $(wildcard cpr/cpr/*.cpp) Jvav.cpp

# choices: -O3 -Ofast -Os
# and added -O3 stuff with size-expander removed, only use if you're using -Os
# -fversion-loops-for-strides is unavaliable
OPTIONS ?= -Os -Icpr/include -fgcse-after-reload -floop-interchange -floop-unroll-and-jam -fpeel-loops -fpredictive-commoning -fsplit-loops -fsplit-paths -ftree-loop-distribution -ftree-loop-vectorize -ftree-partial-pre -ftree-slp-vectorize -funswitch-loops -fvect-cost-model -fvect-cost-model=dynamic
#OPTIONS += -ffast-math

# special, see some SO answer for ref
ENDING_OPTIONS ?= -lcurl
ifeq ($(GHA_RUNNER_WINDOWS),y)
#ENDING_OPTIONS += -Icpr/opt/curl/include
#ENDING_OPTIONS += -llibcurl
else
#OPTIONS += -flto
endif

jvav:
	$(CXX) $(OPTIONS) -o $@ $(REQUIRED_CPP) $(ENDING_OPTIONS)
PREFIX = /usr
install: all
	# coreutils required
	install -m755 jvav "$(PREFIX)/bin"
check:
	$(error This target is currently a stub.)
clean:
	rm -f $(CLEAN_FILES)
help:
	$(info [make] help - show all commands)
	$(info [make] all - build all targets)
	$(info [make] <binary name> - build a binary)
	$(info [make] install - install all buildable binaries (will run all))
	$(info [make] check - a stub for future check commands)
	$(info [make] clean - cleanup workspace)
	@exit