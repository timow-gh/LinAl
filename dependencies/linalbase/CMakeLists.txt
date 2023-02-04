CPMAddPackage(
        NAME LinAlBase
        GITHUB_REPOSITORY "timow-gh/LinAlBase"
        GIT_TAG main
        GIT_SHALLOW TRUE
        OPTIONS
        "LinAlBase_INSTALL ${${PROJECT_NAME}_INSTALL}"
)