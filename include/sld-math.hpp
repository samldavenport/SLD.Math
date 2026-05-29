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
    using  tfrm = mat4;

    //--------------------------------------------------------------------
    // VECTOR 2 
    //--------------------------------------------------------------------

    SLD_MATH_API void vec2_add (const vec2* in_a, const vec2* in_b, vec2* out_c, const u32 count = 1);
    SLD_MATH_API void vec2_sub (const vec2* in_a, const vec2* in_b, vec2* out_c, const u32 count = 1);
    SLD_MATH_API void vec2_prj (const vec2* in_a, const vec2* in_b, vec2* out_c, const u32 count = 1);
    SLD_MATH_API void vec2_rej (const vec2* in_a, const vec2* in_b, vec2* out_c, const u32 count = 1);
    SLD_MATH_API void vec2_mul (const vec2* in_v, const f32*  in_s, vec2* out_v, const u32 count = 1);
    SLD_MATH_API void vec2_div (const vec2* in_v, const f32*  in_s, vec2* out_v, const u32 count = 1);
    SLD_MATH_API void vec2_dot (const vec2* in_a, const vec2* in_b, f32*  out_d, const u32 count = 1);
    SLD_MATH_API void vec2_mag (const vec2* in_v, f32*        out_m,             const u32 count = 1);
    SLD_MATH_API void vec2_nrm (const vec2* in_v, f32*        out_m,             const u32 count = 1);

    //--------------------------------------------------------------------
    // VECTOR 3 
    //--------------------------------------------------------------------

    SLD_MATH_API void vec3_add (const vec3* in_a, const vec3* in_b, vec3* out_c, const u32 count = 1);
    SLD_MATH_API void vec3_sub (const vec3* in_a, const vec3* in_b, vec3* out_c, const u32 count = 1);
    SLD_MATH_API void vec3_prj (const vec2* in_a, const vec3* in_b, vec3* out_c, const u32 count = 1);
    SLD_MATH_API void vec3_rej (const vec2* in_a, const vec3* in_b, vec3* out_c, const u32 count = 1);
    SLD_MATH_API void vec3_crs (const vec3* in_a, const vec3* in_b, vec3* out_c, const u32 count = 1);
    SLD_MATH_API void vec3_mul (const vec3* in_v, const f32*  in_s, vec3* out_v, const u32 count = 1);
    SLD_MATH_API void vec3_div (const vec3* in_v, const f32*  in_s, vec3* out_v, const u32 count = 1);
    SLD_MATH_API void vec3_dot (const vec3* in_a, const vec2* in_b, f32*  out_d, const u32 count = 1);
    SLD_MATH_API void vec3_mag (const vec3* in_v, f32*        out_m,             const u32 count = 1);
    SLD_MATH_API void vec3_nrm (const vec3* in_v, f32*        out_m,             const u32 count = 1);

    //--------------------------------------------------------------------
    // MATRIX 3 
    //--------------------------------------------------------------------

    SLD_MATH_API const mat3& mat3_idt (void);
    SLD_MATH_API void        mat3_det (const mat3* in_m, f32*        out_d,             const u32 count = 1);
    SLD_MATH_API void        mat3_trn (const mat3* in_m, mat3*       out_t,             const u32 count = 1);
    SLD_MATH_API void        mat3_inv (const mat3* in_m, mat3*       out_t,             const u32 count = 1);
    SLD_MATH_API void        mat3_mul (const mat3* in_a, const mat3* in_b, mat3* out_c, const u32 count = 1);


    //--------------------------------------------------------------------
    // TRANSFORMS 
    //--------------------------------------------------------------------

    void tfrm_rot_x (const f32   in_a, trfm*       out_t,             const u32 count = 1);
    void tfrm_rot_y (const f32   in_a, trfm*       out_t,             const u32 count = 1);
    void tfrm_rot_z (const f32   in_a, trfm*       out_t,             const u32 count = 1);
    void tfrm_rot_v (const c32   in_a, const vec3* in_v, trfm* out_t, const u32 count = 1);
    void tfrm_scl_u (const f32*  in_s, trfm*       out_t,             const u32 count = 1);
    void tfrm_scl_n (const vec3* in_s, trfm*       out_t,             const u32 count = 1);
    void tfrm_trn_n (const vec3* in_p, trfm*       out_t,             const u32 count = 1);

    //--------------------------------------------------------------------
    // DEFINITIONS 
    //--------------------------------------------------------------------

    struct vec2 {
        union {
            f32 v[2];
            struct {
                f32 x;
                f32 y;
            }
        }
    };

    struct vec3 {
        union {
            f32 v[3];
            struct {
                f32 x;
                f32 y;
                f32 z;
            };
        }
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