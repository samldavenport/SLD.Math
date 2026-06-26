#pragma once

#include "sld-math.hpp"

namespace sld {

    inline void
    vec2_add(
        vec2*       o_c, 
        const vec2* i_a, 
        const vec2* i_b,
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

                const vec2& a = i_a [index];            
                const vec2& b = i_b [index];            
                vec2&       c = o_c [index];            
        
                c.x = a.x + b.x;
                c.y = a.y + b.y;
        }
    }

    inline void
    vec2_sub(
        vec2*       o_c, 
        const vec2* i_a, 
        const vec2* i_b,
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

                const vec2& a = i_a [index];            
                const vec2& b = i_b [index];            
                vec2&       c = o_c [index];            
        
                c.x = a.x - b.x;
                c.y = a.y - b.y;
        }
    }

    inline void
    vec2_proj(
        vec2*       o_c, 
        const vec2* i_a, 
        const vec2* i_b,
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

                const vec2& a      = i_a  [index];            
                const vec2& b      = i_b  [index];            
                vec2&       c      = o_c [index];            
                const f32   dot_ab = ((a.x * b.x) + (a.y * b.y));
                const f32   dot_bb = ((b.x * b.x) + (b.y * b.y));
                const f32   scalar = (dot_ab / dot_bb);

                c.x = (scalar * b.x); 
                c.y = (scalar * b.y); 
        }
    }

    inline void
    vec2_rej(
        vec2*       o_c, 
        const vec2* i_a, 
        const vec2* i_b,
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

                const vec2& a        = i_a [index];            
                const vec2& b        = i_b [index];            
                vec2&       c        = o_c [index];            
                const f32   dot_ab   = ((a.x * b.x) + (a.y * b.y));
                const f32   dot_bb   = ((b.x * b.x) + (b.y * b.y));
                const f32   scalar   = (dot_ab / dot_bb);
                const vec2  scalar_b = { (scalar * b.x), (scalar * b.y) }; 
                c.x                  = (a.x - scalar_b.x); 
                c.y                  = (a.y - scalar_b.y); 
        }
    }

    inline void
    vec2_scalar_mul(
        vec2*       o_sv,
        const vec2* i_v,
        const f32*  i_s,   
        const u32   i_count) {

        assert(
            o_sv    != NULL &&
            i_v     != NULL &&
            i_s     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec2& v  = i_v  [index];            
                const f32&  s  = i_s  [index];            
                vec2&       sv = o_sv [index];            
        
                sv.x = s * v.x; 
                sv.y = s * v.y;
        }
    }

    inline void
    vec2_scalar_div(
        vec2*       o_sv,
        const vec2* i_v,
        const f32*  i_s,   
        const u32   i_count) {

        assert(
            o_sv    != NULL &&
            i_v     != NULL &&
            i_s     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

                const vec2& v     = i_v    [index];            
                const f32&  s     = i_s    [index];            
                vec2&       sv    = o_sv  [index];            

                assert(s != 0);
                const f32   s_inv = (1 / s); 
                
                sv.x = s_inv * v.x; 
                sv.y = s_inv * v.y;
        }
    }

    inline void
    vec2_dot(
        f32*        o_d,
        const vec2* i_a, 
        const vec2* i_b,
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

                const vec2& a = i_a  [index];            
                const vec2& b = i_b  [index];            
                f32&        d = o_d [index];            

                d = (
                    (a.x * b.x) + (a.y * b.y)
                );
        }
    }

    inline void
    vec2_magnitude(
        f32*        o_m,
        const vec2* i_v,
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

                const vec2& v  = i_v [index];            
                f32&        m  = o_m [index];            

                m = sqrtf(
                    powf(v.x, 2.0f) +
                    powf(v.y, 2.0f)
                );
        }
    }

    inline void
    vec2_normalize(
        vec2*       o_vn,
        const vec2* i_v,
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

                const vec2& v     = i_v  [index];            
                vec2&       vn    = o_vn [index];            
                const f32   m     = sqrtf(powf(v.x, 2.0f) + powf(v.y, 2.0f));
                const f32   m_inv = (1.0f / m);
                vn.x              = (m_inv * v.x);        
                vn.y              = (m_inv * v.y);        
        }
    }
};