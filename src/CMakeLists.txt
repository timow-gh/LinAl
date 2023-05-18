set(linal_HEADER
        include/linal/utils/assert.hpp
        include/linal/utils/compiler.hpp
        include/linal/utils/constants.hpp
        include/linal/utils/Eps.hpp
        include/linal/utils/util.hpp
        include/linal/utils/warnings.hpp
        include/linal/vec.hpp
        include/linal/mat.hpp
        include/linal/containers.hpp
        include/linal/mat_rot.hpp
        include/linal/hmat_translation.hpp
        include/linal/vec2.hpp
        include/linal/vec3.hpp
        include/linal/vec4.hpp
        include/linal/hmat.hpp
        include/linal/hvec.hpp
        include/linal/vec_operations.hpp
        include/linal/hmat_rotation.hpp
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

