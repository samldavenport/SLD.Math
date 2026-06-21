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
    // CONTEXT
    //--------------------------------------------------------------------

    SLD_MATH_API void        math_set_global_up (const vec3* up);
    SLD_MATH_API const vec3* math_get_global_up (void);

    //--------------------------------------------------------------------
    // VECTOR 2 
    //--------------------------------------------------------------------
    
    /// @brief         Add 2D vector A to B
    /// @param o_c     Output vector
    /// @param i_a     Input Vector A
    /// @param i_b     Input Vector B
    /// @param i_count Input Vector count, default 1
    /// @return        void 
    SLD_MATH_API void
    vec2_add(
        vec2*       o_c,
        const vec2* i_a,
        const vec2* i_b,
        const u32   i_count = 1
    );

    /// @brief         Subtract 2D vector b from a 
    /// @param o_c     Output 2D vector
    /// @param i_a     Input 2D vector a
    /// @param i_b     Input 2D vector b
    /// @param i_count count vectors, default = 1
    /// @return void
    SLD_MATH_API void
    vec2_subtract(
        vec2*       o_c,
        const vec2* i_a,
        const vec2* i_b,
        const u32   i_count = 1
    );
    
    /// @brief         Project 2D vector A onto B
    /// @param o_c     Output 2D vector
    /// @param i_a     Input 2D vector A
    /// @param i_b     Input 2D vector B
    /// @param i_count Input 2D vector count, default 1
    /// @return        void 
    SLD_MATH_API void
    vec2_project(
        vec2*       o_c,
        const vec2* i_a,
        const vec2* i_b,
        const u32   i_count = 1
    );

    /// @brief         Reject 2D vector B from A 
    /// @param o_c     Output 2D vector
    /// @param i_a     Input 2D vector A
    /// @param i_b     Input 2D vector B
    /// @param i_count Input 2D vector count
    /// @return        void
    SLD_MATH_API void
    vec2_reject(
        vec2*       o_c,
        const vec2* i_a,
        const vec2* i_b,
        const u32   i_count = 1
    );

    /// @brief         Multiply 2D vector by scalar 
    /// @param o_v     Result 2D Vector
    /// @param i_v     Input 2D Vector
    /// @param i_s     Input Scalar
    /// @param i_count Input 2D Vector count
    /// @return        void
    SLD_MATH_API void
    vec2_scalar_multiply(
        vec2*       o_v,
        const vec2* i_v,
        const f32*  i_s,
        const u32   i_count = 1
    );

    /// @brief         Divide 2D vector by scalar 
    /// @param o_v     Output 2D vector
    /// @param i_v     Input 2D vector
    /// @param i_s     Input scalar
    /// @param i_count Input 2D Vector count
    /// @return        void
    SLD_MATH_API void
    vec2_scalar_divide(
        vec2*       o_v,
        const vec2* i_v,
        const f32*  i_s,
        const u32   i_count = 1
    );
    
    /// @brief         Dot product of 2D vectors A and B
    /// @param o_d     Output dot product
    /// @param i_a     Input vector A
    /// @param i_b     Input vector B
    /// @param i_count Input vector count, default 1
    /// @return        void
    SLD_MATH_API void
    vec2_dot(
        f32*        o_d,
        const vec2* i_a,
        const vec2* i_b,
        const u32   i_count = 1
    );

    /// @brief         2D Vector magnitude
    /// @param o_m     Output magnitude
    /// @param i_v     Input 2D vector
    /// @param i_count Input 2D vector count
    /// @return        void
    SLD_MATH_API void
    vec2_magnitude(
        f32*        o_m,
        const vec2* i_v,
        const u32   i_count = 1
    );

    /// @brief         Normalize 2D vector
    /// @param o_m     Output normalized 2D vector
    /// @param i_v     Input 2D vector
    /// @param i_count Input 2D vector count
    /// @return        void
    SLD_MATH_API void
    vec2_normalize(
        f32*        o_m,
        const vec2* i_v,
        const u32   i_count = 1
    );

    //--------------------------------------------------------------------
    // VECTOR 3 
    //--------------------------------------------------------------------

    SLD_MATH_API void vec3_add             (vec3* o_c, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_subtract        (vec3* o_c, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_project         (vec3* o_c, const vec2* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_reject          (vec3* o_c, const vec2* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_cross           (vec3* o_c, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_scalar_multiply (vec3* o_v, const vec3* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void vec3_scalar_divide   (vec3* o_v, const vec3* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void vec3_dot             (f32*  o_d, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_transform_mat3  (vec3* o_t, const vec3* i_v, const mat3* i_m, const u32 i_count = 1);
    SLD_MATH_API void vec3_transform_mat4  (vec3* o_t, const vec3* i_v, const mat4* i_m, const u32 i_count = 1);
    SLD_MATH_API void vec3_magnitude       (f32*  o_m, const vec3* i_v,                  const u32 i_count = 1);
    SLD_MATH_API void vec3_normalize       (vec3* o_v, const vec3* i_v,                  const u32 i_count = 1);

    //--------------------------------------------------------------------
    // MATRIX 3 
    //--------------------------------------------------------------------

    SLD_MATH_API void mat3_identity        (mat3* o_m, const u32 i_count = 1);
    SLD_MATH_API void mat3_determinant     (f32*  o_d, const mat3* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat3_transpose       (mat3* o_t, const mat3* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat3_invert          (mat3* o_t, const mat3* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat3_multiply        (mat3* o_c, const mat3* i_a, const mat3* i_b, const u32 i_count = 1);

    //--------------------------------------------------------------------
    // MATRIX 4 
    //--------------------------------------------------------------------

    SLD_MATH_API void mat4_identity        (mat4* o_m, const u32 i_count = 1);
    SLD_MATH_API void mat4_determinant     (f32*  o_d, const mat4* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat4_transpose       (mat4* o_t, const mat4* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat4_invert          (mat4* o_t, const mat4* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat4_multiply        (mat4* o_c, const mat4* i_a, const mat3* i_b, const u32 i_count = 1);

    //--------------------------------------------------------------------
    // TRANSFORMS 
    //--------------------------------------------------------------------

    SLD_MATH_API void xform_rotate_vector        (mat4* o_xform, const f32*  i_a, const vec3* i_v,           const u32 i_count = 1);
    SLD_MATH_API void xform_rotate_axis_x        (mat4* o_xform, const f32*  i_a,                            const u32 i_count = 1);
    SLD_MATH_API void xform_rotate_axis_y        (mat4* o_xform, const f32*  i_a,                            const u32 i_count = 1);
    SLD_MATH_API void xform_rotate_axis_z        (mat4* o_xform, const f32*  i_a,                            const u32 i_count = 1);
    SLD_MATH_API void xform_scale_uniform        (mat4* o_xform, const f32*  i_s,                            const u32 i_count = 1);
    SLD_MATH_API void xform_scale_non_uniform    (mat4* o_xform, const vec3* i_s,                            const u32 i_count = 1);
    SLD_MATH_API void xform_translate            (mat4* o_xform, const vec3* i_p,                            const u32 i_count = 1);
    SLD_MATH_API void xform_look_at              (mat4* o_xform, const vec3* i_origin, const vec3* i_target, const u32 i_count = 1);

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

        vec3(
            const f32 x,
            const f32 y,
            const f32 z) {

            this->x = x;
            this->y = y;
            this->z = z;
        }

        vec3(void) {
            this->x = 0;
            this->y = 0;
            this->z = 0;
        } 
    };

    struct vec4 {
        union {
            f32 v[4];
            struct {
                f32 x;
                f32 y;
                f32 z;
                f32 w;
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
            struct {
                vec3 r0;
                vec3 r1;
                vec3 r2;
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
            struct {
                vec4 r0;
                vec4 r1;
                vec4 r2;
                vec4 r3;
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