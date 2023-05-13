cmake_minimum_required(VERSION 3.19)

include(FetchContent)
FetchContent_Declare(twCMakeUtils
        GIT_REPOSITORY https://github.com/timow-gh/twCMakeUtils.git
        GIT_TAG main)
FetchContent_GetProperties(twCMakeUtils)
set(lcs_twCMakeUtils "")
string(TOLOWER "twCMakeUtils" lcs_twCMakeUtils)
if (NOT ${lcs_twCMakeUtils}_POPULATED)
    FetchContent_Populate(twCMakeUtils)

    # Adding CPM to the project
    set(utils_cmake_modules_path ${${lcs_twCMakeUtils}_SOURCE_DIR}/modules)
    include(${utils_cmake_modules_path}/CPM.cmake)
    if (NOT CPM_SOURCE_CACHE AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CPMSourceVariable.cmake")
        include(CPMSourceVariable.cmake)
    endif ()

    if (NOT CPM_SOURCE_CACHE)
        message(AUTHOR_WARNING "CPM_SOURCE_CACHE not set. The source files are downloaded for every build. This is not recommended.
        Set the CPM_SOURCE_CACHE variable to a directory of your choice to cache the cloned git repositories.
        Set the CPM_SOURCE_CACHE variable in CPMSourceVariable.cmake to keep your paths private.")
    endif ()

    list(APPEND CMAKE_MODULE_PATH ${utils_cmake_modules_path})
endif ()

project("LinAl"
        VERSION 0.1.0
        LANGUAGES CXX)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)

include(project_preamble)
include(setup_export_set_installation)

include(CPM)
if (NOT CPM_SOURCE_CACHE AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CPMSourceVariable.cmake")
    include(CPMSourceVariable.cmake)
endif ()

if (NOT CPM_SOURCE_CACHE)
    message(AUTHOR_WARNING "CPM_SOURCE_CACHE not set. The source files are downloaded for every build. This is not recommended.
        Set the CPM_SOURCE_CACHE variable to a directory of your choice to cache the cloned git repositories.
        Set the CPM_SOURCE_CACHE variable in CPMSourceVariable.cmake to keep your paths private.")
endif ()

if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    option(LinAl_BUILD_TESTS "LinAl: Enable tests" ON)
    option(LinAl_BUILD_BENCHMARKS "LinAl: Enable benchmarks" ON)
else ()
    option(LinAl_BUILD_TESTS "LinAl: Enable tests" OFF)
    option(LinAl_BUILD_BENCHMARKS "LinAl: Enable benchmarks" OFF)
endif ()
option(${PROJECT_NAME}_INSTALL "Install project targets" ON)

include(project_preamble)
project_preamble()

if (CMAKE_CXX_STANDARD)
    if (CMAKE_CXX_STANDARD LESS 17)
        message(FATAL_ERROR "LinAl requires C++17 or greater. CMAKE_CXX_STANDARD is set to ${CMAKE_CXX_STANDARD}.")
    endif ()
else ()
    message(FATAL_ERROR "CMAKE_CXX_STANDARD is not set. LinAl requires C++17 or greater.")
endif ()

add_subdirectory(dependencies)
add_subdirectory(src)

if (LinAl_BUILD_BENCHMARKS)
    add_subdirectory(benchmark)
endif ()

if (LinAl_BUILD_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif ()
