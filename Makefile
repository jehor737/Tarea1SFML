# Variables used for the implicit rules
CXX = g++
CXXFLAGS = -Wall -std=c++11 -lsfml-graphics -lsfml-window -lsfml-system
#LDFLAGS = -lm

# OBJECTS = test_vector_list.o Vector3D.o
DEPS = Node.h LinkedList.h Box.h
# Basic rule to compile the program
#name: requirements
#tab->instruction in the compiler
# $@ name the executable with the same name of the rule
# $^ uses all the requeriments written
testBox: main.o
	$(CXX) $^ -o $@ $(CXXFLAGS) $(LDFLAGS)

%.o: %.cpp $(DEPS)
	$(CXX) -o $@ $< $(CXXFLAGS) -c

clean:
	-rm -f testBox *.o
#avoid confusion with a rule and a file with the same name
.PHONY: clean
