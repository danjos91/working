# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nshelly/CLionProjects/doom42

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nshelly/CLionProjects/doom42/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/doom42.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/doom42.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/doom42.dir/flags.make

CMakeFiles/doom42.dir/src/engine.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/engine.c.o: ../src/engine.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/doom42.dir/src/engine.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/engine.c.o   -c /Users/nshelly/CLionProjects/doom42/src/engine.c

CMakeFiles/doom42.dir/src/engine.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/engine.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/engine.c > CMakeFiles/doom42.dir/src/engine.c.i

CMakeFiles/doom42.dir/src/engine.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/engine.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/engine.c -o CMakeFiles/doom42.dir/src/engine.c.s

CMakeFiles/doom42.dir/src/engine_exp.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/engine_exp.c.o: ../src/engine_exp.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/doom42.dir/src/engine_exp.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/engine_exp.c.o   -c /Users/nshelly/CLionProjects/doom42/src/engine_exp.c

CMakeFiles/doom42.dir/src/engine_exp.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/engine_exp.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/engine_exp.c > CMakeFiles/doom42.dir/src/engine_exp.c.i

CMakeFiles/doom42.dir/src/engine_exp.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/engine_exp.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/engine_exp.c -o CMakeFiles/doom42.dir/src/engine_exp.c.s

CMakeFiles/doom42.dir/src/functions_main.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/functions_main.c.o: ../src/functions_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/doom42.dir/src/functions_main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/functions_main.c.o   -c /Users/nshelly/CLionProjects/doom42/src/functions_main.c

CMakeFiles/doom42.dir/src/functions_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/functions_main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/functions_main.c > CMakeFiles/doom42.dir/src/functions_main.c.i

CMakeFiles/doom42.dir/src/functions_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/functions_main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/functions_main.c -o CMakeFiles/doom42.dir/src/functions_main.c.s

CMakeFiles/doom42.dir/src/gun.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/gun.c.o: ../src/gun.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/doom42.dir/src/gun.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/gun.c.o   -c /Users/nshelly/CLionProjects/doom42/src/gun.c

CMakeFiles/doom42.dir/src/gun.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/gun.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/gun.c > CMakeFiles/doom42.dir/src/gun.c.i

CMakeFiles/doom42.dir/src/gun.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/gun.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/gun.c -o CMakeFiles/doom42.dir/src/gun.c.s

CMakeFiles/doom42.dir/src/main.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/main.c.o: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/doom42.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/main.c.o   -c /Users/nshelly/CLionProjects/doom42/src/main.c

CMakeFiles/doom42.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/main.c > CMakeFiles/doom42.dir/src/main.c.i

CMakeFiles/doom42.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/main.c -o CMakeFiles/doom42.dir/src/main.c.s

CMakeFiles/doom42.dir/src/math_functions.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/math_functions.c.o: ../src/math_functions.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/doom42.dir/src/math_functions.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/math_functions.c.o   -c /Users/nshelly/CLionProjects/doom42/src/math_functions.c

CMakeFiles/doom42.dir/src/math_functions.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/math_functions.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/math_functions.c > CMakeFiles/doom42.dir/src/math_functions.c.i

CMakeFiles/doom42.dir/src/math_functions.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/math_functions.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/math_functions.c -o CMakeFiles/doom42.dir/src/math_functions.c.s

CMakeFiles/doom42.dir/src/sdl_addons.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/sdl_addons.c.o: ../src/sdl_addons.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/doom42.dir/src/sdl_addons.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/sdl_addons.c.o   -c /Users/nshelly/CLionProjects/doom42/src/sdl_addons.c

CMakeFiles/doom42.dir/src/sdl_addons.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/sdl_addons.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/sdl_addons.c > CMakeFiles/doom42.dir/src/sdl_addons.c.i

CMakeFiles/doom42.dir/src/sdl_addons.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/sdl_addons.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/sdl_addons.c -o CMakeFiles/doom42.dir/src/sdl_addons.c.s

CMakeFiles/doom42.dir/src/textures.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/textures.c.o: ../src/textures.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building C object CMakeFiles/doom42.dir/src/textures.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/textures.c.o   -c /Users/nshelly/CLionProjects/doom42/src/textures.c

CMakeFiles/doom42.dir/src/textures.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/textures.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/textures.c > CMakeFiles/doom42.dir/src/textures.c.i

CMakeFiles/doom42.dir/src/textures.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/textures.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/textures.c -o CMakeFiles/doom42.dir/src/textures.c.s

