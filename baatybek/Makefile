#CC specifies which compiler we're using
CC = g++

#flags for compilation
COMPILER_FLAGS = -Iinclude -Wall -pedantic -Wextra -g -c -std=c++14

#COMPILER_SDL_FLAGS = -Wall -pedantic -Wextra -g -c -std=c++11

#flags to link lncurses libraries
LINKER_FLAGS = -lncurses

#directory in which I will store all binary files and also the final executable file
BUILD_DIR = build

#directory in which I will store the application binary
COMPILE_DIR = build

#name of the directory where documentation will be stored
DOCUMENTATION_DIR = doc

#directory with all source files
SOURCE_DIR = src
#directory with dynamic object files
DYNAMIC_OBJ_DIR = DynamicObjects
#directory with Game Logic files
GAME_DIR = Game
#directory with Game object files
GAME_OBJ_DIR = GameObjects
#directory with Menu files
MENU_DIR = Menus
#directory with Doxyfile
DOXY_DIR = Files
#final executable
TARGET_EXEC = baatybek

.PHONY: all compile run doc clean

#builds all from the sources
all: compile

#compiles the application binary, the output binary will be stored at baatybek/baatybek
compile: $(BUILD_DIR)/CInput.o $(BUILD_DIR)/CGhost.o $(BUILD_DIR)/CGhostEasy.o $(BUILD_DIR)/CGhostHard.o $(BUILD_DIR)/CGhostManager.o $(BUILD_DIR)/CWindow.o $(BUILD_DIR)/Dot.o $(BUILD_DIR)/DynamicObject.o $(BUILD_DIR)/Fruit.o $(BUILD_DIR)/GameConfig.o $(BUILD_DIR)/GameEngine.o $(BUILD_DIR)/GameMenu.o $(BUILD_DIR)/GameObject.o $(BUILD_DIR)/PacDot.o $(BUILD_DIR)/Pacman.o $(BUILD_DIR)/PowerPellet.o $(BUILD_DIR)/SetupMenu.o $(BUILD_DIR)/Wall.o $(BUILD_DIR)/main.o
	@mkdir -p $(BUILD_DIR)
	@mkdir -p $(COMPILE_DIR)
	$(CC) $(BUILD_DIR)/*.o -o $(TARGET_EXEC) $(LINKER_FLAGS)

#executes the binary
run: compile $(TARGET_EXEC)
	./$(TARGET_EXEC)

#run: $(COMPILE_DIR)/$(TARGET_EXEC)
#	./$(COMPILE_DIR)/$(TARGET_EXEC)

#create a documentation
doc:
	mkdir -p $(DOCUMENTATION_DIR); doxygen $(SOURCE_DIR)/$(DOXY_DIR)/Doxyfile;
#delete all directories and files created with make
clean:
	rm -rf $(BUILD_DIR)
	rm -rf $(COMPILE_DIR)
	rm -rf $(TARGET_EXEC)

cleandoc:
	rm -rf $(DOCUMENTATION_DIR)


#I will store if alfabethically inside modules
#################################GAME DIRECTORY##############################################
#CInput
$(BUILD_DIR)/CInput.o: $(SOURCE_DIR)/$(GAME_DIR)/CInput.cpp $(SOURCE_DIR)/$(GAME_DIR)/CInput.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_DIR)/CInput.cpp -o $(BUILD_DIR)/CInput.o
#CWindow
$(BUILD_DIR)/CWindow.o: $(SOURCE_DIR)/$(GAME_DIR)/CWindow.cpp $(SOURCE_DIR)/$(GAME_DIR)/CWindow.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_DIR)/CWindow.cpp -o $(BUILD_DIR)/CWindow.o
#GameConfig
$(BUILD_DIR)/GameConfig.o: $(SOURCE_DIR)/$(GAME_DIR)/GameConfig.cpp $(SOURCE_DIR)/$(GAME_DIR)/GameConfig.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_DIR)/GameConfig.cpp -o $(BUILD_DIR)/GameConfig.o
#GameEngine
$(BUILD_DIR)/GameEngine.o: $(SOURCE_DIR)/$(GAME_DIR)/GameEngine.cpp $(SOURCE_DIR)/$(GAME_DIR)/GameEngine.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_DIR)/GameEngine.cpp -o $(BUILD_DIR)/GameEngine.o

#################################GAME OBJECTS DIRECTORY##############################################
#GameObject 
$(BUILD_DIR)/GameObject.o: $(SOURCE_DIR)/$(GAME_OBJ_DIR)/GameObject.cpp $(SOURCE_DIR)/$(GAME_OBJ_DIR)/GameObject.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_OBJ_DIR)/GameObject.cpp -o $(BUILD_DIR)/GameObject.o
#Dot
$(BUILD_DIR)/Dot.o: $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Dot.cpp $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Dot.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Dot.cpp -o $(BUILD_DIR)/Dot.o
#Fruit
$(BUILD_DIR)/Fruit.o: $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Fruit.cpp $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Fruit.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Fruit.cpp -o $(BUILD_DIR)/Fruit.o 
#PowerPellet
$(BUILD_DIR)/PowerPellet.o: $(SOURCE_DIR)/$(GAME_OBJ_DIR)/PowerPellet.cpp $(SOURCE_DIR)/$(GAME_OBJ_DIR)/PowerPellet.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_OBJ_DIR)/PowerPellet.cpp -o $(BUILD_DIR)/PowerPellet.o
#PacDot
$(BUILD_DIR)/PacDot.o: $(SOURCE_DIR)/$(GAME_OBJ_DIR)/PacDot.cpp $(SOURCE_DIR)/$(GAME_OBJ_DIR)/PacDot.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_OBJ_DIR)/PacDot.cpp -o $(BUILD_DIR)/PacDot.o
#Wall
$(BUILD_DIR)/Wall.o: $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Wall.cpp $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Wall.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(GAME_OBJ_DIR)/Wall.cpp -o $(BUILD_DIR)/Wall.o

#################################DYNAMIC OBJECTS DIRECTORY##############################################
#DynamicObject  
$(BUILD_DIR)/DynamicObject.o: $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/DynamicObject.cpp $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/DynamicObject.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/DynamicObject.cpp -o $(BUILD_DIR)/DynamicObject.o
#Pacman
$(BUILD_DIR)/Pacman.o: $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CPacman.cpp $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CPacman.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CPacman.cpp -o $(BUILD_DIR)/Pacman.o 
#CGhostManager
$(BUILD_DIR)/CGhostManager.o: $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostManager.cpp $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostManager.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostManager.cpp -o $(BUILD_DIR)/CGhostManager.o 
#CGhost
$(BUILD_DIR)/CGhost.o: $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhost.cpp $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhost.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhost.cpp -o $(BUILD_DIR)/CGhost.o 
#CGhostEasy
$(BUILD_DIR)/CGhostEasy.o: $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostEasy.cpp $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostEasy.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostEasy.cpp -o $(BUILD_DIR)/CGhostEasy.o 
#CGhostHard
$(BUILD_DIR)/CGhostHard.o: $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostHard.cpp $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostHard.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(DYNAMIC_OBJ_DIR)/CGhostHard.cpp -o $(BUILD_DIR)/CGhostHard.o 

#################################MENU DIRECTORY##############################################

$(BUILD_DIR)/GameMenu.o: $(SOURCE_DIR)/$(MENU_DIR)/GameMenu.cpp $(SOURCE_DIR)/$(MENU_DIR)/GameMenu.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(MENU_DIR)/GameMenu.cpp -o $(BUILD_DIR)/GameMenu.o
#SetupMenu
$(BUILD_DIR)/SetupMenu.o: $(SOURCE_DIR)/$(MENU_DIR)/SetupMenu.cpp $(SOURCE_DIR)/$(MENU_DIR)/SetupMenu.h
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/$(MENU_DIR)/SetupMenu.cpp -o $(BUILD_DIR)/SetupMenu.o
#################################MAIN##############################################
#main
$(BUILD_DIR)/main.o: $(SOURCE_DIR)/main.cpp
	@mkdir -p $(BUILD_DIR)
	$(CC) $(COMPILER_FLAGS) $(SOURCE_DIR)/main.cpp -o $(BUILD_DIR)/main.o