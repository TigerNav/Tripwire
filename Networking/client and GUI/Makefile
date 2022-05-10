CXX		  := g++
CXX_FLAGS := -Wall -Wextra -std=c++17 -ggdb

BIN		:= bin
INCLUDE	:= include
SRC = src
DEP = $(INCLUDE)/imgui.cpp $(INCLUDE)/imgui_demo.cpp $(INCLUDE)/imgui_draw.cpp $(INCLUDE)/imgui_tables.cpp $(INCLUDE)/imgui_widgets.cpp
DEP += $(INCLUDE)/imgui_impl_glfw.cpp $(INCLUDE)/imgui_impl_opengl3.cpp


LIB		:= lib -lGL -lglfw -lOpenGL -lIrrKlang

LIBRARIES	:=
EXECUTABLE	:= main


all: $(BIN)/$(EXECUTABLE)

run: clean all
	clear
	./$(BIN)/$(EXECUTABLE)

$(BIN)/$(EXECUTABLE): $(DEP) $(SRC)/*.cpp $(SRC)/Window/*.cpp $(SRC)/Networking/*.cpp
	$(CXX) $(CXX_FLAGS) -I$(INCLUDE) -L$(LIB) $^ -o $@ $(LIBRARIES)

clean:
	-rm $(BIN)/*
