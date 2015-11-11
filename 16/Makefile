
CC=g++-4.9
CFLAGS=-std=c++14 `fltk-config --cxxflags --ldflags` -L ../fltk -lbookgui -lfltk_images -ljpeg -lfltk_forms -lfltk -L ../13 -l13
SOURCES = $(shell ls *.cpp)
OBJECTS = ${SOURCES:.cpp=.out}

all: $(OBJECTS)

%.out: $(SOURCES)
	$(CC) $(SOURCES) $(CFLAGS) -o $(OBJECTS)

clean:
	rm -rf $(OBJECTS) *.out *.stackdump
