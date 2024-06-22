cmake_minimum_required(VERSION 3.14)

project(hemplateTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)

# ---- Dependencies ----

if(PROJECT_IS_TOP_LEVEL)
  find_package(hemplate REQUIRED)
  enable_testing()
endif()

# ---- Tests ----

add_executable(hemplate_test source/hemplate_test.cpp)
target_link_libraries(hemplate_test PRIVATE hemplate::hemplate)
target_compile_features(hemplate_test PRIVATE cxx_std_20)

add_test(NAME hemplate_test COMMAND hemplate_test)

# ---- End-of-file commands ----

add_folders(Test)
