DEFS = -DWIN32 # define platform
FLTK_FLAGS = --use-images # specify fltk-config flags
FLTK_DIR = &quot;C:/msys/opt/FLTK/bin&quot; # fltk dir
FLTK_LIB = -L$(shell $(FLTK_DIR)/fltk-config --libs $(FLTK_FLAGS)) # fltk libs
FLTK_CXX_FLAGS = $(shell $(FLTK_DIR)/fltk-config --cxxflags) # compiler flags for fltk
FLTK_LD_FLAGS = $(shell $(FLTK_DIR)/fltk-config --ldflags $(FLTK_FLAGS)) # linker flags
FLTK_INC_DIR = -I$(shell $(FLTK_DIR)/fltk-config --includedir) # fltk header files placement
CXX = g++
CXX_FLAGS = -std=c++11
PROJECT = try_it
SOURCE = try_it.cpp
LIBS_S = ../fltk/GUI.cpp ../fltk/Simple_window.cpp ../fltk/Window.cpp ../fltk/Graph.cpp
 
$(PROJECT): $(SOURCE) $(LIBS_S)
 $(CXX) -o $(PROJECT) $(SOURCE) $(DEFS) $(LIBS_S) $(FLTK_LIB) $(FLTK_LD_FLAGS) $(FLTK_INC_DIR) $(CXX_FLAGS) -I../
 
%.o: %.cpp %.h
 $(CXX) -c $< 
