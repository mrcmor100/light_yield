# CMake minimum version requirement
cmake_minimum_required(VERSION 3.20)

# Project name and version
project(MIT VERSION 0.1.0)

# Set default build type to Debug if none is specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

#Obtain the CERN ROOT cflags as ROOT_CFLAGS
execute_process(COMMAND root-config --cflags OUTPUT_VARIABLE ROOT_CFLAGS OUTPUT_STRIP_TRAILING_WHITESPACE)

#Obtain the CERN ROOT include directory as ROOT_CFLAGS
execute_process(COMMAND root-config --incdir OUTPUT_VARIABLE ROOT_INCLUDE OUTPUT_STRIP_TRAILING_WHITESPACE)

#Obtain the CERN ROOT libs  as ROOT_LIBS
execute_process(COMMAND root-config --libs OUTPUT_VARIABLE ROOT_LIBS OUTPUT_STRIP_TRAILING_WHITESPACE)

# Define the executable
add_executable(light_yield src/light_yield.cxx)

# Apply the ROOT compiler flags and include directories
#target_compile_options(light_yield PRIVATE ${ROOT_CFLAGS})

# Link the ROOT include directory
target_include_directories(light_yield PRIVATE ${ROOT_INCLUDE})

# Link the ROOT libraries
target_link_libraries(light_yield PRIVATE ${ROOT_LIBS})

# Print useful information for debugging
message(STATUS "ROOT cflags: ${ROOT_CFLAGS}")
message(STATUS "ROOT include: ${ROOT_INCLUDE}")
message(STATUS "ROOT libs: ${ROOT_LIBS}")

set_target_properties(light_yield PROPERTIES CXX_STANDARD 17)
