# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.1.3/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/ensimag/youssef/TI/ti/traitement-d-image/code_src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test_gaussien_spatial.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test_gaussien_spatial.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_gaussien_spatial.dir/flags.make

CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.o: CMakeFiles/test_gaussien_spatial.dir/flags.make
CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.o: ../test_gaussien_spatial.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ensimag/youssef/TI/ti/traitement-d-image/code_src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.o"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.o   -c /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/test_gaussien_spatial.c

CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.i"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/test_gaussien_spatial.c > CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.i

CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.s"
	/opt/rh/devtoolset-9/root/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/test_gaussien_spatial.c -o CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.s

# Object files for target test_gaussien_spatial
test_gaussien_spatial_OBJECTS = \
"CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.o"

# External object files for target test_gaussien_spatial
test_gaussien_spatial_EXTERNAL_OBJECTS =

test_gaussien_spatial: CMakeFiles/test_gaussien_spatial.dir/test_gaussien_spatial.c.o
test_gaussien_spatial: CMakeFiles/test_gaussien_spatial.dir/build.make
test_gaussien_spatial: liblibr.so
test_gaussien_spatial: CMakeFiles/test_gaussien_spatial.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ensimag/youssef/TI/ti/traitement-d-image/code_src/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable test_gaussien_spatial"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_gaussien_spatial.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_gaussien_spatial.dir/build: test_gaussien_spatial

.PHONY : CMakeFiles/test_gaussien_spatial.dir/build

CMakeFiles/test_gaussien_spatial.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_gaussien_spatial.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_gaussien_spatial.dir/clean

CMakeFiles/test_gaussien_spatial.dir/depend:
	cd /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ensimag/youssef/TI/ti/traitement-d-image/code_src /home/ensimag/youssef/TI/ti/traitement-d-image/code_src /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/cmake-build-debug /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/cmake-build-debug /home/ensimag/youssef/TI/ti/traitement-d-image/code_src/cmake-build-debug/CMakeFiles/test_gaussien_spatial.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_gaussien_spatial.dir/depend

