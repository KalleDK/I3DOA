SOURCES=main.cpp binsearch.cpp
OBJECTS=${SOURCES:.cpp=.o}
EXECUTABLE=main
CXX=clang++
CXXFLAGS+=-Wall -pedantic

ifdef X
CXXFLAGS += -DX=${X}
endif

ifdef SIZE
CXXFLAGS += -DA_SIZE=${SIZE}
endif

ifdef DEBUG
CXXFLAGS += -DDEBUG
endif

all: ${OBJECTS}
	@${CXX} -o ${EXECUTABLE} ${OBJECTS}

%.o: %.cpp
	@echo ${SIZE}
	${CXX} ${CXXFLAGS} -c -o $@ $^

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
