#Variables for the makefile
CXXFLAGS := -c -Wall -Wextra -pedantic -std=c++11
MAC_SFML_FLAGS1 := -framework sfml-system -framework sfml-window -framework sfml-graphics
MAC_SFML_FLAGS2 := -framework sfml-audio -framework sfml-network
LINUX_SFML_FLAGS := -lsfml-system -lsfml-window -lsfml-graphics -lsfml-audio -lsfml-network

SRC_DIR := ./src
OBJ_DIR := ./src
INCLUDE_DIRS := -I./media/ -I./include/

# Here, we are calling functions available in GNU Make in order to get all of
# the .o and .cpp files in ./src so we can use them in our rules later.
SRC_FILES := $(wildcard $(SRC_DIR)/*.cpp)
OBJ_FILES := $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC_FILES))

linux:	linuxPre linuxPost runExecutable

mac:	macOneStep runExecutable

linuxPre:	$(OBJ_FILES) ./src/main.cpp ./include/*.hpp
		g++ $(CPPFLAGS) $(CXXFLAGS) $(INCLUDE_DIRS) ./src/main.cpp


linuxPost:
	g++ ./src/main.o -o ./bin/TrafficDodger $(LINUX_SFML_FLAGS)


macOneStep: $(OBJ_FILES) ./src/main.cpp ./include/*.hpp
	g++ $(MAC_SFML_FLAGS1) $(MAC_SFML_FLAGS2)	main.cpp -o ./bin/TrafficDodger

runExecutable:
	./bin/TrafficDodger

clean:
	rm ./src/*.o
	rm ./bin/*.out ./bin/TrafficDodger
