# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = C:\Users\Matze\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = C:\Users\Matze\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Matze\CLionProjects\CG_FutureShock\src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug

# Include any dependencies generated for this target.
include external/glfw-3.1.2/tests/CMakeFiles/windows.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include external/glfw-3.1.2/tests/CMakeFiles/windows.dir/compiler_depend.make

# Include the progress variables for this target.
include external/glfw-3.1.2/tests/CMakeFiles/windows.dir/progress.make

# Include the compile flags for this target's objects.
include external/glfw-3.1.2/tests/CMakeFiles/windows.dir/flags.make

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.obj: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/flags.make
external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.obj: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/includes_C.rsp
external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.obj: ../external/glfw-3.1.2/tests/windows.c
external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.obj: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.obj"
	cd /d C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\external\glfw-3.1.2\tests && C:\Users\Matze\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.obj -MF CMakeFiles\windows.dir\windows.c.obj.d -o CMakeFiles\windows.dir\windows.c.obj -c C:\Users\Matze\CLionProjects\CG_FutureShock\src\external\glfw-3.1.2\tests\windows.c

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/windows.dir/windows.c.i"
	cd /d C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\external\glfw-3.1.2\tests && C:\Users\Matze\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Matze\CLionProjects\CG_FutureShock\src\external\glfw-3.1.2\tests\windows.c > CMakeFiles\windows.dir\windows.c.i

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/windows.dir/windows.c.s"
	cd /d C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\external\glfw-3.1.2\tests && C:\Users\Matze\AppData\Local\JetBrains\Toolbox\apps\CLion\ch-0\222.4345.21\bin\mingw\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Matze\CLionProjects\CG_FutureShock\src\external\glfw-3.1.2\tests\windows.c -o CMakeFiles\windows.dir\windows.c.s

# Object files for target windows
windows_OBJECTS = \
"CMakeFiles/windows.dir/windows.c.obj"

# External object files for target windows
windows_EXTERNAL_OBJECTS =

external/glfw-3.1.2/tests/windows.exe: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/windows.c.obj
external/glfw-3.1.2/tests/windows.exe: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build.make
external/glfw-3.1.2/tests/windows.exe: external/glfw-3.1.2/src/libglfw3.a
external/glfw-3.1.2/tests/windows.exe: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/linklibs.rsp
external/glfw-3.1.2/tests/windows.exe: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/objects1.rsp
external/glfw-3.1.2/tests/windows.exe: external/glfw-3.1.2/tests/CMakeFiles/windows.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable windows.exe"
	cd /d C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\external\glfw-3.1.2\tests && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\windows.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build: external/glfw-3.1.2/tests/windows.exe
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/windows.dir/build

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/clean:
	cd /d C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\external\glfw-3.1.2\tests && $(CMAKE_COMMAND) -P CMakeFiles\windows.dir\cmake_clean.cmake
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/windows.dir/clean

external/glfw-3.1.2/tests/CMakeFiles/windows.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Matze\CLionProjects\CG_FutureShock\src C:\Users\Matze\CLionProjects\CG_FutureShock\src\external\glfw-3.1.2\tests C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\external\glfw-3.1.2\tests C:\Users\Matze\CLionProjects\CG_FutureShock\src\cmake-build-debug\external\glfw-3.1.2\tests\CMakeFiles\windows.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : external/glfw-3.1.2/tests/CMakeFiles/windows.dir/depend

