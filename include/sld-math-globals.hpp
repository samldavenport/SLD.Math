#ifndef SLD_MATH_GLOBALS_HPP
#define SLD_MATH_GLOBALS_HPP

#include <sld.hpp>
#include <sld-math-types.hpp>

// NOTE(SLD): these are based on opengl coordinate space
#define SLD_MATH_DEFAULT_GLOBAL_UP     {0.0f, 1.0f, 0.0f}
#define SLD_MATH_DEFAULT_GLOBAL_X_AXIS {1.0f, 0.0f, 0.0f}
#define SLD_MATH_DEFAULT_GLOBAL_Y_AXIS {0.0f, 1.0f, 0.0f}
#define SLD_MATH_DEFAULT_GLOBAL_Z_AXIS {0.0f, 0.0f, 1.0f}

namespace sld {

    //--------------------------------------------------------------------
    // CONSTANTS
    //--------------------------------------------------------------------

    constexpr f32 PI_32          = 3.1415926535f;
    constexpr f32 RADIANS_FACTOR = (PI_32 / 180.0f);
    constexpr f32 DEGREES_FACTOR = (180.f / PI_32);

    //--------------------------------------------------------------------
    // GLOBALS
    //--------------------------------------------------------------------

    static vec3 _global_up     = SLD_MATH_DEFAULT_GLOBAL_UP;
    static vec3 _global_x_axis = SLD_MATH_DEFAULT_GLOBAL_X_AXIS;
    static vec3 _global_y_axis = SLD_MATH_DEFAULT_GLOBAL_Y_AXIS;
    static vec3 _global_z_axis = SLD_MATH_DEFAULT_GLOBAL_Z_AXIS;

    //--------------------------------------------------------------------
    // INLINE METHODS
    //--------------------------------------------------------------------

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

#endif //SLD_MATH_GLOBALS_HPP