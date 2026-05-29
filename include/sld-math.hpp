#ifndef SLD_MATH_HPP
#define SLD_MATH_HPP

#include <math.h>
#include <sld.hpp>


#ifdef SLD_MATH_STATIC
#   define SLD_MATH_API
#elif defined(SLD_MATH_DLL_EXPORT)
#   define SLD_MATH_API __declspec(dllexport)
#else
#   define SLD_MATH_API __declspec(dllimport)
#endif

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

    SLD_MATH_API void        vec2_add             (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec2_subtract        (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec2_project         (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec2_reject          (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec2_scalar_multiply (vec2* o_v, const vec2* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void        vec2_scalar_divide   (vec2* o_v, const vec2* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void        vec2_dot             (f32*  o_d, const vec2* i_a, const vec2* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec2_magnitude       (f32*  o_m, const vec2* i_v,                  const u32 i_count = 1);
    SLD_MATH_API void        vec2_normalize       (f32*  o_m, const vec2* i_v,                  const u32 i_count = 1);

    //--------------------------------------------------------------------
    // VECTOR 3 
    //--------------------------------------------------------------------

    SLD_MATH_API void        vec3_add             (vec3* o_c, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec3_subtract        (vec3* o_c, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec3_project         (vec3* o_c, const vec2* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec3_reject          (vec3* o_c, const vec2* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec3_cross           (vec3* o_c, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec3_scalar_multiply (vec3* o_v, const vec3* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void        vec3_scalar_divide   (vec3* o_v, const vec3* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void        vec3_dot             (f32*  o_d, const vec3* i_a, const vec2* i_b, const u32 i_count = 1);
    SLD_MATH_API void        vec3_magnitude       (f32*  o_m, const vec3* i_v,                  const u32 i_count = 1);
    SLD_MATH_API void        vec3_normalize       (f32*  o_m, const vec3* i_v,                  const u32 i_count = 1);

    //--------------------------------------------------------------------
    // MATRIX 3 
    //--------------------------------------------------------------------

    SLD_MATH_API const mat3& mat3_identity        (void);
    SLD_MATH_API void        mat3_determinant     (f32*  o_d, const mat3* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void        mat3_transpose       (mat3* o_t, const mat3* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void        mat3_invert          (mat3* o_t, const mat3* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void        mat3_multiply        (mat3* o_c, const mat3* i_a, const mat3* i_b, const u32 i_count = 1);

    //--------------------------------------------------------------------
    // TRANSFORMS 
    //--------------------------------------------------------------------

    SLD_MATH_API void        rotate_vector        (mat4* o_m, const f32*  i_a, const vec3* i_v, const u32 i_count = 1);
    SLD_MATH_API void        rotate_axis_x        (mat4* o_m, const f32*  i_a,                  const u32 i_count = 1);
    SLD_MATH_API void        rotate_axis_y        (mat4* o_m, const f32*  i_a,                  const u32 i_count = 1);
    SLD_MATH_API void        rotate_axis_z        (mat4* o_m, const f32*  i_a,                  const u32 i_count = 1);
    SLD_MATH_API void        scale_uniform        (mat4* o_m, const f32*  i_s,                  const u32 i_count = 1);
    SLD_MATH_API void        scale_non_uniform    (mat4* o_m, const vec3* i_s,                  const u32 i_count = 1);
    SLD_MATH_API void        translate            (mat4* o_m, const vec3* i_p,                  const u32 i_count = 1);

    //--------------------------------------------------------------------
    // DEFINITIONS 
    //--------------------------------------------------------------------

    struct vec2 {
        union {
            f32 v[2];
            struct {
                f32 x;
                f32 y;
            };
        };
    };

    struct vec3 {
        union {
            f32 v[3];
            struct {
                f32 x;
                f32 y;
                f32 z;
            };
        };
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
        union {
            f32 q[4];
            struct {
                f32 x;
                f32 y;
                f32 z;
                f32 w;
            };
        };
    };
};

#endif //SLD_MATH_HPP