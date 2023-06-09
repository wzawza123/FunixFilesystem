# this is the build file for project 
# it is autogenerated by the xmake build system.
# do not edit by hand.

CXX=/usr/bin/gcc
AS=/usr/bin/gcc
CC=/usr/bin/gcc
MXX=/usr/bin/gcc
MM=/usr/bin/gcc

SH=/usr/bin/g++
AR=/usr/bin/ar
LD=/usr/bin/g++

funix_CXXFLAGS=-m64 -Iinclude
funix_CXXFLAGS=-m64 -Iinclude
funix_LDFLAGS=-m64

default:  funix

all:  funix

.PHONY: default all  funix

funix: build/linux/x86_64/release/funix
build/linux/x86_64/release/funix: build/.objs/funix/linux/x86_64/release/src/dev/DeviceManager.cpp.o build/.objs/funix/linux/x86_64/release/src/dev/ATADriver.cpp.o build/.objs/funix/linux/x86_64/release/src/main.cpp.o
	@echo linking.release funix
	@mkdir -p build/linux/x86_64/release
	@$(LD) -o build/linux/x86_64/release/funix build/.objs/funix/linux/x86_64/release/src/dev/DeviceManager.cpp.o build/.objs/funix/linux/x86_64/release/src/dev/ATADriver.cpp.o build/.objs/funix/linux/x86_64/release/src/main.cpp.o $(funix_LDFLAGS) > build/.build.log 2>&1

build/.objs/funix/linux/x86_64/release/src/dev/DeviceManager.cpp.o: src/dev/DeviceManager.cpp
	@echo compiling.release src/dev/DeviceManager.cpp
	@mkdir -p build/.objs/funix/linux/x86_64/release/src/dev
	@$(CXX) -c $(funix_CXXFLAGS) -o build/.objs/funix/linux/x86_64/release/src/dev/DeviceManager.cpp.o src/dev/DeviceManager.cpp > build/.build.log 2>&1

build/.objs/funix/linux/x86_64/release/src/dev/ATADriver.cpp.o: src/dev/ATADriver.cpp
	@echo compiling.release src/dev/ATADriver.cpp
	@mkdir -p build/.objs/funix/linux/x86_64/release/src/dev
	@$(CXX) -c $(funix_CXXFLAGS) -o build/.objs/funix/linux/x86_64/release/src/dev/ATADriver.cpp.o src/dev/ATADriver.cpp > build/.build.log 2>&1

build/.objs/funix/linux/x86_64/release/src/main.cpp.o: src/main.cpp
	@echo compiling.release src/main.cpp
	@mkdir -p build/.objs/funix/linux/x86_64/release/src
	@$(CXX) -c $(funix_CXXFLAGS) -o build/.objs/funix/linux/x86_64/release/src/main.cpp.o src/main.cpp > build/.build.log 2>&1

clean:  clean_funix

clean_funix: 
	@rm -rf build/linux/x86_64/release/funix
	@rm -rf build/linux/x86_64/release/funix.sym
	@rm -rf build/.objs/funix/linux/x86_64/release/src/dev/DeviceManager.cpp.o
	@rm -rf build/.objs/funix/linux/x86_64/release/src/dev/ATADriver.cpp.o
	@rm -rf build/.objs/funix/linux/x86_64/release/src/main.cpp.o

