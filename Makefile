# ------------------------------------------------
# Generic Makefile
#
# Author: yanick.rochon@gmail.com
# Date  : 2011-08-10
#
# Changelog :
#   2010-11-05 - first version
#   2011-08-10 - added structure : sources, objects, binaries
#				thanks to http://stackoverflow.com/users/128940/beta
#   2017-04-24 - changed order of linker params
# ------------------------------------------------

# project name (generate executable with this name)
TARGET   		= Expanse

CC	  	 		= gcc
# compiling flags here
CFLAGS   		= -std=c++11 -Wall -I. `pkg-config gtkmm-3.0 --cflags`

LINKER   		= g++
# linking flags here
LFLAGS   		= -Wall -I. -lm `pkg-config gtkmm-3.0 --libs`

# change these to proper directories where each file should be
SRCDIR  	 	= src
OBJDIR   		= obj
BINDIR   		= bin

INPOUTEXT		= .cpp
OUTPOUTEXT	= .o

SOURCES		 := $(wildcard $(SRCDIR)/*$(INPOUTEXT))
INCLUDES 	 := $(wildcard $(SRCDIR)/*.h)
OBJECTS  	 := $(SOURCES:$(SRCDIR)/%$(INPOUTEXT)=$(OBJDIR)/%$(OUTPOUTEXT))
rm	 		    = rm -f


$(BINDIR)/$(TARGET): $(OBJECTS)
	@$(LINKER) $(OBJECTS) $(LFLAGS) -o $@
	@echo "Linking complete!"

$(OBJECTS): $(OBJDIR)/%$(OUTPOUTEXT) : $(SRCDIR)/%$(INPOUTEXT)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "Compiled "$<" successfully!"

.PHONY: clean
clean:
	@$(rm) $(OBJECTS)
	@echo "Cleanup complete!"

.PHONY: remove
clean_all: clean
	@$(rm) $(BINDIR)/$(TARGET)
	@echo "Executable removed!"
	
lauch:
	@$(BINDIR)/$(TARGET)
	@echo "Executable lauched!"
