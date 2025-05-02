cmake_minimum_required(VERSION 3.14)

project(hemplateTests LANGUAGES CXX)

include(../cmake/project-is-top-level.cmake)
include(../cmake/folders.cmake)


# ---- Dependencies ----

find_package(Catch2 REQUIRED)
include(Catch)

# ---- Tests ----

function(add_test NAME)
  add_executable("${NAME}" "source/${NAME}.cpp")
  target_link_libraries("${NAME}" PRIVATE hemplate::hemplate)
  target_link_libraries("${NAME}" PRIVATE Catch2::Catch2WithMain)
  target_compile_features("${NAME}" PRIVATE cxx_std_20)
  catch_discover_tests("${NAME}")
endfunction()

add_test(attribute_test)
add_test(attribute_list_test)
add_test(element_test)
add_test(classes_test)
add_test(html_test)
add_test(atom_test)
add_test(rss_test)
add_test(sitemap_test)

# ---- End-of-file commands ----

add_folders(Test)
