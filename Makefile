CXX=g++
CXXFLAGS=-g

lisp: *.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
