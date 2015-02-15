SOURCES=main.cpp Room.cpp Maze.cpp Player.cpp Compass.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=main
CXX=clang++
CXXFLAGS=-std=c++11

all: ${OBJECTS}
	  @${CXX} -o ${EXECUTABLE} ${OBJECTS}

%.o: %.cpp
	@${CXX} ${CXXFLAGS} -c -o $@ $^ -g

clean: 
	@rm -f ${EXECUTABLE} ${OBJECTS}

help:
	@echo "Targets:"
	@echo "  all"
	@echo "  clean"
	@echo "  help"
	@echo ""
	@echo "Vars:"
	@echo "  CXX"
	@echo "  EXECUTABLE"
	@echo "" 

rebuild: clean all
