# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/axel/git/Hearthstone-Battleground-Clone

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/axel/git/Hearthstone-Battleground-Clone/build

# Include any dependencies generated for this target.
include CMakeFiles/HearthStoneClone.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HearthStoneClone.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HearthStoneClone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HearthStoneClone.dir/flags.make

CMakeFiles/HearthStoneClone.dir/main.cpp.o: CMakeFiles/HearthStoneClone.dir/flags.make
CMakeFiles/HearthStoneClone.dir/main.cpp.o: ../main.cpp
CMakeFiles/HearthStoneClone.dir/main.cpp.o: CMakeFiles/HearthStoneClone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HearthStoneClone.dir/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HearthStoneClone.dir/main.cpp.o -MF CMakeFiles/HearthStoneClone.dir/main.cpp.o.d -o CMakeFiles/HearthStoneClone.dir/main.cpp.o -c /home/axel/git/Hearthstone-Battleground-Clone/main.cpp

CMakeFiles/HearthStoneClone.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HearthStoneClone.dir/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/axel/git/Hearthstone-Battleground-Clone/main.cpp > CMakeFiles/HearthStoneClone.dir/main.cpp.i

CMakeFiles/HearthStoneClone.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HearthStoneClone.dir/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/axel/git/Hearthstone-Battleground-Clone/main.cpp -o CMakeFiles/HearthStoneClone.dir/main.cpp.s

CMakeFiles/HearthStoneClone.dir/Player.cpp.o: CMakeFiles/HearthStoneClone.dir/flags.make
CMakeFiles/HearthStoneClone.dir/Player.cpp.o: ../Player.cpp
CMakeFiles/HearthStoneClone.dir/Player.cpp.o: CMakeFiles/HearthStoneClone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HearthStoneClone.dir/Player.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HearthStoneClone.dir/Player.cpp.o -MF CMakeFiles/HearthStoneClone.dir/Player.cpp.o.d -o CMakeFiles/HearthStoneClone.dir/Player.cpp.o -c /home/axel/git/Hearthstone-Battleground-Clone/Player.cpp

CMakeFiles/HearthStoneClone.dir/Player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HearthStoneClone.dir/Player.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/axel/git/Hearthstone-Battleground-Clone/Player.cpp > CMakeFiles/HearthStoneClone.dir/Player.cpp.i

CMakeFiles/HearthStoneClone.dir/Player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HearthStoneClone.dir/Player.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/axel/git/Hearthstone-Battleground-Clone/Player.cpp -o CMakeFiles/HearthStoneClone.dir/Player.cpp.s

CMakeFiles/HearthStoneClone.dir/game.cpp.o: CMakeFiles/HearthStoneClone.dir/flags.make
CMakeFiles/HearthStoneClone.dir/game.cpp.o: ../game.cpp
CMakeFiles/HearthStoneClone.dir/game.cpp.o: CMakeFiles/HearthStoneClone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/HearthStoneClone.dir/game.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HearthStoneClone.dir/game.cpp.o -MF CMakeFiles/HearthStoneClone.dir/game.cpp.o.d -o CMakeFiles/HearthStoneClone.dir/game.cpp.o -c /home/axel/git/Hearthstone-Battleground-Clone/game.cpp

CMakeFiles/HearthStoneClone.dir/game.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HearthStoneClone.dir/game.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/axel/git/Hearthstone-Battleground-Clone/game.cpp > CMakeFiles/HearthStoneClone.dir/game.cpp.i

CMakeFiles/HearthStoneClone.dir/game.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HearthStoneClone.dir/game.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/axel/git/Hearthstone-Battleground-Clone/game.cpp -o CMakeFiles/HearthStoneClone.dir/game.cpp.s

CMakeFiles/HearthStoneClone.dir/Minions.cpp.o: CMakeFiles/HearthStoneClone.dir/flags.make
CMakeFiles/HearthStoneClone.dir/Minions.cpp.o: ../Minions.cpp
CMakeFiles/HearthStoneClone.dir/Minions.cpp.o: CMakeFiles/HearthStoneClone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/HearthStoneClone.dir/Minions.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HearthStoneClone.dir/Minions.cpp.o -MF CMakeFiles/HearthStoneClone.dir/Minions.cpp.o.d -o CMakeFiles/HearthStoneClone.dir/Minions.cpp.o -c /home/axel/git/Hearthstone-Battleground-Clone/Minions.cpp

CMakeFiles/HearthStoneClone.dir/Minions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HearthStoneClone.dir/Minions.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/axel/git/Hearthstone-Battleground-Clone/Minions.cpp > CMakeFiles/HearthStoneClone.dir/Minions.cpp.i

