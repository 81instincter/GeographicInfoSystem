CXX = g++
SHELL = /bin/bash

# compiler flags:
CXXFLAGS = -g -std=c++14 -Wall -Wall -Werror=return-type  \
			-Werror=uninitialized -Wno-sign-compare

HEADERS = point.hpp polygon.hpp gis.hpp
OBJECTS = main.o point.o polygon.o gis.o
TESTS = test-1-point test-2-polygon test-3-polygon-advanced test-4-gis

main: $(OBJECTS)
	$(CXX) -o $@ $^

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c -o $@ $<

simple-main: main
	echo -e "bad-file-name.zz\nsimple-polygons.txt\n1\n1\n3\n3\n7\n7\nq\n" | ./main

complex-main: main
	echo -e "polygons.txt\n2\n14\n0\n2\n2\n8\n5\n9\n5\n5\n5\n0\n7\n4\nq\n" | ./main

test-all: $(TESTS)

test-1-point: test/catch/catch.o test/test-1-point.o point.o
	$(CXX) -o $@ $^
	./test-1-point --success

test-2-polygon: test/catch/catch.o test/test-2-polygon.o polygon.o point.o
	$(CXX) -o $@ $^
	./test-2-polygon --success

test-3-polygon-advanced: test/catch/catch.o test/test-3-polygon-advanced.o point.o polygon.o
	$(CXX) -o $@ $^
	./test-3-polygon-advanced --success

test-4-gis: test/catch/catch.o test/test-4-gis.o point.o polygon.o gis.o
	$(CXX) -o $@ $^
	./test-4-gis --success

clean:
	rm -rf *.dSYM test/*.dSYM
	$(RM) *.o *.gc* main test/*.o test/catch/catch.o $(TESTS)
