cmake_minimum_required(VERSION 3.22)

# set cmake options

# constants
set(UNITY_DIR "/unity") # note this assumes the file is being run in the fpih-test docker container

# create project
project(fpih C ASM)

# add testing executable
message("created executable fpih-test")
add_executable(fpih-test "")

# add Unity test framework 
message(STATUS "adding Unity source from directory: ${UNITY_DIR}")
target_include_directories(fpih-test PRIVATE ${UNITY_DIR})
target_sources(fpih-test PRIVATE ${UNITY_DIR}/unity.c)

# add tests to testing executable
message(status "adding tests")
target_sources(fpih-test PRIVATE 
    fpih-test-util-32.c
)

# add code under test
target_include_directories(fpih-test PRIVATE .. code-under-test)

# add compile options