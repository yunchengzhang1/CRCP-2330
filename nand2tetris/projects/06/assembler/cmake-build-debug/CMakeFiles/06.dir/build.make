# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /cygdrive/c/Users/AZ/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe

# The command to remove a file.
RM = /cygdrive/c/Users/AZ/AppData/Local/JetBrains/CLion2020.3/cygwin_cmake/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/06.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/06.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/06.dir/flags.make

CMakeFiles/06.dir/main.cpp.o: CMakeFiles/06.dir/flags.make
CMakeFiles/06.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/06.dir/main.cpp.o"
	/usr/bin/c++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/06.dir/main.cpp.o -c "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/main.cpp"

CMakeFiles/06.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/06.dir/main.cpp.i"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/main.cpp" > CMakeFiles/06.dir/main.cpp.i

CMakeFiles/06.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/06.dir/main.cpp.s"
	/usr/bin/c++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/main.cpp" -o CMakeFiles/06.dir/main.cpp.s

# Object files for target 06
06_OBJECTS = \
"CMakeFiles/06.dir/main.cpp.o"

# External object files for target 06
06_EXTERNAL_OBJECTS =

06.exe: CMakeFiles/06.dir/main.cpp.o
06.exe: CMakeFiles/06.dir/build.make
06.exe: CMakeFiles/06.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable 06.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/06.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/06.dir/build: 06.exe

.PHONY : CMakeFiles/06.dir/build

CMakeFiles/06.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/06.dir/cmake_clean.cmake
.PHONY : CMakeFiles/06.dir/clean

CMakeFiles/06.dir/depend:
	cd "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler" "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler" "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/cmake-build-debug" "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/cmake-build-debug" "/cygdrive/a/2021 spring/NAND/CRCP-2330/nand2tetris/projects/06/assembler/cmake-build-debug/CMakeFiles/06.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/06.dir/depend

