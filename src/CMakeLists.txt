set(linAl_HEADER
    include/LinAl/BlazeWrapper/LinAlBlaze.hpp
    include/LinAl/BlazeWrapper/BlazeVector.hpp
    include/LinAl/BlazeWrapper/BlazeMatrix.hpp
    include/LinAl/BlazeWrapper/BlazeContainers.hpp
    include/LinAl/BlazeWrapper/BlazeGlMatrix.hpp
    include/LinAl/BlazeWrapper/BlazeGlVector.hpp
    include/LinAl/BlazeWrapper/BlazeGlMatrixOperations.hpp
    include/LinAl/BlazeWrapper/BlazeMatrixTransformations.hpp
    include/LinAl/BlazeWrapper/BlazeMatrixOperations.hpp
    include/LinAl/BlazeWrapper/BlazeMatrixConversions.hpp
    include/LinAl/LinearAlgebra.hpp
    include/LinAl/LinearAlgebraUtil.hpp
    include/LinAl/BlazeWrapper/BlazeUtil.hpp)

set(linAl_SOURCES
    source/BlazeGlMatrixOperations.cpp)

include(Warnings)

add_library(Lin_Al ${linAl_SOURCES})
target_include_directories(Lin_Al
                           PUBLIC
                           $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
                           $<BUILD_INTERFACE:${PROJECT_BINARY_DIR}>
                           # Make blaze headers visible
                           $<BUILD_INTERFACE:${CMAKE_INSTALL_PREFIX}/${CMAKE_INSTALL_INCLUDEDIR}>
                           )
target_link_libraries(Lin_Al INTERFACE blaze::blaze OpenBLAS::OpenBLAS)
set(TARGET_ALIAS LinAl)
add_library(${PROJECT_NAME}::${TARGET_ALIAS} ALIAS Lin_Al)
set_target_properties(Lin_Al
                      PROPERTIES
                      SOVERSION ${PROJECT_VERSION_MAJOR}
                      VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
                      DEBUG_POSTFIX d
                      LINKER_LANGUAGE CXX
                      EXPORT_NAME ${TARGET_ALIAS})
target_set_warnings(Lin_Al ENABLE ALL AS_ERROR ALL DISABLE Annoying)
if (MSVC)
    include(HelperFunctions)
    setMSVCOutputDirectories(Lin_Al)
endif ()

include(GenerateExportHeader)
generate_export_header(Lin_Al BASE_NAME ${PROJECT_NAME})

if (${PROJECT_NAME}_INSTALL)
    include(CMakePackageConfigHelpers)

    install(DIRECTORY "include/LinAl" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

    string(TOLOWER "${PROJECT_NAME}_export.h" GENERATED_TARGET_EXPORTS_FILE)
    install(FILES "${PROJECT_BINARY_DIR}/${GENERATED_TARGET_EXPORTS_FILE}"
            DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")

    install(TARGETS Lin_Al EXPORT
            LinAlTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION
            ${CMAKE_INSTALL_INCLUDEDIR}
            ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

    set(${PROJECT_NAME}_INSTALL_CMAKEDIR
        "${CMAKE_INSTALL_LIBDIR}/cmake/${PROJECT_NAME}"
        CACHE STRING "Path to install ${PROJECT_NAME} Config*.cmake files to.")
    set(${PROJECT_NAME}_MODULE_INSTALL_DIR
        "${CMAKE_INSTALL_LIBDIR}/cmake"
        CACHE STRING "Path to install ${PROJECT_NAME}'s .cmake  module files to.")

    install(EXPORT LinAlTargetsExportSet
            NAMESPACE ${PROJECT_NAME}::
            FILE ${PROJECT_NAME}Targets.cmake
            DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})

    write_basic_package_version_file(
            ${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
            VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
            COMPATIBILITY SameMajorVersion)

    configure_package_config_file(
            ${PROJECT_SOURCE_DIR}/cmake/Config.cmake.in
            ${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake
            INSTALL_DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR}
            PATH_VARS ${PROJECT_NAME}_MODULE_INSTALL_DIR
            NO_SET_AND_CHECK_MACRO
            NO_CHECK_REQUIRED_COMPONENTS_MACRO)

    install(FILES
            "${PROJECT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
            "${PROJECT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
            DESTINATION ${${PROJECT_NAME}_INSTALL_CMAKEDIR})
endif ()