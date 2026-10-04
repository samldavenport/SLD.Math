cmake_minimum_required(VERSION 3.21)

project(SLD.Math VERSION 0.1.0 LANGUAGES CXX)

# exceptions are disabled, so drop the /EHsc that cmake adds by default
if(MSVC)
    string(REPLACE "/EHsc" "" CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif()

# SLD.Core is a submodule; skip it if a parent project already provides it
if(NOT TARGET SLD::Core)
    add_subdirectory(SLD.Core)
endif()

# SLD.Math is header only (SLD_MATH_API is inline), so there is nothing to link
add_library(sld_math INTERFACE)
add_library(SLD::Math ALIAS sld_math)

target_include_directories(sld_math INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# sld-math.hpp includes sld.hpp, so consumers need it too
target_link_libraries(sld_math INTERFACE SLD::Core)

target_compile_features(sld_math INTERFACE cxx_std_17)

# standalone builds compile sld-math.cpp so the headers get checked
if(PROJECT_IS_TOP_LEVEL)
    add_library(sld_math_check OBJECT)

    target_sources(sld_math_check PRIVATE
        src/sld-math.cpp
        include/sld-math.hpp
        include/sld-math-types.hpp
        include/sld-math-globals.hpp
        include/sld-math-vec2.hpp
        include/sld-math-vec3.hpp
        include/sld-math-mat3.hpp
        include/sld-math-mat4.hpp
        include/sld-math-xforms.hpp
    )

    target_include_directories(sld_math_check PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)

    target_link_libraries(sld_math_check PRIVATE SLD::Math)

    set_target_properties(sld_math_check PROPERTIES CXX_EXTENSIONS OFF)

    target_compile_definitions(sld_math_check PRIVATE _HAS_EXCEPTIONS=0)

    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_compile_options(sld_math_check PRIVATE /EHs-)
    endif()
endif()
