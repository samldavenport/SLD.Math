#ifndef SLD_MATH_VEC3_HPP
#define SLD_MATH_VEC3_HPP

#include <sld-math.hpp>
namespace sld {

    //--------------------------------------------------------------------
    // REFERENCE METHODS 
    //--------------------------------------------------------------------

    inline vec3
    vec3_add(
        const vec3& a,
        const vec3& b) {

        const vec3 result = {
            (a.x + a.x),
            (a.y + a.y),
            (a.z + a.z)
        };
        return(result);
    }

    inline vec3
    vec3_subtract(
        const vec3& a,
        const vec3& b) {

        const vec3 result = {
            (a.x - a.x),
            (a.y - a.y),
            (a.z - a.z)
        };
        return(result);
    }

    inline vec3
    vec3_project(
        const vec3& a,
        const vec3& b) {

        const f32   dot_ab = ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
        const f32   dot_bb = ((b.x * b.x) + (b.y * b.y) + (b.z * b.z));
        const f32   scalar = (dot_ab / dot_bb);
        
        const vec3 result = {
            (scalar * b.x), 
            (scalar * b.y), 
            (scalar * b.z) 
        };

        return(result);
    }

    inline vec3
    vec3_reject(
        const vec3& a,
        const vec3& b) {

        const f32   dot_ab   = ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
        const f32   dot_bb   = ((b.x * b.x) + (b.y * b.y) + (b.z * b.z));
        const f32   scalar   = (dot_ab / dot_bb);
        const vec3  scalar_b = { (scalar * b.x),     (scalar * b.y),     (scalar * b.z)     }; 
        const vec3  result   = { (a.x - scalar_b.x), (a.y - scalar_b.y), (a.z - scalar_b.z) };

        return(result);        
    }

    inline vec3
    vec3_cross(
        const vec3& a,
        const vec3& b) {

        const vec3 result = {
            (a.y * b.z) - (a.z * b.y),
            (a.z * b.x) - (a.x * b.z),
            (a.x * b.y) - (a.y * b.x)
        };
        return(result);
    }



    inline vec3
    vec3_scalar_multiply(
        const vec3& v,
        const f32   s) {

        const vec3 result = {
            (v.x * s),
            (v.y * s),
            (v.z * s)
        };
        return(result);
    }

    inline vec3
    vec3_scalar_divide(
        const vec3& v,
        const f32   s) {

        assert(s != 0);

        const f32  s_inv  = (1.0f / s);
        const vec3 result = {
            (v.x * s_inv),
            (v.y * s_inv),
            (v.z * s_inv)
        };
        return(result);
    }

    inline f32
    vec3_dot(
        const vec3& a,
        const vec3& b) {

        const f32 result = (
            (a.x * b.x) +
            (a.y * b.y) +
            (a.z * b.z)
        );
        return(result);
    }

    inline f32
    vec3_magnitude(
        const vec3& v) {

        const f32 result = sqrtf(
            powf(v.x, 2.0f) +
            powf(v.y, 2.0f) +
            powf(v.z, 2.0f)
        );
        return(result);
    }

    inline vec3
    vec3_normalize(
        const vec3& v) {

        const f32   m     = sqrtf(powf(v.x, 2.0f) + powf(v.y, 2.0f));
        const f32   m_inv = (1.0f / m);
        const vec3  result = {
            (m_inv * v.x),        
            (m_inv * v.y),        
            (m_inv * v.z)   
        };
        return(result);
    }

    //--------------------------------------------------------------------
    // POINTER METHODS 
    //--------------------------------------------------------------------

};

#endif //VEC3_INL