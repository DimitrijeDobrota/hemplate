if(PROJECT_IS_TOP_LEVEL)
  set(
      CMAKE_INSTALL_INCLUDEDIR "include/hemplate-${PROJECT_VERSION}"
      CACHE STRING ""
  )
  set_property(CACHE CMAKE_INSTALL_INCLUDEDIR PROPERTY TYPE PATH)
endif()

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# find_package(<package>) call for consumers to find this project
set(package hemplate)

install(
    DIRECTORY
    include/
    "${PROJECT_BINARY_DIR}/export/"
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
    COMPONENT hemplate_Development
)

install(
    TARGETS hemplate_hemplate
    EXPORT hemplateTargets
    RUNTIME #
    COMPONENT hemplate_Runtime
    LIBRARY #
    COMPONENT hemplate_Runtime
    NAMELINK_COMPONENT hemplate_Development
    ARCHIVE #
    COMPONENT hemplate_Development
    INCLUDES #
    DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}"
)

write_basic_package_version_file(
    "${package}ConfigVersion.cmake"
    COMPATIBILITY SameMajorVersion
)

# Allow package maintainers to freely override the path for the configs
set(
    hemplate_INSTALL_CMAKEDIR "${CMAKE_INSTALL_LIBDIR}/cmake/${package}"
    CACHE STRING "CMake package config location relative to the install prefix"
)
set_property(CACHE hemplate_INSTALL_CMAKEDIR PROPERTY TYPE PATH)
mark_as_advanced(hemplate_INSTALL_CMAKEDIR)

install(
    FILES cmake/install-config.cmake
    DESTINATION "${hemplate_INSTALL_CMAKEDIR}"
    RENAME "${package}Config.cmake"
    COMPONENT hemplate_Development
)

install(
    FILES "${PROJECT_BINARY_DIR}/${package}ConfigVersion.cmake"
    DESTINATION "${hemplate_INSTALL_CMAKEDIR}"
    COMPONENT hemplate_Development
)

install(
    EXPORT hemplateTargets
    NAMESPACE hemplate::
    DESTINATION "${hemplate_INSTALL_CMAKEDIR}"
    COMPONENT hemplate_Development
)

if(PROJECT_IS_TOP_LEVEL)
  include(CPack)
endif()
