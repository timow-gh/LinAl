set(linal_HEADER
        include/linal/policies/addition_policy.hpp
        include/linal/policies/subtraction_policy.hpp
        include/linal/policies/multiplication_policy.hpp
        include/linal/policies/division_policy.hpp
        include/linal/policies/element_access_policy.hpp
        include/linal/policies/comparison_policy.hpp
        include/linal/utils/assert.hpp
        include/linal/utils/compiler.hpp
        include/linal/utils/constants.hpp
        include/linal/utils/eps.hpp
        include/linal/utils/print_mat.hpp
        include/linal/utils/util.hpp
        include/linal/utils/warnings.hpp
        include/linal/array_type_traits.hpp
        include/linal/hmat.hpp
        include/linal/linal.hpp
        include/linal/mat.hpp
        include/linal/mat_operations.hpp
        include/linal/mat_rot.hpp
        include/linal/mat_transposed_type_trait.hpp
        include/linal/vec.hpp
        include/linal/vec_compare.hpp
        include/linal/vec_operations.hpp
)

set(TARGET_NAME Lin_Al)
add_library(${TARGET_NAME} INTERFACE ${linal_HEADER})
target_include_directories(${TARGET_NAME} INTERFACE $<BUILD_INTERFACE:${CMAKE_CURRENT_LIST_DIR}/include>)
set(TARGET_ALIAS linal)
set_target_properties(${TARGET_NAME}
        PROPERTIES
        LINKER_LANGUAGE CXX
        EXPORT_NAME ${TARGET_ALIAS})

add_library(${TARGET_ALIAS}::${TARGET_ALIAS} ALIAS ${TARGET_NAME})

add_warnings_and_compile_options(${TARGET_NAME} "${${PROJECT_NAME}_WARNINGS_AS_ERRORS}")
if (${${PROJECT_NAME}_STATIC_ANALYSIS})
    enable_static_analysis(${TARGET_NAME} "${${PROJECT_NAME}_WARNINGS_AS_ERRORS}")
endif ()

if (LinAl_INSTALL)
    include(setup_export_set_installation)

    set(project_export_set_name "${PROJECT_NAME}TargetsExportSet")

    install(DIRECTORY "include/${TARGET_NAME}" DESTINATION "${CMAKE_INSTALL_INCLUDEDIR}")

    install(TARGETS
            ${TARGET_NAME}
            EXPORT ${project_export_set_name}
            INCLUDES DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})

    setup_export_set_installation(
            ${PROJECT_NAME}
            ${project_export_set_name}
            Config.cmake.in
            ${PROJECT_VERSION_MAJOR} ${PROJECT_VERSION_MINOR} ${PROJECT_VERSION_PATCH}
    )
endif ()