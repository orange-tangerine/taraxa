cmake_minimum_required(VERSION 3.1)
set(CMAKE_CXX_STANDARD 11)

set(CMakeDemo_TEST_SRC
    example.cpp
)

PREPEND(CMakeDemo_TEST_SRC)

# Make an executable target that depends on the test source code we specified
# above.
add_executable(example ${CMakeDemo_TEST_SRC} ${CMakeDemo_TEST_HEADER})

# Enable testing via CTest
enable_testing()
# Add our test as runnable via CTest
add_test(NAME example  COMMAND example)

# Link our unit tests against the library we compiled
target_link_libraries(example CMakeDemo)
