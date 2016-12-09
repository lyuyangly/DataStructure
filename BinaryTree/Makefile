#*
#***********************************************************************************************
#	Makefile
#
#	Author    	: Lyu Yang
#	Description : Makefile for GNU/GCC
#
#***********************************************************************************************
#*

# Project Name
PROJECT = BinarySearchTree

# Architecture and Platform
ARCH = x86
PLATFORM = Debug
CROSS = 

# Include Dirs and Library Dirs
INCLUDE_DIRS = -I ./
LIBRARY_DIRS = -L ./

# GCC Parameters
CC = $(CROSS)g++
CFLAGS = -c $(INCLUDE_DIRS) -g

CXX = $(CROSS)g++
CXXFLAGS = -c $(INCLUDE_DIRS) -g

AS = $(CROSS)g++
ASFLAGS =  -x assembler-with-cpp

LD = $(CROSS)g++
LDFLAGS = $(LIBRARY_DIRS)

OBJCP = $(CROSS)objcopy
OBJCPFLAGS = -O binary -S -R .note -R .commen

AR = $(CROSS)ar
ARFLAGS = cr

DUMP = $(CROSS)objdump
DUMPFLAG = -d

SIZE = $(CROSS)size

# Source Files
# SRCS := $(wildcard ./*.cpp)

# Build Objects
# OBJS = $(SRCS:.cpp=.o)
# OBJB = $(patsubst %.cpp, $(PLATFORM)/$(ARCH)/%.o, $(notdir ${SRCS}))
OBJS = main.o

# Make ALL
.PHONY: all clean debug run core
all: $(PROJECT)

$(PROJECT): $(OBJS)
	@$(LD) $(LDFLAGS) $^ -o $@
	@echo "$(CXX) $(notdir $^) -o $(notdir $@)"

%.o: %.cpp
	@$(CXX) $(CFLAGS) $^ -o $(notdir $@)
	@echo "$(CXX) $(notdir $^) -o $(notdir $@)"

clean:
	@rm $(OBJS) $(PROJECT) 2>/dev/null

run:
	@$(PROJECT)

debug:
	@$(CROSS)gdb ./$(PROJECT)

core:
	@$(CROSS)gdb ./$(PROJECT) ./core

