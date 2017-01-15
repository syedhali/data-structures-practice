cmake_minimum_required(VERSION 2.8.7)
project(ds CXX)

file(GLOB_RECURSE DS_SRC
        src/*.cpp
        *.hpp
        *.h)

# Enable this when we have source files!
add_library(ds ${DS_SRC})
set_target_properties(ds PROPERTIES LINKER_LANGUAGE CXX)

include_directories(include)