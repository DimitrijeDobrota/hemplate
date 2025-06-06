cmake_minimum_required(VERSION 3.14)

include(cmake/prelude.cmake)

project(
    hemplate
    VERSION 0.4.1
    DESCRIPTION "Simple HTML template engine"
    HOMEPAGE_URL "https://git.dimitrijedobrota.com/hemplate.git"
    LANGUAGES CXX
)

include(cmake/project-is-top-level.cmake)
include(cmake/variables.cmake)

find_package(based 0.2.0 CONFIG REQUIRED)

# ---- Declare library ----

add_library(
    hemplate_hemplate
    source/common.cpp
    source/attribute.cpp
)
target_link_libraries(hemplate_hemplate PUBLIC based::based)
add_library(hemplate::hemplate ALIAS hemplate_hemplate)

include(GenerateExportHeader)
generate_export_header(
    hemplate_hemplate
    BASE_NAME hemplate
    EXPORT_FILE_NAME export/hemplate/hemplate_export.hpp
    CUSTOM_CONTENT_FROM_VARIABLE pragma_suppress_c4251
)

if(NOT BUILD_SHARED_LIBS)
  target_compile_definitions(hemplate_hemplate PUBLIC HEMPLATE_STATIC_DEFINE)
endif()

set_target_properties(
    hemplate_hemplate PROPERTIES
    CXX_VISIBILITY_PRESET hidden
    VISIBILITY_INLINES_HIDDEN YES
    VERSION "${PROJECT_VERSION}"
    SOVERSION "${PROJECT_VERSION_MAJOR}"
    EXPORT_NAME hemplate
    OUTPUT_NAME hemplate
)

target_include_directories(
    hemplate_hemplate ${warning_guard}
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include>"
)

target_include_directories(
    hemplate_hemplate SYSTEM
    PUBLIC
    "\$<BUILD_INTERFACE:${PROJECT_BINARY_DIR}/export>"
)

target_compile_features(hemplate_hemplate PUBLIC cxx_std_20)

# ---- Install rules ----

if(NOT CMAKE_SKIP_INSTALL_RULES)
  include(cmake/install-rules.cmake)
endif()

# ---- Examples ----

if(PROJECT_IS_TOP_LEVEL)
  option(BUILD_EXAMPLES "Build examples tree." "${hemplate_DEVELOPER_MODE}")
  if(BUILD_EXAMPLES)
    add_subdirectory(example)
  endif()
endif()

# ---- Developer mode ----

if(NOT hemplate_DEVELOPER_MODE)
  return()
elseif(NOT PROJECT_IS_TOP_LEVEL)
  message(
      AUTHOR_WARNING
      "Developer mode is intended for developers of hemplate"
  )
endif()

include(cmake/dev-mode.cmake)
