#******************************************************************************
# Copyright (C) 2017 by Alex Fosdick - University of Colorado
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are 
# permitted to modify this and use it to learn about the field of embedded
# software. Alex Fosdick and the University of Colorado are not liable for any
# misuse of this material. 
#
#*****************************************************************************

#------------------------------------------------------------------------------
# Simple make file to support two build platforms
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.o - Builds a <FILE>.o object file
#      <FILE>.i - Builds a <FILE>.i preprocessed file
#      <FILE>.asm - Dumps <FILE>.asm assembly file
#      <FILE>.d - Builds <FILE>.d dependency file
#      compile-all - Compiles all source files in project
#      build - Builds all object files in project (links as well)
#      clean - Removes all generated files
#
# Platform Overrides:
#      HOST - Default platform
#      MSP342 - Target cross-compiled platform
#
# Author: Mohab Alaa Gouda
# Date:   22/3/2020
#
#------------------------------------------------------------------------------
include sources.mk

# Platform Overrides.
PLATFORM ?= HOST
TEST = NO

# General flags for both platforms.
G_FLAGS = -std=c99 \
	  -g \
	  -O0 \
	  -Wall \
	  -Werror

# Architectures Specific Flags for MSP432.
LINKER_FILE = -T msp432p401r.lds
CPU = cortex-m4
ARCH = armv7e-m
SPECS = nosys.specs
EXTRA = -mthumb \
	-mfloat-abi=hard \
	-mfpu=fpv4-sp-d16


TARGET = course1


# Conditional If for select between Platforms (HOST & MSP432).
# When Platform selected, Specific Flags will be added.
ifeq ($(PLATFORM), MSP432)
	# Compiler Flags & Defines
        CC = arm-none-eabi-gcc
        LD = arm-none-eabi-ld
        CFLAGS = $(G_FLAGS) \
		 -mcpu=$(CPU) \
		 -march=$(ARCH) \
		 --specs=$(SPECS) \
		 $(EXTRA)
        CPPFLAGS = -DMSP432 $(INCLUDES)
        LDFLAGS = -Wl,-Map=$(TARGET).map \
		  -L ../ $(LINKER_FILE)
        OBJDUMP = arm-none-eabi-objdump
        SIZE = arm-none-eabi-size 

else ifeq ($(PLATFORM), HOST)
	# Compiler Flags & Defines
        CC = gcc
        LD = ld
        CFLAGS = $(G_FLAGS)
        CPPFLAGS = -DHOST $(INCLUDES)
        LDFLAGS = -Wl,-Map=$(TARGET).map
        OBJDUMP = objdump
        SIZE = size

# If the client enter a Platform rather than (HOST or MSP432)
# Error Message will appear and the Program will Stop
else 
$(error Not defined Platform, Please select from Platforms (HOST & MSP432))

endif

# Enable Test Flag
ifeq ($(TEST), YES)
	TESTFLAGS = -D COURSE1 -D VERBOSE
else
	TESTFLAGS = -D COURSE1
endif

# Building Object file (file.o)
# Building Dependency file (file.d)
# Building Assembly file (file.asm)
# Building Preprocessed file (file.i)
OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PREP = $(SOURCES:.c=.i)

%.o : %.c
	$(CC) -c $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@

%.asm: %.c
	$(CC) -S $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@

%.i: %.c
	$(CC) -E $< $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@




.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(TARGET).out

$(TARGET).out: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(TESTFLAGS) -o $@
	$(SIZE) $@

.PHONY: all_files

all_files: $(SOURCES)
	make $(PREP)
	make $(ASMS)
	make compile-all
	make $(TARGET).out
	$(OBJDUMP) -t $(TARGET).out > $(TARGET).symbol_table

.PHONY: clean
clean:
	rm -f *.o *.i *.asm  $(TARGET).out*  $(TARGET).map
