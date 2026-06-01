cmake_minimum_required(VERSION 3.21)

project(prot-ser
    VERSION 1.0.0
    LANGUAGES CXX
)

include(CMakePackageConfigHelpers)
include(GNUInstallDirs)

# Library

add_library(prot-ser STATIC
    protocols.cpp
)

add_library(prot-ser::prot-ser ALIAS prot-ser)

# C standard

set_target_properties(prot-ser PROPERTIES
    CXX_STANDARD 20
    CXX_STANDARD_REQUIRED ON
    CXX_EXTENSIONS OFF
)

# Headers

target_include_directories(prot-ser
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)

# Defines

target_compile_definitions(prot-ser
    PUBLIC
    PROTSER_VER_MAJOR=${PROJECT_VERSION_MAJOR}
    PROTSER_VER_MINOR=${PROJECT_VERSION_MINOR}
    PROTSER_VER_PATCH=${PROJECT_VERSION_PATCH}
)

# Depndencies

cmake_path(SET YAML_CPP_PATH_CMAKE "$ENV{YAML_CPP_PATH}")
list(APPEND CMAKE_PREFIX_PATH "${YAML_CPP_PATH_CMAKE}")

find_package(yaml-cpp REQUIRED CONFIG)

target_link_libraries(prot-ser
    PUBLIC
    yaml-cpp::yaml-cpp
)

# Name output debug/release

set_target_properties(prot-ser PROPERTIES
    DEBUG_POSTFIX d
)

# Install

cmake_path(SET PROTOCOL_SERIALIZER_PATH_CMAKE "$ENV{PROTOCOL_SERIALIZER_PATH}")
if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
    set(CMAKE_INSTALL_PREFIX ${PROTOCOL_SERIALIZER_PATH_CMAKE} CACHE PATH "Install path" FORCE)
endif()

install(TARGETS prot-ser
    EXPORT prot-serTargets
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
)

# Install header

install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR}
    FILES_MATCHING
    PATTERN "*.h"
    PATTERN "*.hpp"
)

# Export target

install(EXPORT prot-serTargets
    FILE prot-serTargets.cmake
    NAMESPACE prot-ser::
    DESTINATION "${CMAKE_INSTALL_PREFIX}/cmake/\${CMAKE_INSTALL_CONFIG_NAME}"
)

# Config package

configure_package_config_file(
    cmake/prot-serConfig.cmake.in
    ${CMAKE_CURRENT_BINARY_DIR}/prot-serConfig.cmake
    INSTALL_DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/prot-serConfigVersion.cmake
    VERSION ${PROJECT_VERSION}
    COMPATIBILITY SameMajorVersion
)

install(FILES
    ${CMAKE_CURRENT_BINARY_DIR}/prot-serConfig.cmake
    ${CMAKE_CURRENT_BINARY_DIR}/prot-serConfigVersion.cmake
    DESTINATION ${CMAKE_INSTALL_PREFIX}/cmake
)
