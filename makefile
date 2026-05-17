CXX := g++

TARGET := game.exe

CXXFLAGS := -std=c++20 -Wall -Wextra -Iinclude
LDFLAGS := -Llib
LDLIBS := -lraylib -lopengl32 -lgdi32 -lwinmm

SRC := $(wildcard src/*.cpp)
OBJ := $(SRC:.cpp=.o)

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CXX) $(OBJ) -o $(TARGET) $(LDFLAGS) $(LDLIBS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

run: $(TARGET)
	./$(TARGET)

clean:
	-del /Q src\*.o game.exe 2>NUL