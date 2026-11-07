#ifndef SLD_MATH_PLANE_HPP
#define SLD_MATH_PLANE_HPP

#include "sld-math-types.hpp"
#include "sld-math-globals.hpp"
#include "sld-math-vec3.hpp"

namespace sld {

    //--------------------------------------------------------------------
    // PLANE
    //--------------------------------------------------------------------

    // the plane through a point, facing along normal, which doesn't have to be unit length
    SLD_MATH_API plane
    plane_from_point_normal(
        const vec3& point,
        const vec3& normal) {

        plane result;
        result.normal   = vec3_normalize(normal);
        result.distance = vec3_dot(result.normal, point);
        return(result);
    }

    // the plane through three points, facing the side they wind counter-clockwise from
    // the points can't be on one line
    SLD_MATH_API plane
    plane_from_points(
        const vec3& a,
        const vec3& b,
        const vec3& c) {

        const vec3 ab = vec3_subtract(b, a);
        const vec3 ac = vec3_subtract(c, a);
        return(plane_from_point_normal(a, vec3_cross(ab, ac)));
    }

    // the same plane with a unit normal, so plane_signed_distance gives world units
    SLD_MATH_API plane
    plane_normalize(
        const plane& p) {

        const f32 m_inv = (1.0f / vec3_magnitude(p.normal));

        plane result;
        result.normal   = vec3_scalar_multiply(p.normal, m_inv);
        result.distance = (p.distance * m_inv);
        return(result);
    }

    // how far a point is in front of the plane, negative behind it
    // in world units with a unit normal, otherwise scaled by the normal's length
    SLD_MATH_API f32
    plane_signed_distance(
        const plane& p,
        const vec3&  point) {

        return(vec3_dot(p.normal, point) - p.distance);
    }

    // the point on the plane closest to a point, the plane needs a unit normal
    SLD_MATH_API vec3
    plane_project_point(
        const plane& p,
        const vec3&  point) {

        const f32 d = plane_signed_distance(p, point);
        return(vec3_subtract(point, vec3_scalar_multiply(p.normal, d)));
    }

    // the one point on all three planes, which don't need unit normals
    // false if two of them are parallel, or they meet in a line
    SLD_MATH_API bool
    plane_intersect_planes(
        const plane& a,
        const plane& b,
        const plane& c,
        vec3&        point) {

        const vec3 b_cross_c = vec3_cross(b.normal, c.normal);
        const f32  det       = vec3_dot(a.normal, b_cross_c);
        if (fabsf(det) < EPSILON_32) return(false);

        // (a.d * (b x c) + b.d * (c x a) + c.d * (a x b)) / (a . (b x c))
        const vec3 c_cross_a = vec3_cross(c.normal, a.normal);
        const vec3 a_cross_b = vec3_cross(a.normal, b.normal);
        const vec3 sum       = vec3_add(
            vec3_add(
                vec3_scalar_multiply(b_cross_c, a.distance),
                vec3_scalar_multiply(c_cross_a, b.distance)
            ),
            vec3_scalar_multiply(a_cross_b, c.distance)
        );

        point = vec3_scalar_multiply(sum, (1.0f / det));
        return(true);
    }
};

#endif //SLD_MATH_PLANE_HPP
