SOURCES=main.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=main
CXX=clang++

all: ${OBJECTS}
	  @${CXX} -o ${EXECUTABLE} ${OBJECTS}

%.o: %.cpp
	@${CXX} -c -o $@ $^

clean: 
	@rm -f ${EXECUTABLE} ${OBJECTS}

rebuild: clean all

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

run:
	./main
