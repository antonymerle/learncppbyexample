# Compiler settings
CXX       := clang++
CXXFLAGS  := -std=c++23 -fcolor-diagnostics -fansi-escape-codes -g \
             -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion \
             -Wsign-conversion -Werror

# File names
SRC       := $(wildcard *.cpp)
TARGET    := learn

# Default target
all: $(TARGET)

# Build rule
$(TARGET): $(SRC)
	@echo "🔧 Compiling..."
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)
	@echo "✅ Build complete: $(TARGET)"

# Run the program
run: $(TARGET)
	@echo "🚀 Running..."
	@./$(TARGET)

# Clean up build artifacts
clean:
	@echo "🧹 Cleaning up..."
	@rm -f $(TARGET)
	@echo "✅ Clean complete"

# Phony targets
.PHONY: all run clean
