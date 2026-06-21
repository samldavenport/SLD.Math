#pragma once

#include "sld-math.hpp"

namespace sld {


    SLD_MATH_API const mat4&
    mat4_identity(
        void) {

        static mat4 mat;

        // row 0
        mat.m[0]  = 1.0f; 
        mat.m[1]  = 0.0f;
        mat.m[2]  = 0.0f;
        mat.m[3]  = 0.0f;

        // row 1
        mat.m[4]  = 0.0f; 
        mat.m[5]  = 1.0f;
        mat.m[6]  = 0.0f;
        mat.m[7]  = 0.0f;

        // row 2
        mat.m[8]  = 0.0f; 
        mat.m[9]  = 0.0f;
        mat.m[10] = 1.0f;
        mat.m[11] = 0.0f;

        // row 3
        mat.m[12] = 0.0f; 
        mat.m[13] = 0.0f;
        mat.m[14] = 0.0f;
        mat.m[15] = 1.0f;

        return(mat);
    }

    // SLD_MATH_API void        mat4_determinant     (f32*  o_d, const mat4* i_m,                  const u32 i_count = 1);
    // SLD_MATH_API void        mat4_transpose       (mat4* o_t, const mat4* i_m,                  const u32 i_count = 1);
    // SLD_MATH_API void        mat4_invert          (mat4* o_t, const mat4* i_m,                  const u32 i_count = 1);
    // SLD_MATH_API void        mat4_multiply        (mat4* o_c, const mat4* i_a, const mat3* i_b, const u32 i_count = 1);


};