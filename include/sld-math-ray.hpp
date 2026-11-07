
#ifndef SLD_MATH_PLANE_HPP
#define SLD_MATH_PLANE_HPP

#include "sld-math-types.hpp"
#include "sld-math-globals.hpp"
#include "sld-math-vec3.hpp"

namespace sld {

    // the point t along the ray, in units of the direction's length
    SLD_MATH_API vec3
    ray_get_point(
        const ray& r,
        const f32  t) {

        return(vec3_add(r.origin, vec3_scalar_multiply(r.direction, t)));
    }

    // where the ray hits the plane, from either side, ray_get_point(r, t) is the hit
    // false if the ray runs along the plane, or the plane is behind it
    SLD_MATH_API bool
    ray_intersect_plane(
        const ray&   r,
        const plane& p,
        f32&         t) {

        const f32 dir_dot_n = vec3_dot(p.normal, r.direction);
        if (fabsf(dir_dot_n) < EPSILON_32) return(false);

        const f32 hit = (p.distance - vec3_dot(p.normal, r.origin)) / dir_dot_n;
        if (hit < 0.0f) return(false);

        t = hit;
        return(true);
    }
};

#endif //SLD_MATH_PLANE_HPP
