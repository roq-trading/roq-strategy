cmake_minimum_required(VERSION 3.12)

project(strategy)

if(DEFINED ENV{CONDA_PREFIX} AND NOT DEFINED ENV{CONDA_BUILD})
  set(CMAKE_INSTALL_PREFIX $ENV{CONDA_PREFIX})
  set(CMAKE_FIND_ROOT_PATH $ENV{CONDA_PREFIX})
endif()

set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

include(GNUInstallDirs)

find_package(absl REQUIRED)
find_package(fmt REQUIRED)
find_package(roq-api REQUIRED)
find_package(roq-client REQUIRED)
find_package(roq-logging REQUIRED)

include_directories("${CMAKE_SOURCE_DIR}/src")

add_subdirectory("${CMAKE_CURRENT_SOURCE_DIR}/src")

# test

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  include(CTest)
endif()

find_package(Catch2 REQUIRED)

find_package(PkgConfig REQUIRED)                                                                                        
                                                                                                                        
pkg_check_modules(MLPACK REQUIRED mlpack)

add_subdirectory("${CMAKE_SOURCE_DIR}/test")

# benchmark

find_package(benchmark REQUIRED)

add_subdirectory("${CMAKE_SOURCE_DIR}/benchmark")
