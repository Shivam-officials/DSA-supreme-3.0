cmake_minimum_required(VERSION 3.20)
project(DSA_Supreme_3_0 CXX)

set(CMAKE_CXX_STANDARD 17)

# Force all compiled binary executables to be generated in the build directory,
# keeping the source directories completely clean of binary files.
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Find all C++ source files recursively in all directories
file(GLOB_RECURSE SOURCE_FILES *.cpp)

foreach(source_file ${SOURCE_FILES})
    # Skip temporary, build, or backup directories just in case
    if(NOT source_file MATCHES "cmake-build-" AND NOT source_file MATCHES "/build/")
        # Get relative path of the file from the source directory
        file(RELATIVE_PATH rel_path ${CMAKE_SOURCE_DIR} ${source_file})
        
        # Remove trailing .cpp extension
        string(REGEX REPLACE "\\.cpp$" "" target_name ${rel_path})
        
        # Replace all invalid target characters (anything not alphanumeric, _, -, or +) with underscores
        string(REGEX REPLACE "[^a-zA-Z0-9_+-]" "_" target_name ${target_name})
        
        # Add the executable target
        add_executable(${target_name} ${source_file})
    endif()
endforeach()
