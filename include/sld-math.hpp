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

// NOTE(SAM): these are based on opengl coordinate space
#define SLD_MATH_DEFAULT_GLOBAL_UP     vec3(0.0f, 1.0f, 0.0f)
#define SLD_MATH_DEFAULT_GLOBAL_X_AXIS vec3(1.0f, 0.0f, 0.0f)
#define SLD_MATH_DEFAULT_GLOBAL_Y_AXIS vec3(0.0f, 1.0f, 0.0f)
#define SLD_MATH_DEFAULT_GLOBAL_Z_AXIS vec3(0.0f, 0.0f, 1.0f)

namespace sld {

    //--------------------------------------------------------------------
    // CONSTANTS
    //--------------------------------------------------------------------

    constexpr f32 PI_32          = 3.1415926535f;
    constexpr f32 RADIANS_FACTOR = (PI_32 / 180.0f);
    constexpr f32 DEGREES_FACTOR = (180.f / PI_32);

    //--------------------------------------------------------------------
    // STRUCTURED TYPES
    //--------------------------------------------------------------------

    struct vec2;
    struct vec3;
    struct mat3;
    struct mat4;
    struct quat;
    struct xform;
    struct view;
    struct proj;

    //--------------------------------------------------------------------
    // GLOBALS
    //--------------------------------------------------------------------

    SLD_MATH_API void        math_set_global_up     (const vec3& up);
    SLD_MATH_API void        math_set_global_x_axis (const vec3& x_axis);
    SLD_MATH_API void        math_set_global_y_axis (const vec3& y_axis);
    SLD_MATH_API void        math_set_global_z_axis (const vec3& z_axis);

    SLD_MATH_API const vec3& math_get_global_up     (void);
    SLD_MATH_API const vec3& math_set_global_x_axis (void);
    SLD_MATH_API const vec3& math_set_global_y_axis (void);
    SLD_MATH_API const vec3& math_set_global_z_axis (void);


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

