#pragma once

#include "sld-math.hpp"

namespace sld {

    SLD_MATH_API void
    mat3_identity(
        mat3*     o_m,
        const u32 i_count) {


        assert(o_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            mat3& m = o_m[index];
            
            // row 0
            m.r0c0  = 1.0f; 
            m.r0c1  = 0.0f;
            m.r0c2  = 0.0f;

            // row 1
            m.r1c0  = 0.0f; 
            m.r1c1  = 1.0f;
            m.r1c2  = 0.0f;

            // row 2
            m.r2c0 = 0.0f; 
            m.r2c1 = 0.0f;
            m.r2c2 = 1.0f;
        }
    }

    SLD_MATH_API void
    mat3_determinant(
        f32*        o_d,
        const mat3* i_m,
        const u32   i_count) {
        
        assert(
            o_d     != NULL &&
            i_m     != NULL &&
            i_count != 0
        );

        for (
            u32 index = 0;
                index < i_count;
              ++index
        ) {

            const mat3& m = i_m[index];
            f32&        d = o_d[index];
            
            d = (
                (m.r0c0 * m.r1c1 * m.r2c2 - m.r1c2 * m.r2c1) +
                (m.r0c1 * m.r1c2 * m.r2c0 - m.r1c0 * m.r2c2) +
                (m.r0c2 * m.r1c0 * m.r2c1 - m.r1c1 * m.r2c0)
            );
        }

    }

    SLD_MATH_API void
    mat3_transpose(
        mat3*       o_t,
        const mat3* i_m,
        const u32   i_count) {

        for (
            u32 index = 0;
                index < i_count;
              ++index
        ) {

            mat3&       t = o_t[index];
            const mat3& m = i_m[index];

            t.r0c0 = m.r0c0;
            t.r0c1 = m.r1c0;
            t.r0c2 = m.r2c0;
            t.r1c0 = m.r0c1;
            t.r1c1 = m.r1c1;
            t.r1c2 = m.r2c1;
            t.r2c0 = m.r0c2;
            t.r2c1 = m.r1c2;
            t.r2c2 = m.r2c2;
        }
    }

    SLD_MATH_API void
    mat3_invert(
        mat3*       o_t,
        const mat3* i_m,
        const u32   i_count) {

        assert(
            o_t     != NULL &&
            i_m     != NULL &&
            i_count != 0
        );

        vec3 r0_cross;
        vec3 r1_cross;
        vec3 r2_cross;
        f32  dot;

        for (
            u32 index = 0;
                index < i_count;
              ++index
        ) {

            mat3&       t = o_t[index];
            const mat3& m = i_m[index];
        
            vec3_cross(&r0_cross, &m.r1, &m.r2);
            vec3_cross(&r1_cross, &m.r2, &m.r0);
            vec3_cross(&r2_cross, &m.r0, &m.r2);

            vec3_dot(&dot, &r2_cross, &m.r2);

            const f32 inv_dot = (1.0f / dot);
            
            t.r0c0 = inv_dot * r0_cross.x;
            t.r0c1 = inv_dot * r0_cross.y;
            t.r0c2 = inv_dot * r0_cross.z;

            t.r1c0 = inv_dot * r1_cross.x;
            t.r1c1 = inv_dot * r1_cross.y;
            t.r1c2 = inv_dot * r1_cross.z;
            
            t.r2c0 = inv_dot * r2_cross.x;
            t.r2c1 = inv_dot * r2_cross.y;
            t.r2c2 = inv_dot * r2_cross.z;
        }
    }

    SLD_MATH_API void
    mat3_multiply(
        mat3*       o_c,
        const mat3* i_a,
        const mat3* i_b,
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
              ++index
        ) {

            const mat3& a = i_a[index];    
            const mat3& b = i_b[index];    
            mat3&       c = o_c[index];

            c.r0c0 = (a.r0c0 * b.r0c0) + (a.r0c1 * b.r1c0) + (a.r0c2 * b.r2c0); 
            c.r0c1 = (a.r0c0 * b.r0c1) + (a.r0c1 * b.r1c1) + (a.r0c2 * b.r2c1); 
            c.r0c2 = (a.r0c0 * b.r0c2) + (a.r0c1 * b.r1c2) + (a.r0c2 * b.r2c2); 
            c.r1c0 = (a.r1c0 * b.r0c0) + (a.r1c1 * b.r1c0) + (a.r1c2 * b.r2c0); 
            c.r1c1 = (a.r1c0 * b.r0c1) + (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1); 
            c.r1c2 = (a.r1c0 * b.r0c2) + (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2); 
            c.r2c0 = (a.r2c0 * b.r0c0) + (a.r2c1 * b.r1c0) + (a.r2c2 * b.r2c0); 
            c.r2c1 = (a.r2c0 * b.r0c1) + (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1); 
            c.r2c2 = (a.r2c0 * b.r0c2) + (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2); 
        }
    }
};