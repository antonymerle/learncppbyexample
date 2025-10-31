MAKEFLAGS += -j$(shell nproc)

# Compiler settings
CXX       := clang++
CXXFLAGS  := -std=c++23 -fcolor-diagnostics -fansi-escape-codes -g \
             -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion \
             -Wsign-conversion -Werror

# Directories
BUILD_DIR := build

# File names
SRC       := $(wildcard *.cpp)
OBJ       := $(patsubst %.cpp,$(BUILD_DIR)/%.o,$(SRC))
TARGET    := learn

# Default target
all: $(TARGET)

# Build rule - link object files
$(TARGET): $(OBJ)
	@echo "🔗 Linking..."
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(TARGET)
	@echo "✅ Build complete: $(TARGET)"

# Compile individual source files to object files
$(BUILD_DIR)/%.o: %.cpp | $(BUILD_DIR)
	@echo "🔧 Compiling $<..."
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Create build directory if it doesn't exist
$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

# Run the program
run: $(TARGET)
	@echo "🚀 Running..."
	@./$(TARGET)

# Clean up build artifacts
clean:
	@echo "🧹 Cleaning up..."
	@rm -rf $(TARGET) $(BUILD_DIR)
	@echo "✅ Clean complete"

# Phony targets
.PHONY: all run clean
