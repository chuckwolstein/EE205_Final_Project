# You can use variables in Makefiles in order to make all of the repetitive
# typing much easier. Here, we include the C++11 version flag as well as
# additional warning flags to make compilation stricter (and, thus, our programs
# safer).
#
CXXFLAGS := -Wall -Wextra -pedantic -std=c++11

SRC_DIR := ./src
OBJ_DIR := ./src
INCLUDE_DIRS := -I./dep/ -I./include/

# Here, we are calling functions available in GNU Make in order to get all of
# the .o and .cpp files in ./src so we can use them in our rules later.
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

all: ./bin/main.out

# This build each of the .cpp in the src dir into a .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp
	g++ $(INCLUDE_DIRS) $(CPPFLAGS) $(CXXFLAGS) -c -o  $@ $<

./bin/main.out: $(OBJ_FILES) ./tst/main.cpp ./include/*.hpp
	g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) \
		-o ./bin/main.out \
		./tst/main.cpp $(OBJ_FILES)
	./bin/main.out

# Convenience rules for the command line to quickly test a class

main: ./bin/main.out

clean:
	rm ./src/*.o
	rm ./bin/*.out
