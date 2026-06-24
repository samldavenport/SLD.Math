#pragma once

#define SLD_MATH_DLL_EXPORT

#include "vec2.cpp"
#include "vec3.cpp"
#include "mat3.cpp"
#include "mat4.cpp"
#include "transforms.cpp"

namespace sld {

    static vec3 _global_up(0.0f, 1.0f, 0.0f);

    SLD_MATH_API void
    math_set_global_up(
        const vec3& up) {

        _global_up = up;
    }
        
    SLD_MATH_API const vec3&
    math_get_global_up(
        void) {

        return(_global_up);
    }
};
