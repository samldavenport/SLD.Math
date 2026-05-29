#pragma once

#include "sld-math.hpp"

namespace sld {

    SLD_MATH_API void
    vec2_add(
        const vec2* in_a, 
        const vec2* in_b,
        vec2*       out_c, 
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

                const vec2& a = in_a  [index];            
                const vec2& b = in_b  [index];            
                vec2&       c = out_c [index];            
        
                c.x = a.x + b.x;
                c.y = a.y + b.y;
        }
    }

    SLD_MATH_API void
    vec2_sub(
        const vec2* in_a, 
        const vec2* in_b,
        vec2*       out_c, 
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

                const vec2& a = in_a  [index];            
                const vec2& b = in_b  [index];            
                vec2&       c = out_c [index];            
        
                c.x = a.x - b.x;
                c.y = a.y - b.y;
        }
    }

    SLD_MATH_API void
    vec2_proj(
        const vec2* in_a, 
        const vec2* in_b,
        vec2*       out_c, 
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

                const vec2& a = in_a  [index];            
                const vec2& b = in_b  [index];            
                vec2&       c = out_c [index];            
        
                const f32 dot_ab = ((a.x * b.x) + (a.y * b.y));
                const f32 dot_bb = ((b.x * b.x) + (b.y * b.y));
                const f32 scalar = (dot_ab / dot_bb);

                c.x = (scalar * b.x); 
                c.y = (scalar * b.y); 
        }
    }

    SLD_MATH_API void
    vec2_rej(
        const vec2* in_a, 
        const vec2* in_b,
        vec2*       out_c, 
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

                const vec2& a        = in_a  [index];            
                const vec2& b        = in_b  [index];            
                vec2&       c        = out_c [index];            
                const f32   dot_ab   = ((a.x * b.x) + (a.y * b.y));
                const f32   dot_bb   = ((b.x * b.x) + (b.y * b.y));
                const f32   scalar   = (dot_ab / dot_bb);
                const vec2  scalar_b = { (scalar * b.x), (scalar * b.y) }; 
                c.x                  = (a.x - scalar_b.x); 
                c.y                  = (a.y - scalar_b.y); 
        }
    }

    SLD_MATH_API void
    vec2_scalar_mul(
        const vec2* in_v,
        const f32*  in_s,   
        vec2*       out_sv,
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

                const vec2& v  = in_v   [index];            
                const vec2& s  = in_s   [index];            
                vec2&       sv = out_sv [index];            
        
                c.x = s * v.x; 
                c.y = s * v.y;
        }
    }

    SLD_MATH_API void
    vec2_scalar_div(
        const vec2* in_v2,
        const f32*  s,   
        vec2*       out_v2,
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

                const vec2& v     = in_v    [index];            
                const vec2& s     = in_s    [index];            
                vec2&       sv    = out_sv  [index];            

                assert(s != 0);
                const f32   s_inv = (1 / s); 
                
                c.x = s_inv * v.x; 
                c.y = s_inv * v.y;
        }
    }

    SLD_MATH_API void
    vec2_dot(
        const vec2* in_a, 
        const vec2* in_b,
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

                const vec2& a = in_a    [index];            
                const vec2& b = in_b    [index];            
                vec2&       d = out_sv  [index];            

                d = (
                    (a.x * b.x) + (a.y * b.y);
                );
        }
    }

    SLD_MATH_API void
    vec2_magnitude(
        const vec2* in_v,
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

                const vec2& v  = in_v  [index];            
                f32&        m  = out_m [index];            

                m = sqrtf(
                    powf(v.x, 2.0f) +
                    powf(v.y, 2.0f)
                );
        }
    }

    SLD_MATH_API void
    vec2_normalize(
        const vec2* in_v,
        vec2*       out_vn,
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

                const vec2& v     = in_v   [index];            
                vec2&       vn    = out_vn [index];            
                const u32   m     = sqrtf(powf(v.x, 2.0f) + powf(v.y, 2.0f));
                const uf32  m_inv = (1.0f / m);
                vn.x              = (m_inv * v.x);        
                vn.y              = (m_inv * v.y);        
        }
    }

};