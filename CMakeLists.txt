cmake_minimum_required(VERSION 3.24)

project("LinAl"
        VERSION 2.0.0
        LANGUAGES CXX)

# Make all modules available to this project and other projects that consume this project by
# adding the cmake directory to the CMAKE_MODULE_PATH
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_LIST_DIR}/cmake)
include(warnings)
include(static_analysis)
include(cmake/CPM.cmake)
if (NOT CPM_SOURCE_CACHE AND EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/CPMSourceVariable.cmake")
    include(CPMSourceVariable.cmake)
endif ()

if (NOT CPM_SOURCE_CACHE)
    message(AUTHOR_WARNING "CPM_SOURCE_CACHE not set. The source files are downloaded for every build. This is not recommended.
        Set the CPM_SOURCE_CACHE variable to a directory of your choice to cache the cloned git repositories.
        Set the CPM_SOURCE_CACHE variable in CPMSourceVariable.cmake to keep your paths private.")
endif ()

if ((CMAKE_SOURCE_DIR STREQUAL CMAKE_CURRENT_SOURCE_DIR))
    option(LinAl_STATIC_ANALYSIS "" ON)
    option(LinAl_TESTS "" ON)
else ()
    option(LinAl_STATIC_ANALYSIS "" OFF)
    option(LinAl_TESTS "" ON)
endif ()
option(LinAl_INSTALL "Install project targets" ON)

add_subdirectory(src)

if (LinAl_TESTS)
    include(CTest)
    enable_testing()
    add_subdirectory(tests)
endif ()
