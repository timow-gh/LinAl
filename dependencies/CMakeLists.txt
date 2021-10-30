include(FetchContent)
FetchContent_Declare(
        core
        GIT_REPOSITORY https://github.com/timow-gh/Core.git
        GIT_TAG main)

FetchContent_Declare(
        linalbase
        GIT_REPOSITORY https://github.com/timow-gh/LinAlBase.git
        GIT_TAG main)

add_subdirectory(core)
add_subdirectory(linalbase)