CMakeFiles/HearthStoneClone.dir/Minions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HearthStoneClone.dir/Minions.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/axel/git/Hearthstone-Battleground-Clone/Minions.cpp -o CMakeFiles/HearthStoneClone.dir/Minions.cpp.s

CMakeFiles/HearthStoneClone.dir/shop.cpp.o: CMakeFiles/HearthStoneClone.dir/flags.make
CMakeFiles/HearthStoneClone.dir/shop.cpp.o: ../shop.cpp
CMakeFiles/HearthStoneClone.dir/shop.cpp.o: CMakeFiles/HearthStoneClone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/HearthStoneClone.dir/shop.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HearthStoneClone.dir/shop.cpp.o -MF CMakeFiles/HearthStoneClone.dir/shop.cpp.o.d -o CMakeFiles/HearthStoneClone.dir/shop.cpp.o -c /home/axel/git/Hearthstone-Battleground-Clone/shop.cpp

CMakeFiles/HearthStoneClone.dir/shop.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HearthStoneClone.dir/shop.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/axel/git/Hearthstone-Battleground-Clone/shop.cpp > CMakeFiles/HearthStoneClone.dir/shop.cpp.i

CMakeFiles/HearthStoneClone.dir/shop.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HearthStoneClone.dir/shop.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/axel/git/Hearthstone-Battleground-Clone/shop.cpp -o CMakeFiles/HearthStoneClone.dir/shop.cpp.s

CMakeFiles/HearthStoneClone.dir/Board.cpp.o: CMakeFiles/HearthStoneClone.dir/flags.make
CMakeFiles/HearthStoneClone.dir/Board.cpp.o: ../Board.cpp
CMakeFiles/HearthStoneClone.dir/Board.cpp.o: CMakeFiles/HearthStoneClone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/HearthStoneClone.dir/Board.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/HearthStoneClone.dir/Board.cpp.o -MF CMakeFiles/HearthStoneClone.dir/Board.cpp.o.d -o CMakeFiles/HearthStoneClone.dir/Board.cpp.o -c /home/axel/git/Hearthstone-Battleground-Clone/Board.cpp

CMakeFiles/HearthStoneClone.dir/Board.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HearthStoneClone.dir/Board.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/axel/git/Hearthstone-Battleground-Clone/Board.cpp > CMakeFiles/HearthStoneClone.dir/Board.cpp.i

CMakeFiles/HearthStoneClone.dir/Board.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HearthStoneClone.dir/Board.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/axel/git/Hearthstone-Battleground-Clone/Board.cpp -o CMakeFiles/HearthStoneClone.dir/Board.cpp.s

# Object files for target HearthStoneClone
HearthStoneClone_OBJECTS = \
"CMakeFiles/HearthStoneClone.dir/main.cpp.o" \
"CMakeFiles/HearthStoneClone.dir/Player.cpp.o" \
"CMakeFiles/HearthStoneClone.dir/game.cpp.o" \
"CMakeFiles/HearthStoneClone.dir/Minions.cpp.o" \
"CMakeFiles/HearthStoneClone.dir/shop.cpp.o" \
"CMakeFiles/HearthStoneClone.dir/Board.cpp.o"

# External object files for target HearthStoneClone
HearthStoneClone_EXTERNAL_OBJECTS =

HearthStoneClone: CMakeFiles/HearthStoneClone.dir/main.cpp.o
HearthStoneClone: CMakeFiles/HearthStoneClone.dir/Player.cpp.o
HearthStoneClone: CMakeFiles/HearthStoneClone.dir/game.cpp.o
HearthStoneClone: CMakeFiles/HearthStoneClone.dir/Minions.cpp.o
HearthStoneClone: CMakeFiles/HearthStoneClone.dir/shop.cpp.o
HearthStoneClone: CMakeFiles/HearthStoneClone.dir/Board.cpp.o
HearthStoneClone: CMakeFiles/HearthStoneClone.dir/build.make
HearthStoneClone: CMakeFiles/HearthStoneClone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable HearthStoneClone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HearthStoneClone.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HearthStoneClone.dir/build: HearthStoneClone
.PHONY : CMakeFiles/HearthStoneClone.dir/build

CMakeFiles/HearthStoneClone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HearthStoneClone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HearthStoneClone.dir/clean

CMakeFiles/HearthStoneClone.dir/depend:
	cd /home/axel/git/Hearthstone-Battleground-Clone/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/axel/git/Hearthstone-Battleground-Clone /home/axel/git/Hearthstone-Battleground-Clone /home/axel/git/Hearthstone-Battleground-Clone/build /home/axel/git/Hearthstone-Battleground-Clone/build /home/axel/git/Hearthstone-Battleground-Clone/build/CMakeFiles/HearthStoneClone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HearthStoneClone.dir/depend

