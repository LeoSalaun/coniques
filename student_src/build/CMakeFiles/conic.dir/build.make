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
CMAKE_SOURCE_DIR = /home/mailis/Conique/coniques/student_src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mailis/Conique/coniques/student_src/build

# Include any dependencies generated for this target.
include CMakeFiles/conic.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/conic.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/conic.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/conic.dir/flags.make

CMakeFiles/conic.dir/src/main.cpp.o: CMakeFiles/conic.dir/flags.make
CMakeFiles/conic.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/conic.dir/src/main.cpp.o: CMakeFiles/conic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mailis/Conique/coniques/student_src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/conic.dir/src/main.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/conic.dir/src/main.cpp.o -MF CMakeFiles/conic.dir/src/main.cpp.o.d -o CMakeFiles/conic.dir/src/main.cpp.o -c /home/mailis/Conique/coniques/student_src/src/main.cpp

CMakeFiles/conic.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conic.dir/src/main.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mailis/Conique/coniques/student_src/src/main.cpp > CMakeFiles/conic.dir/src/main.cpp.i

CMakeFiles/conic.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conic.dir/src/main.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mailis/Conique/coniques/student_src/src/main.cpp -o CMakeFiles/conic.dir/src/main.cpp.s

CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o: CMakeFiles/conic.dir/flags.make
CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o: ../src/Geogebra_conics.cpp
CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o: CMakeFiles/conic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mailis/Conique/coniques/student_src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o -MF CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o.d -o CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o -c /home/mailis/Conique/coniques/student_src/src/Geogebra_conics.cpp

CMakeFiles/conic.dir/src/Geogebra_conics.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conic.dir/src/Geogebra_conics.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mailis/Conique/coniques/student_src/src/Geogebra_conics.cpp > CMakeFiles/conic.dir/src/Geogebra_conics.cpp.i

CMakeFiles/conic.dir/src/Geogebra_conics.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conic.dir/src/Geogebra_conics.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mailis/Conique/coniques/student_src/src/Geogebra_conics.cpp -o CMakeFiles/conic.dir/src/Geogebra_conics.cpp.s

CMakeFiles/conic.dir/src/Entry.cpp.o: CMakeFiles/conic.dir/flags.make
CMakeFiles/conic.dir/src/Entry.cpp.o: ../src/Entry.cpp
CMakeFiles/conic.dir/src/Entry.cpp.o: CMakeFiles/conic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mailis/Conique/coniques/student_src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/conic.dir/src/Entry.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/conic.dir/src/Entry.cpp.o -MF CMakeFiles/conic.dir/src/Entry.cpp.o.d -o CMakeFiles/conic.dir/src/Entry.cpp.o -c /home/mailis/Conique/coniques/student_src/src/Entry.cpp

CMakeFiles/conic.dir/src/Entry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conic.dir/src/Entry.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mailis/Conique/coniques/student_src/src/Entry.cpp > CMakeFiles/conic.dir/src/Entry.cpp.i

CMakeFiles/conic.dir/src/Entry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conic.dir/src/Entry.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mailis/Conique/coniques/student_src/src/Entry.cpp -o CMakeFiles/conic.dir/src/Entry.cpp.s

CMakeFiles/conic.dir/src/Directory.cpp.o: CMakeFiles/conic.dir/flags.make
CMakeFiles/conic.dir/src/Directory.cpp.o: ../src/Directory.cpp
CMakeFiles/conic.dir/src/Directory.cpp.o: CMakeFiles/conic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mailis/Conique/coniques/student_src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/conic.dir/src/Directory.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/conic.dir/src/Directory.cpp.o -MF CMakeFiles/conic.dir/src/Directory.cpp.o.d -o CMakeFiles/conic.dir/src/Directory.cpp.o -c /home/mailis/Conique/coniques/student_src/src/Directory.cpp

CMakeFiles/conic.dir/src/Directory.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conic.dir/src/Directory.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mailis/Conique/coniques/student_src/src/Directory.cpp > CMakeFiles/conic.dir/src/Directory.cpp.i

