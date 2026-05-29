#ifndef SLD_MATH_HPP
#define SLD_MATH_HPP

#include <sld.hpp>

namespace sld {

    //--------------------------------------------------------------------
    // STRUCTURED TYPES
    //--------------------------------------------------------------------

    struct vec2;
    struct vec3;
    struct mat3;
    struct mat4;
    struct quat;

    //--------------------------------------------------------------------
    // VECTOR 2 
    //--------------------------------------------------------------------

    void vec2_add        (const vec2* in_a,  const vec2* in_b, vec2* out_c,   const u32 count = 1);
    void vec2_sub        (const vec2* in_a,  const vec2* in_b, vec2* out_c,   const u32 count = 1);
    void vec2_scalar_mul (const vec2* in_v2, const f32*  s,    vec2* out_v2,  const u32 count = 1);
    void vec2_scalar_div (const vec2* in_v2, const f32*  s,    vec2* out_v2,  const u32 count = 1);
    void vec2_dot        (const vec2* in_a,  const vec2* in_b, f32*  out_dot, const u32 count = 1);
    void vec2_magnitude  (const vec2* in_v2, f32* out_mag,                    const u32 count = 1);
    void vec2_normalize  (const vec2* in_v2, f32* out_mag,                    const u32 count = 1);

    //--------------------------------------------------------------------
    // VECTOR 3 
    //--------------------------------------------------------------------

    void vec3_add        (const vec3* in_a,  const vec3* in_b, vec3* out_c,   const u32 count = 1);
    void vec3_sub        (const vec3* in_a,  const vec3* in_b, vec3* out_c,   const u32 count = 1);
    void vec3_cross      (const vec3* in_a,  const vec3* in_b, vec3* out_c,   const u32 count = 1);
    void vec3_scalar_mul (const vec3* in_v2, const f32*  s,    vec3* out_v2,  const u32 count = 1);
    void vec3_scalar_div (const vec3* in_v2, const f32*  s,    vec3* out_v2,  const u32 count = 1);
    void vec3_dot        (const vec3* in_a,  const vec2* in_b, f32*  out_dot  const u32 count = 1);
    void vec3_magnitude  (const vec3* in_v2, f32* out_mag,                    const u32 count = 1);
    void vec3_normalize  (const vec3* in_v2, f32* out_mag,                    const u32 count = 1);

    //--------------------------------------------------------------------
    // DEFINITIONS 
    //--------------------------------------------------------------------

    struct vec2 {
        f32 x;
        f32 y;
    };

    struct vec3 {
        f32 x;
        f32 y;
        f32 z;
    };

    struct mat3 {
        union {
            f32 m[9];
            struct {
                f32 r0c0;
                f32 r0c1;
                f32 r0c2;
                f32 r1c0;
                f32 r1c1;
                f32 r1c2;
                f32 r2c0;
                f32 r2c1;
                f32 r2c2;
            };
        };
    };

    struct mat4 {
        union {
            f32 m[16];
            struct {
                f32 r0c0;
                f32 r0c1;
                f32 r0c2;
                f32 r0c3;
                f32 r1c0;
                f32 r1c1;
                f32 r1c2;
                f32 r1c3;
                f32 r2c0;
                f32 r2c1;
                f32 r2c2;
                f32 r2c3;
                f32 r3c0;
                f32 r3c1;
                f32 r3c2;
                f32 r3c3;
            };
        };

    };

    struct quat {
        f32 x;
        f32 y;
        f32 z;
        f32 w;
    };


};

#endif //SLD_MATH_HPP