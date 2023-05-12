set(linAl_blayewrapper_HEADER
        include/LinAl/BlazeWrapper/BlazeVec.hpp
        include/LinAl/BlazeWrapper/BlazeMat.hpp
        include/LinAl/BlazeWrapper/BlazeContainers.hpp
        include/LinAl/BlazeWrapper/BlazeMatOperations.hpp
        include/LinAl/BlazeWrapper/BlazeUtil.hpp
        include/LinAl/BlazeWrapper/BlazeVec2.hpp
        include/LinAl/BlazeWrapper/BlazeVec3.hpp
        include/LinAl/BlazeWrapper/BlazeVec4.hpp
        include/LinAl/BlazeWrapper/BlazeHMat.hpp
        include/LinAl/BlazeWrapper/BlazeHVec.hpp
        include/LinAl/BlazeWrapper/BlazeVecOperations.hpp
        include/LinAl/BlazeWrapper/BlazeHMatOperations.hpp
        include/LinAl/Utils/Eps.hpp
        include/LinAl/Utils/Warnings.hpp
        )

set(linAl_HEADER
        )


add_library(Lin_Al INTERFACE ${linAl_HEADER} ${linAl_blayewrapper_HEADER})
target_include_directories(Lin_Al
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
set(TARGET_ALIAS LinAl)
set_target_properties(Lin_Al
        PROPERTIES
        DEBUG_POSTFIX d
        LINKER_LANGUAGE CXX
        EXPORT_NAME ${TARGET_ALIAS})
target_link_libraries(Lin_Al
        INTERFACE
        Core::Utils
        Core::Math
        LinAlBase::LinAlBase)

add_library(${TARGET_ALIAS}::${TARGET_ALIAS} ALIAS Lin_Al)

if (${PROJECT_NAME}_INSTALL)
    install(FILES ${linAl_HEADER} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")
    install(FILES ${linAl_blayewrapper_HEADER} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}/BlazeWrapper")

    install(TARGETS Lin_Al
            EXPORT LinAlTargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    setup_export_set_installation(
            "LinAl"
            "LinAlTargetsExportSet"
            Config.cmake.in
            ${PROJECT_VERSION_MAJOR} ${PROJECT_VERSION_MINOR} ${PROJECT_VERSION_PATCH}
    )
endif ()

