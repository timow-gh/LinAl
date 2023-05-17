set(linal_HEADER
        include/linal/utils/Assert.hpp
        include/linal/utils/Compiler.hpp
        include/linal/utils/Constants.hpp
        include/linal/utils/Eps.hpp
        include/linal/utils/Util.hpp
        include/linal/utils/Warnings.hpp
        include/linal/Vec.hpp
        include/linal/Mat.hpp
        include/linal/Containers.hpp
        include/linal/MatRotation.hpp
        include/linal/HMatTranslation.hpp
        include/linal/Vec2.hpp
        include/linal/Vec3.hpp
        include/linal/Vec4.hpp
        include/linal/HMat.hpp
        include/linal/HVec.hpp
        include/linal/VecOperations.hpp
        include/linal/HMatRotation.hpp
        )

set(TARGET_NAME Lin_Al)
add_library(${TARGET_NAME} INTERFACE ${linal_HEADER})
target_include_directories(${TARGET_NAME}
        INTERFACE
        $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
set(TARGET_ALIAS linal)
set_target_properties(${TARGET_NAME}
        PROPERTIES
        DEBUG_POSTFIX d
        LINKER_LANGUAGE CXX
        EXPORT_NAME ${TARGET_ALIAS})
target_link_libraries(Lin_Al
        INTERFACE
        LinAlBase::LinAlBase)

add_library(${TARGET_ALIAS}::${TARGET_ALIAS} ALIAS ${TARGET_NAME})

if (${PROJECT_NAME}_INSTALL)
    install(FILES ${linal_HEADER} DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}/${PROJECT_NAME}")

    install(TARGETS ${TARGET_NAME}
            EXPORT ${TARGET_ALIAS}TargetsExportSet
            RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}
            LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
            ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    setup_export_set_installation(
            "${PROJECT_NAME}"
            "${TARGET_ALIAS}TargetsExportSet"
            Config.cmake.in
            ${PROJECT_VERSION_MAJOR} ${PROJECT_VERSION_MINOR} ${PROJECT_VERSION_PATCH}
    )
endif ()

