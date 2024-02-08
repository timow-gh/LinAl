set(linal_HEADER
        include/linal/policies/addition_policy.hpp
        include/linal/policies/subtraction_policy.hpp
        include/linal/policies/multiplication_policy.hpp
        include/linal/policies/division_policy.hpp
        include/linal/policies/comparison_policy.hpp
        include/linal/utils/assert.hpp
        include/linal/utils/compiler.hpp
        include/linal/utils/constants.hpp
        include/linal/utils/eps.hpp
        include/linal/utils/util.hpp
        include/linal/utils/warnings.hpp
        include/linal/array_type_traits.hpp
        include/linal/hmat.hpp
        include/linal/mat.hpp
        include/linal/mat_rot.hpp
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
