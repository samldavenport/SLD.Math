#pragma once

#include "sld-math.hpp"

namespace sld {

    SLD_MATH_API void
    vec3_add(
        const vec3* in_a, 
        const vec3* in_b,
        vec3*       out_c, 
        const u32   count) {

        assert(
            in_a  != NULL &&
            in_b  != NULL &&
            out_c != NULL &&
            count != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& a = in_a  [index];            
                const vec3& b = in_b  [index];            
                vec3&       c = out_c [index];            
        
                c.x = (a.x + b.x);
                c.y = (a.y + b.y);
                c.z = (a.z + b.z);
        }
    }

    SLD_MATH_API void
    vec3_sub(
        const vec3* in_a, 
        const vec3* in_b,
        vec3*       out_c, 
        const u32   count) {

        assert(
            in_a  != NULL &&
            in_b  != NULL &&
            out_c != NULL &&
            count != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& a = in_a  [index];            
                const vec3& b = in_b  [index];            
                vec3&       c = out_c [index];            
        
                c.x = (a.x - b.x);
                c.y = (a.y - b.y);
                c.z = (a.z - b.z);
        }
    }

    SLD_MATH_API void
    vec3_cross(
        const vec3* in_a,
        const vec3* in_b,
        vec3*       out_c,
        const u32   count) {

        assert(
            in_a  != NULL &&
            in_b  != NULL &&
            out_c != NULL &&
            count != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& a = in_a  [index];            
                const vec3& b = in_b  [index];            
                vec3&       c = out_c [index];            
        
                c.x = (a.y * b.z) - (a.z * b.y);
                c.y = (a.z * b.x) - (a.x * b.z);
                c.z = (a.x * b.y) - (a.y * b.x);
        }
    }

    SLD_MATH_API void
    vec3_scalar_mul(
        const vec3* in_v,
        const f32*  in_s,   
        vec3*       out_sv,
        const u32   count) {

        assert(
            in_v   != NULL &&
            in_s   != NULL &&
            out_sv != NULL &&
            count  != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& v  = in_v   [index];            
                const vec3& s  = in_s   [index];            
                vec3&       sv = out_sv [index];            
        
                sv.x = (s * v.x); 
                sv.y = (s * v.y);
                sv.z = (s * v.z);
        }
    }

    SLD_MATH_API void
    vec3_scalar_div(
        const vec3* in_v2,
        const f32*  s,   
        vec3*       out_v2,
        const u32   count) {

        assert(
            in_v   != NULL &&
            in_s   != NULL &&
            out_sv != NULL &&
            count  != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& v     = in_v    [index];            
                const vec3& s     = in_s    [index];            
                vec3&       sv    = out_sv  [index];            

                assert(s != 0);
                const f32   s_inv = (1 / s); 
                
                c.x = (s_inv * v.x); 
                c.y = (s_inv * v.y);
                c.z = (s_inv * v.z);
        }
    }

    SLD_MATH_API void
    vec3_dot(
        const vec3* in_a, 
        const vec3* in_b,
        f32*        out_d
        const u32   count) {

        assert(
            in_a  != NULL &&
            in_a  != NULL &&
            out_d != NULL &&
            count != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& a = in_a    [index];            
                const vec3& b = in_b    [index];            
                vec3&       d = out_sv  [index];            

                d = (
                    (a.x * b.x) +
                    (a.y * b.y) +
                    (a.z * b.z)
                );
        }
    }

    SLD_MATH_API void
    vec3_magnitude(
        const vec3* in_v,
        f32*        out_m,
        const u32   count) {

        assert(
            in_v   != NULL &&
            out_m  != NULL &&
            count  != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& v  = in_v  [index];            
                f32&        m  = out_m [index];            

                m = sqrtf(
                    powf(v.x, 2.0f) +
                    powf(v.y, 2.0f) +
                    powf(v.z, 2.0f)
                );
        }
    }

    SLD_MATH_API void
    vec3_normalize(
        const vec3* in_v,
        vec3*       out_vn,
        const u32   count) {

        assert(
            in_v   != NULL &&
            out_vn != NULL &&
            count  != 0
        );

        for (
            u32 index = 0;
                index < count;
              ++index) {

                const vec3& v     = in_v   [index];            
                vec3&       vn    = out_vn [index];            
                const u32   m     = sqrtf(powf(v.x, 2.0f) + powf(v.y, 2.0f));
                const uf32  m_inv = (1.0f / m);
                vn.x              = (m_inv * v.x);        
                vn.y              = (m_inv * v.y);        
                vn.z              = (m_inv * v.z);        
        }
    }

};