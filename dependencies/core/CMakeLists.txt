CPMAddPackage(
        NAME Core
        GITHUB_REPOSITORY "timow-gh/Core"
        GIT_TAG dev
        GIT_SHALLOW TRUE
        OPTIONS
        "Core_INSTALL ${${PROJECT_NAME}_INSTALL}"
)