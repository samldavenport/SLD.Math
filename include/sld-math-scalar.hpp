#ifndef SLD_MATH_SCALAR_HPP
#define SLD_MATH_SCALAR_HPP

#include "sld-math-types.hpp"

namespace sld {

    // v kept between min and max, assumes min <= max
    SLD_MATH_API f32
    math_clamp(
        const f32 v,
        const f32 min,
        const f32 max) {

        if (v < min) return(min);
        if (v > max) return(max);
        return(v);
    }

    // a at t = 0, b at t = 1, t isn't clamped
    SLD_MATH_API f32
    math_lerp(
        const f32 a,
        const f32 b,
        const f32 t) {

        return(a + ((b - a) * t));
    }
};

#endif //SLD_MATH_SCALAR_HPP