CMakeFiles/doom42.dir/src/vectors_1.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/vectors_1.c.o: ../src/vectors_1.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building C object CMakeFiles/doom42.dir/src/vectors_1.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/vectors_1.c.o   -c /Users/nshelly/CLionProjects/doom42/src/vectors_1.c

CMakeFiles/doom42.dir/src/vectors_1.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/vectors_1.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/vectors_1.c > CMakeFiles/doom42.dir/src/vectors_1.c.i

CMakeFiles/doom42.dir/src/vectors_1.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/vectors_1.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/vectors_1.c -o CMakeFiles/doom42.dir/src/vectors_1.c.s

CMakeFiles/doom42.dir/src/vectors_2.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/vectors_2.c.o: ../src/vectors_2.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building C object CMakeFiles/doom42.dir/src/vectors_2.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/vectors_2.c.o   -c /Users/nshelly/CLionProjects/doom42/src/vectors_2.c

CMakeFiles/doom42.dir/src/vectors_2.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/vectors_2.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/vectors_2.c > CMakeFiles/doom42.dir/src/vectors_2.c.i

CMakeFiles/doom42.dir/src/vectors_2.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/vectors_2.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/vectors_2.c -o CMakeFiles/doom42.dir/src/vectors_2.c.s

CMakeFiles/doom42.dir/src/walls.c.o: CMakeFiles/doom42.dir/flags.make
CMakeFiles/doom42.dir/src/walls.c.o: ../src/walls.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building C object CMakeFiles/doom42.dir/src/walls.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/doom42.dir/src/walls.c.o   -c /Users/nshelly/CLionProjects/doom42/src/walls.c

CMakeFiles/doom42.dir/src/walls.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/doom42.dir/src/walls.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/nshelly/CLionProjects/doom42/src/walls.c > CMakeFiles/doom42.dir/src/walls.c.i

CMakeFiles/doom42.dir/src/walls.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/doom42.dir/src/walls.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/nshelly/CLionProjects/doom42/src/walls.c -o CMakeFiles/doom42.dir/src/walls.c.s

# Object files for target doom42
doom42_OBJECTS = \
"CMakeFiles/doom42.dir/src/engine.c.o" \
"CMakeFiles/doom42.dir/src/engine_exp.c.o" \
"CMakeFiles/doom42.dir/src/functions_main.c.o" \
"CMakeFiles/doom42.dir/src/gun.c.o" \
"CMakeFiles/doom42.dir/src/main.c.o" \
"CMakeFiles/doom42.dir/src/math_functions.c.o" \
"CMakeFiles/doom42.dir/src/sdl_addons.c.o" \
"CMakeFiles/doom42.dir/src/textures.c.o" \
"CMakeFiles/doom42.dir/src/vectors_1.c.o" \
"CMakeFiles/doom42.dir/src/vectors_2.c.o" \
"CMakeFiles/doom42.dir/src/walls.c.o"

# External object files for target doom42
doom42_EXTERNAL_OBJECTS =

doom42: CMakeFiles/doom42.dir/src/engine.c.o
doom42: CMakeFiles/doom42.dir/src/engine_exp.c.o
doom42: CMakeFiles/doom42.dir/src/functions_main.c.o
doom42: CMakeFiles/doom42.dir/src/gun.c.o
doom42: CMakeFiles/doom42.dir/src/main.c.o
doom42: CMakeFiles/doom42.dir/src/math_functions.c.o
doom42: CMakeFiles/doom42.dir/src/sdl_addons.c.o
doom42: CMakeFiles/doom42.dir/src/textures.c.o
doom42: CMakeFiles/doom42.dir/src/vectors_1.c.o
doom42: CMakeFiles/doom42.dir/src/vectors_2.c.o
doom42: CMakeFiles/doom42.dir/src/walls.c.o
doom42: CMakeFiles/doom42.dir/build.make
doom42: CMakeFiles/doom42.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Linking C executable doom42"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/doom42.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/doom42.dir/build: doom42

.PHONY : CMakeFiles/doom42.dir/build

CMakeFiles/doom42.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/doom42.dir/cmake_clean.cmake
.PHONY : CMakeFiles/doom42.dir/clean

CMakeFiles/doom42.dir/depend:
	cd /Users/nshelly/CLionProjects/doom42/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nshelly/CLionProjects/doom42 /Users/nshelly/CLionProjects/doom42 /Users/nshelly/CLionProjects/doom42/cmake-build-debug /Users/nshelly/CLionProjects/doom42/cmake-build-debug /Users/nshelly/CLionProjects/doom42/cmake-build-debug/CMakeFiles/doom42.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/doom42.dir/depend

