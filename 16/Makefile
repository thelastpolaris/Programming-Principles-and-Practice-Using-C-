CC=g++-4.9
CFLAGS=-std=c++14 `fltk-config --cxxflags --ldflags` -L ../fltk -lbookgui -lfltk_images -ljpeg -lfltk_forms -lfltk -L ../13 -l13 -Wno-narrowing
#CPP_FILES := $(wildcard *.cpp)
OUT_FILES := $(notdir $(CPP:.cpp=.out))
C := $(CPP:.cpp=.out)
all:
	$(CC) $(CPP) $(CFLAGS) -o $(C)

#all: $(OUT_FILES)

#%.out: %.cpp
#	$(CC) $< $(CPP) $(CFLAGS) -o $@