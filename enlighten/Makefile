# A line starting with a has is a comment, we'll build up
# the below example

TARGET = enlighten
SRC_FILES = main.cpp

# DO NOT EDIT BELOW HERE
CXX = g++
CXXFLAGS = -Wall -Wextra -Werror -pedantic-errors
CXXFLAGS_DEBUG = -g
OBJECTS = $(SRC_FILES:.cpp=.o)

ifeq ($(shell echo "Windows"), "Windows")
	TARGET := $(TARGET).exe
	DEL = del
else
	DEL = rm -f
endif

debug: CXXFLAGS += -DDEBUG
debug: clean $(TARGET)

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^

.cpp.o:
	$(CXX) $(CXXFLAGS) $(CXXFLAGS_DEBUG) -o $@ -c $<

clean:
	$(DEL) $(TARGET) $(OBJECTS)

.PHONY: all clean depend
