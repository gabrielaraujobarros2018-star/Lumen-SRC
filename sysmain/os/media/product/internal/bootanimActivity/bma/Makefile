# Still, idk how to make Makefiles, so i still ask for AI help a bit while still not letting AI control my life, this way, reducing anxiety and modifying the Makefile to suit the program's info & needs.

# ---------------------------------------

# Define the compiler
CC := gcc
# Define the build directory (optional, but it's a good practice)
BUILD_DIR := build

# Use the wildcard function to get a list of all .c source files
SRCS := $(wildcard *.c)

# Use the wildcard function to get a list of all .cpp files
SRCS_CPP := $(wildcard *.cpp)

# Use the wildcard function to get a list of all .java files
JAVA_FILES := $(wildcard src/*.java)
# Use the wildcard function to get a list of all .xml files
XML_FILES := $(wildcard src/*.xml)
# Use the wildcard function to get a list of all .rs files
RUST_FILES := $(wildcard src/*.xml)

# Use string substitution to create a list of corresponding object files
# from the source file list
OBJS := $(patsubst %.c,$(BUILD_DIR)/%.o,$(SRCS))

# Default target
all: $(OBJS)
	$(CXX) -o bma $(OBJS)

# --- Missing Compilers & Flags ---
CXX      := g++
JC       := javac
RUSTC    := rustc
# XML validation tool (optional, common for transformation)
XMLLINT  := xmllint 

# Update OBJS to include C++ files as well
OBJS += $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRCS_CPP))

# --- Missing Pattern Rules ---

# C++: Build .o from .cpp
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Java: Build .class from .java (Outputs to the same directory as source)
# Tip: Use 'javac -d $(BUILD_DIR)' to send them to the build folder instead
%.class: %.java
	$(JC) $<

# Rust: Build binaries from .rs files
# Note: Rust handles dependencies differently; this is for standalone files
$(BUILD_DIR)/%: src/%.rs | $(BUILD_DIR)
	$(RUSTC) $< --out-dir $(BUILD_DIR)

# XML: Optional "Build" step (Validation)
# This 'touches' a dummy file to track when validation was last run
$(BUILD_DIR)/%.xml.valid: src/%.xml | $(BUILD_DIR)
	$(XMLLINT) --noout $<
	touch $@

# Rule to create the build directory if it doesn't exist
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# this thing below is the Pattern rule to build an object file from a source file. Look:
# $< is the first prerequisite (the .c file)
# $@ is the target (the .o file)
$(BUILD_DIR)/%.o: %.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# a `Phony` target for cleaning up created files
clean:
	rm -rf bma $(BUILD_DIR)

.PHONY: all clean
