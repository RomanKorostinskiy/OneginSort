# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/clion/169/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/169/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/roman/CS/C/Huawei/OneginSort

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/roman/CS/C/Huawei/OneginSort/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/OneginSort.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/OneginSort.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/OneginSort.dir/flags.make

CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.o: CMakeFiles/OneginSort.dir/flags.make
CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.o: ../src/MakeStringFunc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roman/CS/C/Huawei/OneginSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.o -c /home/roman/CS/C/Huawei/OneginSort/src/MakeStringFunc.cpp

CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roman/CS/C/Huawei/OneginSort/src/MakeStringFunc.cpp > CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.i

CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roman/CS/C/Huawei/OneginSort/src/MakeStringFunc.cpp -o CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.s

CMakeFiles/OneginSort.dir/src/OneginSort.cpp.o: CMakeFiles/OneginSort.dir/flags.make
CMakeFiles/OneginSort.dir/src/OneginSort.cpp.o: ../src/OneginSort.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roman/CS/C/Huawei/OneginSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/OneginSort.dir/src/OneginSort.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OneginSort.dir/src/OneginSort.cpp.o -c /home/roman/CS/C/Huawei/OneginSort/src/OneginSort.cpp

CMakeFiles/OneginSort.dir/src/OneginSort.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OneginSort.dir/src/OneginSort.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roman/CS/C/Huawei/OneginSort/src/OneginSort.cpp > CMakeFiles/OneginSort.dir/src/OneginSort.cpp.i

CMakeFiles/OneginSort.dir/src/OneginSort.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OneginSort.dir/src/OneginSort.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roman/CS/C/Huawei/OneginSort/src/OneginSort.cpp -o CMakeFiles/OneginSort.dir/src/OneginSort.cpp.s

CMakeFiles/OneginSort.dir/src/SortFunc.cpp.o: CMakeFiles/OneginSort.dir/flags.make
CMakeFiles/OneginSort.dir/src/SortFunc.cpp.o: ../src/SortFunc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/roman/CS/C/Huawei/OneginSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/OneginSort.dir/src/SortFunc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/OneginSort.dir/src/SortFunc.cpp.o -c /home/roman/CS/C/Huawei/OneginSort/src/SortFunc.cpp

CMakeFiles/OneginSort.dir/src/SortFunc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/OneginSort.dir/src/SortFunc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/roman/CS/C/Huawei/OneginSort/src/SortFunc.cpp > CMakeFiles/OneginSort.dir/src/SortFunc.cpp.i

CMakeFiles/OneginSort.dir/src/SortFunc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/OneginSort.dir/src/SortFunc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/roman/CS/C/Huawei/OneginSort/src/SortFunc.cpp -o CMakeFiles/OneginSort.dir/src/SortFunc.cpp.s

# Object files for target OneginSort
OneginSort_OBJECTS = \
"CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.o" \
"CMakeFiles/OneginSort.dir/src/OneginSort.cpp.o" \
"CMakeFiles/OneginSort.dir/src/SortFunc.cpp.o"

# External object files for target OneginSort
OneginSort_EXTERNAL_OBJECTS =

OneginSort: CMakeFiles/OneginSort.dir/src/MakeStringFunc.cpp.o
OneginSort: CMakeFiles/OneginSort.dir/src/OneginSort.cpp.o
OneginSort: CMakeFiles/OneginSort.dir/src/SortFunc.cpp.o
OneginSort: CMakeFiles/OneginSort.dir/build.make
OneginSort: CMakeFiles/OneginSort.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/roman/CS/C/Huawei/OneginSort/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable OneginSort"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/OneginSort.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/OneginSort.dir/build: OneginSort
.PHONY : CMakeFiles/OneginSort.dir/build

CMakeFiles/OneginSort.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/OneginSort.dir/cmake_clean.cmake
.PHONY : CMakeFiles/OneginSort.dir/clean

CMakeFiles/OneginSort.dir/depend:
	cd /home/roman/CS/C/Huawei/OneginSort/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/roman/CS/C/Huawei/OneginSort /home/roman/CS/C/Huawei/OneginSort /home/roman/CS/C/Huawei/OneginSort/cmake-build-debug /home/roman/CS/C/Huawei/OneginSort/cmake-build-debug /home/roman/CS/C/Huawei/OneginSort/cmake-build-debug/CMakeFiles/OneginSort.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/OneginSort.dir/depend

