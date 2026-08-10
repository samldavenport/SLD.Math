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
            (a.x + b.x),
            (a.y + b.y),
            (a.z + b.z)
        };
        return(result);
    }

    inline vec3
    vec3_subtract(
        const vec3& a,
        const vec3& b) {

        const vec3 result = {
            (a.x - b.x),
            (a.y - b.y),
            (a.z - b.z)
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

        const f32   m     = vec3_magnitude(v);
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

    SLD_MATH_API void
    vec3_add(
        vec3*       o_v,
        const vec3* i_a,
        const vec3* i_b,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_add(
                i_a[index],
                i_b[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_subtract(
        vec3*       o_v,
        const vec3* i_a,
        const vec3* i_b,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_subtract(
                i_a[index],
                i_b[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_project(
        vec3*       o_v,
        const vec3* i_a,
        const vec3* i_b,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_project(
                i_a[index],
                i_b[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_reject(
        vec3*       o_v,
        const vec3* i_a,
        const vec3* i_b,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_reject(
                i_a[index],
                i_b[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_cross(
        vec3*       o_v,
        const vec3* i_a,
        const vec3* i_b,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_cross(
                i_a[index],
                i_b[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_scalar_multiply(
        vec3*       o_v,
        const vec3* i_v,
        const f32*  i_s,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_scalar_multiply(
                i_v[index],
                i_s[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_scalar_divide(
        vec3*       o_v,
        const vec3* i_v,
        const f32*  i_s,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_scalar_divide(
                i_v[index],
                i_s[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_dot(
        f32*        o_d,
        const vec3* i_a,
        const vec3* i_b,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_d[index] = vec3_dot(
                i_a[index],
                i_b[index]
            );
        }
    }

    SLD_MATH_API void
    vec3_magnitude(
        f32*        o_m,
        const vec3* i_v,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_m[index] = vec3_magnitude(i_v[index]);
        }
    }

    SLD_MATH_API void
    vec3_normalize(
        vec3*       o_v,
        const vec3* i_v,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_v[index] = vec3_normalize(i_v[index]);
        }
    }
};

#endif //VEC3_INL
