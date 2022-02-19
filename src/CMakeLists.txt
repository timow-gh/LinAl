set(linAl_HEADER
        include/LinAl/BlazeWrapper/LinAlBlaze.hpp
        include/LinAl/BlazeWrapper/BlazeVec.hpp
        include/LinAl/BlazeWrapper/BlazeMat.hpp
        include/LinAl/BlazeWrapper/BlazeContainers.hpp
        include/LinAl/BlazeWrapper/BlazeGlMatrix.hpp
        include/LinAl/BlazeWrapper/BlazeGlVec.hpp
        include/LinAl/BlazeWrapper/BlazeGlMatrixOperations.hpp
        include/LinAl/BlazeWrapper/BlazeMatOperations.hpp
        include/LinAl/BlazeWrapper/BlazeUtil.hpp
        include/LinAl/BlazeWrapper/BlazeVec2.hpp
        include/LinAl/BlazeWrapper/BlazeVec3.hpp
        include/LinAl/BlazeWrapper/BlazeVec4.hpp
        include/LinAl/BlazeWrapper/BlazeHMat.hpp
        include/LinAl/BlazeWrapper/BlazeHVec.hpp
        include/LinAl/BlazeWrapper/BlazeHMatOperations.hpp
        include/LinAl/LinearAlgebra.hpp
        include/LinAl/LinearAlgebraUtil.hpp)

set(linAl_SOURCES
        source/BlazeGlMatrixOperations.cpp)

add_library(Lin_Al ${linAl_HEADER} ${linAl_SOURCES})
target_include_directories(Lin_Al
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>
        $<BUILD_INTERFACE:${LinAl_BINARY_DIR}/src>)
target_link_libraries(Lin_Al
        PUBLIC
        Core::Settings
        Core::Utils
        Core::Math
        LinAlBase::LinAlBase
        )

add_library(LinAl::LinAl ALIAS Lin_Al)
set_target_properties(Lin_Al
        PROPERTIES
        SOVERSION ${PROJECT_VERSION_MAJOR}
        VERSION ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}.${PROJECT_VERSION_PATCH}
        DEBUG_POSTFIX d
        LINKER_LANGUAGE CXX
        EXPORT_NAME LinAl)
target_compile_features(Lin_Al INTERFACE cxx_std_17)

include(GenerateExportHeader)
generate_export_header(Lin_Al BASE_NAME LinAl)
include(CMakePackageConfigHelpers)

install(TARGETS Lin_Al
        EXPORT LinAlTargetsExportSet
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
        LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
        ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
        INCLUDES DESTINATION
        ${CMAKE_INSTALL_INCLUDEDIR}
        ${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME})

install(DIRECTORY "include/LinAl" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

string(TOLOWER "${PROJECT_NAME}_export.h" GENERATED_TARGET_EXPORTS_FILE)
install(FILES "${LinAl_BINARY_DIR}/src/${GENERATED_TARGET_EXPORTS_FILE}"
        DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")

setupExportSetInstall("${PROJECT_NAME}" "LinAlTargetsExportSet")
