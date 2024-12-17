# Makefile for Rust project

# Variables
CARGO := cargo
TARGET := target
RELEASE := release
DEBUG := debug

# Default target
all: build

# Build the project in release mode
build:
	$(CARGO) build --release

# Build the project in debug mode
debug:
	$(CARGO) build

# Run the project in release mode
run: build
	$(CARGO) run --release 50000000

# Run the project in debug mode
run-debug: debug
	$(CARGO) run

# Clean the project
clean:
	$(CARGO) clean

.PHONY: all build debug run run-debug clean