CMakeFiles/conic.dir/src/Directory.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conic.dir/src/Directory.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mailis/Conique/coniques/student_src/src/Directory.cpp -o CMakeFiles/conic.dir/src/Directory.cpp.s

CMakeFiles/conic.dir/src/Shape.cpp.o: CMakeFiles/conic.dir/flags.make
CMakeFiles/conic.dir/src/Shape.cpp.o: ../src/Shape.cpp
CMakeFiles/conic.dir/src/Shape.cpp.o: CMakeFiles/conic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mailis/Conique/coniques/student_src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/conic.dir/src/Shape.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/conic.dir/src/Shape.cpp.o -MF CMakeFiles/conic.dir/src/Shape.cpp.o.d -o CMakeFiles/conic.dir/src/Shape.cpp.o -c /home/mailis/Conique/coniques/student_src/src/Shape.cpp

CMakeFiles/conic.dir/src/Shape.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conic.dir/src/Shape.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mailis/Conique/coniques/student_src/src/Shape.cpp > CMakeFiles/conic.dir/src/Shape.cpp.i

CMakeFiles/conic.dir/src/Shape.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conic.dir/src/Shape.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mailis/Conique/coniques/student_src/src/Shape.cpp -o CMakeFiles/conic.dir/src/Shape.cpp.s

CMakeFiles/conic.dir/src/Conic.cpp.o: CMakeFiles/conic.dir/flags.make
CMakeFiles/conic.dir/src/Conic.cpp.o: ../src/Conic.cpp
CMakeFiles/conic.dir/src/Conic.cpp.o: CMakeFiles/conic.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mailis/Conique/coniques/student_src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/conic.dir/src/Conic.cpp.o"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/conic.dir/src/Conic.cpp.o -MF CMakeFiles/conic.dir/src/Conic.cpp.o.d -o CMakeFiles/conic.dir/src/Conic.cpp.o -c /home/mailis/Conique/coniques/student_src/src/Conic.cpp

CMakeFiles/conic.dir/src/Conic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/conic.dir/src/Conic.cpp.i"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mailis/Conique/coniques/student_src/src/Conic.cpp > CMakeFiles/conic.dir/src/Conic.cpp.i

CMakeFiles/conic.dir/src/Conic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/conic.dir/src/Conic.cpp.s"
	/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mailis/Conique/coniques/student_src/src/Conic.cpp -o CMakeFiles/conic.dir/src/Conic.cpp.s

# Object files for target conic
conic_OBJECTS = \
"CMakeFiles/conic.dir/src/main.cpp.o" \
"CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o" \
"CMakeFiles/conic.dir/src/Entry.cpp.o" \
"CMakeFiles/conic.dir/src/Directory.cpp.o" \
"CMakeFiles/conic.dir/src/Shape.cpp.o" \
"CMakeFiles/conic.dir/src/Conic.cpp.o"

# External object files for target conic
conic_EXTERNAL_OBJECTS =

conic: CMakeFiles/conic.dir/src/main.cpp.o
conic: CMakeFiles/conic.dir/src/Geogebra_conics.cpp.o
conic: CMakeFiles/conic.dir/src/Entry.cpp.o
conic: CMakeFiles/conic.dir/src/Directory.cpp.o
conic: CMakeFiles/conic.dir/src/Shape.cpp.o
conic: CMakeFiles/conic.dir/src/Conic.cpp.o
conic: CMakeFiles/conic.dir/build.make
conic: CMakeFiles/conic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mailis/Conique/coniques/student_src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable conic"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/conic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/conic.dir/build: conic
.PHONY : CMakeFiles/conic.dir/build

CMakeFiles/conic.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/conic.dir/cmake_clean.cmake
.PHONY : CMakeFiles/conic.dir/clean

CMakeFiles/conic.dir/depend:
	cd /home/mailis/Conique/coniques/student_src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mailis/Conique/coniques/student_src /home/mailis/Conique/coniques/student_src /home/mailis/Conique/coniques/student_src/build /home/mailis/Conique/coniques/student_src/build /home/mailis/Conique/coniques/student_src/build/CMakeFiles/conic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/conic.dir/depend