    // reference methods
    SLD_MATH_API vec3 vec3_add             (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_subtract        (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_project         (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_reject          (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_cross           (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_transform       (const vec3& v, const mat3& m);
    SLD_MATH_API vec3 vec3_scalar_multiply (const vec3& v, const f32   s);
    SLD_MATH_API vec3 vec3_scalar_divide   (const vec3& v, const f32   s);
    SLD_MATH_API f32  vec3_dot             (const vec3& a, const vec3& b);
    SLD_MATH_API f32  vec3_magnitude       (const vec3& v);
    SLD_MATH_API vec3 vec3_normalize       (const vec3& v);

    // pointer methods
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

    SLD_MATH_API void mat3_identity        (mat3& m);
    SLD_MATH_API void mat3_transpose       (mat3& mt, const mat3& m);
    SLD_MATH_API void mat3_invert          (mat3& mi, const mat3& m);
    SLD_MATH_API void mat3_multiply        (mat3& mm, const mat3& a, const mat3* b);
    SLD_MATH_API f32  mat3_determinant     (const mat3& m);

    SLD_MATH_API void mat3_identity        (mat3* m,                                 const u32 i_count = 1);
    SLD_MATH_API void mat3_transpose       (mat3* mt, const mat3*  m,                const u32 i_count = 1);
    SLD_MATH_API void mat3_invert          (mat3* mt, const mat3*  m,                const u32 i_count = 1);
    SLD_MATH_API void mat3_multiply        (mat3* mm, const mat3*  a, const mat3* b, const u32 i_count = 1);
    SLD_MATH_API void mat3_determinant     (f32*  o_d, const mat3* m,                const u32 i_count = 1);

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

    SLD_MATH_API mat4 xform_translate     (const vec3& t);
    SLD_MATH_API mat4 xform_scale         (const vec3& s);
    SLD_MATH_API mat4 xform_rotate_vector (const vec3& r, const f32 rad);
    SLD_MATH_API mat4 xform_rotate_axis_x (const f32 rad);
    SLD_MATH_API mat4 xform_rotate_axis_y (const f32 rad);
    SLD_MATH_API mat4 xform_rotate_axis_z (const f32 rad);
    SLD_MATH_API mat4 xform_view_look_at  (const vec3& origin, const vec3& target);
    SLD_MATH_API vec3 xform_view_forward  (const mat4& m);
    SLD_MATH_API vec3 xform_view_right    (const mat4& m);
    SLD_MATH_API vec3 xform_view_up       (const mat4& m);
    SLD_MATH_API vec3 xform_view_origin   (const mat4& m);

    //--------------------------------------------------------------------
    // TRIGONOMETRY
    //--------------------------------------------------------------------

    inline f32 trig_degrees_to_radians (const f32 d) { return(d * RADIANS_FACTOR); }
    inline f32 trig_radians_to_degrees (const f32 r) { return(r * DEGREES_FACTOR); }

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


    struct view : mat4 {

        inline void
        forward(vec3& f) {
            f.x = -r0c2;
            f.y = -r1c2;
            f.z = -r2c2;
        }

        inline void
        right(vec3& r) {
            r.x = r0c0;
            r.y = r1c0;
            r.z = r2c0;
        }

        inline void
        up(vec3& u) {
            u.x = r0c1;
            u.y = r1c1;
            u.z = r2c1;
        }

        inline void
        origin(vec3& o) {
            o.x = r0c3;
            o.y = r1c3;
            o.z = r2c3;
        }

        inline void
        look_at(
            const vec3& origin,
            const vec3& target) {

            const vec3& global_up = math_get_global_up();

            vec3 forward     = {0.0f, 0.0f, 0.0f};
            vec3 right       = {0.0f, 0.0f, 0.0f};
            vec3 up          = {0.0f, 0.0f, 0.0f};
            vec3 translation = {0.0f, 0.0f, 0.0f};

            // forward
            forward = vec3_subtract  (origin,target);
            forward = vec3_normalize (forward);

            // right
            right = vec3_cross     (global_up, forward);
            right = vec3_normalize (right);
            
            // up
            up = vec3_cross     (forward, right);
            up = vec3_normalize (up);

            // translation
            translation.x = vec3_dot(origin, target);
            translation.y = vec3_dot(origin, target);
            translation.z = vec3_dot(origin, target);

            // look at transform
            r0c0 = right.x;
            r0c1 = up.x;
            r0c2 = forward.x;
            r0c3 = 0.0f;
            r1c0 = right.y;
            r1c1 = up.y;
            r1c2 = forward.y;
            r1c3 = 0.0f;
            r2c0 = right.z;
            r2c1 = up.z;
            r2c3 = forward.z;
            r3c0 = -translation.x;
            r3c1 = -translation.y;
            r3c2 = -translation.z;
            r3c3 = 1.0f;
        } 
    };

    struct proj : mat4 {

        inline void
        near_to_far(
            const f32 fov_radians,
            const f32 aspect_ratio,
            const f32 clip_near,
            const f32 clip_far) {

            const f32 fov_half     = fov_radians * 0.5f;
            const f32 tan_fov_half = tanf(fov_half);
            const f32 far_sub_near = clip_far - clip_near;

            identity();

            r0c0 = 1.0f / (aspect_ratio * tan_fov_half);
            r1c1 = 1.0f / tan_fov_half;
            r2c2 = -(clip_far + clip_near)        / far_sub_near;
            r2c3 = -(2.0f * clip_far * clip_near) / far_sub_near;
            r3c2 = -1.0f;
            r3c3 = 0.0f;
        }

        inline void
        near_to_infinite(
            const f32 fov_radians,
            const f32 aspect_ratio,
            const f32 clip_near) {

            const f32 fov_half     = fov_radians * 0.5f;
            const f32 tan_fov_half = tanf(fov_half);

            identity();

            r0c0 =  1.0f / (aspect_ratio * tan_fov_half);
            r1c1 =  1.0f / tan_fov_half;
            r2c2 = -1.0f;
            r2c3 = -2.0f * clip_near;
            r3c2 = -1.0f;
            r3c3 = 0.0f;
        }
    };
};

#endif //SLD_MATH_HPP