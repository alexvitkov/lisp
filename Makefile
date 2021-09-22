CXX=g++
CXXFLAGS=

lisp: *.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@
