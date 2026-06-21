#pragma once

#include "sld-math.hpp"

namespace sld {

    SLD_MATH_API void
    vec3_add(
        vec3*       o_c, 
        const vec3* i_a, 
        const vec3* i_b,
        const u32   i_count) {

        assert(
            o_c   != NULL &&
            i_a   != NULL &&
            i_b   != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& a = i_a [index];            
                const vec3& b = i_b [index];            
                vec3&       c = o_c [index];            
                c.x           = (a.x + b.x);
                c.y           = (a.y + b.y);
                c.z           = (a.z + b.z);
        }
    }

    SLD_MATH_API void
    vec3_sub(
        vec3*       o_c, 
        const vec3* i_a, 
        const vec3* i_b,
        const u32   i_count) {

        assert(
            o_c   != NULL &&
            i_a   != NULL &&
            i_b   != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& a = i_a [index];            
                const vec3& b = i_b [index];            
                vec3&       c = o_c [index];            
                c.x           = (a.x - b.x);
                c.y           = (a.y - b.y);
                c.z           = (a.z - b.z);
        }
    }

    SLD_MATH_API void
    vec3_cross(
        vec3*       o_c,
        const vec3* i_a,
        const vec3* i_b,
        const u32   i_count) {

        assert(
            i_a   != NULL &&
            i_b   != NULL &&
            o_c   != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& a = i_a [index];            
                const vec3& b = i_b [index];            
                vec3&       c = o_c [index];            
                c.x           = (a.y * b.z) - (a.z * b.y);
                c.y           = (a.z * b.x) - (a.x * b.z);
                c.z           = (a.x * b.y) - (a.y * b.x);
        }
    }


    SLD_MATH_API void
    vec3_proj(
        vec3*       o_c, 
        const vec3* i_a, 
        const vec3* i_b,
        const u32   i_count) {

        assert(
            o_c     != NULL &&
            i_a     != NULL &&
            i_b     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& a      = i_a [index];            
                const vec3& b      = i_b [index];            
                vec3&       c      = o_c [index];            
                const f32   dot_ab = ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
                const f32   dot_bb = ((b.x * b.x) + (b.y * b.y) + (b.z * b.z));
                const f32   scalar = (dot_ab / dot_bb);
                c.x                = (scalar * b.x); 
                c.y                = (scalar * b.y); 
                c.z                = (scalar * b.z); 
        }
    }

    SLD_MATH_API void
    vec3_rej(
        vec3*       o_c, 
        const vec3* i_a, 
        const vec3* i_b,
        const u32   i_count) {

        assert(
            i_a     != NULL &&
            i_b     != NULL &&
            o_c     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& a        = i_a  [index];            
                const vec3& b        = i_b  [index];            
                vec3&       c        = o_c [index];            
                const f32   dot_ab   = ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
                const f32   dot_bb   = ((b.x * b.x) + (b.y * b.y) + (b.z * b.z));
                const f32   scalar   = (dot_ab / dot_bb);
                const vec3  scalar_b = { (scalar * b.x), (scalar * b.y), (scalar * b.z) }; 
                c.x                  = (a.x - scalar_b.x); 
                c.y                  = (a.y - scalar_b.y); 
                c.y                  = (a.z - scalar_b.z); 
        }
    }

    SLD_MATH_API void
    vec3_scalar_mul(
        vec3*       o_sv,
        const vec3* i_v,
        const f32*  i_s,   
        const u32   i_count) {

        assert(
            i_v     != NULL &&
            i_s     != NULL &&
            o_sv    != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& v  = i_v  [index];            
                const f32&  s  = i_s  [index];            
                vec3&       sv = o_sv [index];            
                sv.x           = (s * v.x); 
                sv.y           = (s * v.y);
                sv.z           = (s * v.z);
        }
    }

    SLD_MATH_API void
    vec3_scalar_div(
        vec3*       o_v,
        const vec3* i_v,
        const f32*  i_s,   
        const u32   i_count) {

        assert(
            o_v     != NULL &&
            i_v     != NULL &&
            i_s     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& v   = i_v [index];            
                const f32&  s   = i_s [index];            
                vec3&       sv  = o_v [index];            

                assert(s != 0);

                const f32 s_inv = (1 / s); 
                sv.x             = (s_inv * v.x); 
                sv.y             = (s_inv * v.y);
                sv.z             = (s_inv * v.z);
        }
    }

    SLD_MATH_API void
    vec3_dot(
        f32*        o_d,
        const vec3* i_a, 
        const vec3* i_b,
        const u32   i_count) {

        assert(
            o_d     != NULL &&
            i_a     != NULL &&
            i_a     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& a = i_a [index];            
                const vec3& b = i_b [index];            
                f32&        d = o_d [index];            

                d = (
                    (a.x * b.x) +
                    (a.y * b.y) +
                    (a.z * b.z)
                );
        }
    }


    SLD_MATH_API void
    vec3_transform_mat3(
        vec3*       o_t,
        const vec3* i_v,
        const mat3* i_m,
        const u32   i_count) {

        assert(
            o_t     != NULL && 
            i_v     != NULL && 
            i_m     != NULL && 
            i_count != 0         
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            vec3&       t = o_t[index];
            const vec3& v = i_v[index];
            const mat3& m = i_m[index];
        
            t.x = (m.r0c0 * v.x) + (m.r0c1 * v.y) + (m.r0c2 * v.z);  
            t.y = (m.r1c0 * v.x) + (m.r1c1 * v.y) + (m.r1c2 * v.z); 
            t.z = (m.r2c0 * v.x) + (m.r2c1 * v.y) + (m.r2c2 * v.z); 
        }
    }

    SLD_MATH_API void
    vec3_transform_mat4(
        vec3*       o_t,
        const vec3* i_v,
        const mat4* i_m,
        const u32   i_count) {

        assert(
            o_t     != NULL && 
            i_v     != NULL && 
            i_m     != NULL && 
            i_count != 0         
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            vec3&       t = o_t[index];
            const vec3& v = i_v[index];
            const mat4& m = i_m[index];
        
            t.x = (m.r0c0 * v.x) + (m.r0c1 * v.y) + (m.r0c2 * v.z);  
            t.y = (m.r1c0 * v.x) + (m.r1c1 * v.y) + (m.r1c2 * v.z); 
            t.z = (m.r2c0 * v.x) + (m.r2c1 * v.y) + (m.r2c2 * v.z); 
        }
    }

    SLD_MATH_API void
    vec3_magnitude(
        f32*        o_m,
        const vec3* i_v,
        const u32   i_count) {

        assert(
            o_m     != NULL &&
            i_v     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& v = i_v [index];            
                f32&        m = o_m [index];            

                m = sqrtf(
                    powf(v.x, 2.0f) +
                    powf(v.y, 2.0f) +
                    powf(v.z, 2.0f)
                );
        }
    }

    SLD_MATH_API void
    vec3_normalize(
        vec3*       o_vn,
        const vec3* i_v,
        const u32   i_count) {

        assert(
            o_vn    != NULL &&
            i_v     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec3& v     = i_v  [index];            
                vec3&       vn    = o_vn [index];            
                const u32   m     = sqrtf(powf(v.x, 2.0f) + powf(v.y, 2.0f));
                const f32   m_inv = (1.0f / m);
                vn.x              = (m_inv * v.x);        
                vn.y              = (m_inv * v.y);        
                vn.z              = (m_inv * v.z);        
        }
    }
};