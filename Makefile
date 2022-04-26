CXX?=g++ 
CXXFLAGS+= --std=c++17 -O3 -Wextra -I.
SOURCES=src/main.cpp src/utils.cpp src/input.cpp src/rectangle.cpp src/coordinateSystem.cpp

src/%.o: src/%.cpp 
	$(CXX) $(CXXFLAGS) -c -o $@ $<

app: $(SOURCES:.cpp=.o)
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm src/*.o