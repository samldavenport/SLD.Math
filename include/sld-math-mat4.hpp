#ifndef SLD_MATH_MAT4_HPP
#define SLD_MATH_MAT4_HPP

#include "sld-math-types.hpp"
#include "sld-math-globals.hpp"

namespace sld {

    SLD_MATH_API void
    mat4_identity(
        mat4* o_m,
        const u32 i_count) {

        assert(o_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            mat4& m = o_m[index];
            
            // row 0
            m.r0c0  = 1.0f; 
            m.r0c1  = 0.0f;
            m.r0c2  = 0.0f;
            m.r0c3  = 0.0f;

            // row 1
            m.r1c0  = 0.0f; 
            m.r1c1  = 1.0f;
            m.r1c2  = 0.0f;
            m.r1c3  = 0.0f;

            // row 2
            m.r2c0 = 0.0f; 
            m.r2c1 = 0.0f;
            m.r2c2 = 1.0f;
            m.r2c3 = 0.0f;

            // row 3
            m.r3c0 = 0.0f; 
            m.r3c1 = 0.0f;
            m.r3c2 = 0.0f;
            m.r3c3 = 1.0f;
        }
    }

    SLD_MATH_API void
    mat4_determinant(
        f32*        o_d,
        const mat4* i_m,
        const u32   i_count) {

    }

    SLD_MATH_API void
    mat4_transpose(
        mat4*       o_t,
        const mat4* i_m,
        const u32   i_count) {

    }
    
    SLD_MATH_API void
    mat4_invert(
        mat4*       o_t,
        const mat4* i_m,
        const u32   i_count) {

    }

    SLD_MATH_API void
    mat4_multiply(
        mat4*       o_c,
        const mat4* i_a,
        const mat4* i_b,
        const u32   i_count) {

    }
};

#endif //SLD_MATH_MAT4_HPP