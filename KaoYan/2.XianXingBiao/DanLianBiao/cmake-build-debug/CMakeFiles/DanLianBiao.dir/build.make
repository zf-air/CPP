# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\CLion 2021.1.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\GitProjects\CPP\KaoYan\DanLianBiao

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\GitProjects\CPP\KaoYan\DanLianBiao\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/DanLianBiao.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/DanLianBiao.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/DanLianBiao.dir/flags.make

CMakeFiles/DanLianBiao.dir/main.cpp.obj: CMakeFiles/DanLianBiao.dir/flags.make
CMakeFiles/DanLianBiao.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\GitProjects\CPP\KaoYan\DanLianBiao\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/DanLianBiao.dir/main.cpp.obj"
	E:\Qt5.13.1\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\DanLianBiao.dir\main.cpp.obj -c E:\GitProjects\CPP\KaoYan\DanLianBiao\main.cpp

CMakeFiles/DanLianBiao.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/DanLianBiao.dir/main.cpp.i"
	E:\Qt5.13.1\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E E:\GitProjects\CPP\KaoYan\DanLianBiao\main.cpp > CMakeFiles\DanLianBiao.dir\main.cpp.i

CMakeFiles/DanLianBiao.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/DanLianBiao.dir/main.cpp.s"
	E:\Qt5.13.1\Tools\mingw730_64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S E:\GitProjects\CPP\KaoYan\DanLianBiao\main.cpp -o CMakeFiles\DanLianBiao.dir\main.cpp.s

# Object files for target DanLianBiao
DanLianBiao_OBJECTS = \
"CMakeFiles/DanLianBiao.dir/main.cpp.obj"

# External object files for target DanLianBiao
DanLianBiao_EXTERNAL_OBJECTS =

DanLianBiao.exe: CMakeFiles/DanLianBiao.dir/main.cpp.obj
DanLianBiao.exe: CMakeFiles/DanLianBiao.dir/build.make
DanLianBiao.exe: CMakeFiles/DanLianBiao.dir/linklibs.rsp
DanLianBiao.exe: CMakeFiles/DanLianBiao.dir/objects1.rsp
DanLianBiao.exe: CMakeFiles/DanLianBiao.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\GitProjects\CPP\KaoYan\DanLianBiao\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable DanLianBiao.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\DanLianBiao.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/DanLianBiao.dir/build: DanLianBiao.exe

.PHONY : CMakeFiles/DanLianBiao.dir/build

CMakeFiles/DanLianBiao.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\DanLianBiao.dir\cmake_clean.cmake
.PHONY : CMakeFiles/DanLianBiao.dir/clean

CMakeFiles/DanLianBiao.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\GitProjects\CPP\KaoYan\DanLianBiao E:\GitProjects\CPP\KaoYan\DanLianBiao E:\GitProjects\CPP\KaoYan\DanLianBiao\cmake-build-debug E:\GitProjects\CPP\KaoYan\DanLianBiao\cmake-build-debug E:\GitProjects\CPP\KaoYan\DanLianBiao\cmake-build-debug\CMakeFiles\DanLianBiao.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/DanLianBiao.dir/depend
