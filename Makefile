CXX = g++
CXXFLAGS = -O2 -Wall -std=c++17
LDFLAGS = -lopenblas

TARGET = benchmark
SOURCES = lab6.cpp

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SOURCES) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean
