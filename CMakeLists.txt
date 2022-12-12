cmake_minimum_required(VERSION 3.20)
project(TOMLConfig VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# default options
option(WITH_TESTS "configure project with tests")
option(WITH_DOCS "configure project with doxygen docs")
option(BUILD_SHARED_LIBS "build as shared library")

# dependencies
find_package(toml11 3.7.1 REQUIRED)

# includes
if (WITH_TESTS)
    add_subdirectory(tests)
endif ()
if (WITH_DOCS)
    add_subdirectory(docs)
endif ()

# targets
add_library(
        lib
        src/utils/static_ptr.h
        src/resource/IResource.h
        src/resource/ResourceType.h
        src/resource/ResourceException.h
        src/resource/NullResource.cpp src/resource/NullResource.h
        src/resource/NodeResource.cpp src/resource/NodeResource.h
)

target_link_libraries(
        lib
        PUBLIC
        toml11::toml11
)

include(GNUInstallDirs)
target_include_directories(
        lib
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}/${CMAKE_PROJECT_NAME}-${CMAKE_PROJECT_VERSION}>
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}/src> # for tests
)

set(INSTALL_TARGETS lib)
include(cmake/install_targets.cmake)
