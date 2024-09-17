cmake_minimum_required(VERSION 3.14)
project(check_cred_project)

# Set C++ standard
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(googletest
	GIT_REPOSITORY https://github.com/google/googletest
	GIT_TAG release-1.11.0)
FetchContent_GetProperties(googletest)
#googletest_POPULATED
#googletest_SOURCE_DIR
#googletest_BUILD_DIR
if(NOT googletest_POPULATED)
  FetchContent_Populate(googletest)
  add_subdirectory(${googletest_SOURCE_DIR} ${googletest_BUILD_DIR})
endif()

# Create a test binary
add_executable(check_cred_test check_cred_test.cpp)
target_link_libraries(check_cred_test GTest::gtest_main)

# Enable testing
enable_testing()
#gtest_discover_tests(check_cred_test)
