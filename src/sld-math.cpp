#pragma once

#define SLD_MATH_DLL_EXPORT

#include "vec2.cpp"
#include "vec3.cpp"
#include "mat3.cpp"
#include "mat4.cpp"
#include "transforms.cpp"

namespace sld {

    static vec3 _global_up     = SLD_MATH_DEFAULT_GLOBAL_UP;
    static vec3 _global_x_axis = SLD_MATH_DEFAULT_GLOBAL_X_AXIS;
    static vec3 _global_y_axis = SLD_MATH_DEFAULT_GLOBAL_Y_AXIS;
    static vec3 _global_z_axis = SLD_MATH_DEFAULT_GLOBAL_Z_AXIS;

    SLD_MATH_API void
    math_set_global_up(
        const vec3& up) {

        _global_up = up;
    }

    SLD_MATH_API void
    math_set_global_x_axis(
        const vec3& x_axis) {

        _global_x_axis = x_axis;
    }

    SLD_MATH_API void
    math_set_global_y_axis(
        const vec3& y_axis) {

        _global_y_axis = y_axis;
    }

    SLD_MATH_API void
    math_set_global_z_axis(
        const vec3& z_axis) {

        _global_z_axis = z_axis;
    }

        
    SLD_MATH_API const vec3&
    math_get_global_up(
        void) {

        return(_global_up);
    }

    SLD_MATH_API const vec3&
    math_set_global_x_axis(
        void) {

        return(_global_x_axis);
    }

    SLD_MATH_API const vec3&
    math_set_global_y_axis(
        void) {

        return(_global_y_axis);
    }

    SLD_MATH_API const vec3&
    math_set_global_z_axis(
        void) {

        return(_global_z_axis);
    }
};
