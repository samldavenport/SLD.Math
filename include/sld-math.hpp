#ifndef SLD_MATH_HPP
#define SLD_MATH_HPP

#include <math.h>
#include <sld.hpp>
#include "sld-math-types.hpp"
#include "sld-math-globals.hpp"
namespace sld {

    //--------------------------------------------------------------------
    // TYPES 
    //--------------------------------------------------------------------

    struct vec2;
    struct vec3;
    struct mat3;
    struct mat4;

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
    
    SLD_MATH_API void vec2_add             (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec2_subtract        (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1 );
    SLD_MATH_API void vec2_project         (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1 ); 
    SLD_MATH_API void vec2_reject          (vec2* o_c, const vec2* i_a, const vec2* i_b, const u32 i_count = 1 );
    SLD_MATH_API void vec2_scalar_multiply (vec2* o_v, const vec2* i_v, const f32*  i_s, const u32 i_count = 1 );
    SLD_MATH_API void vec2_scalar_divide   (vec2* o_v, const vec2* i_v, const f32*  i_s, const u32 i_count = 1 );
    SLD_MATH_API void vec2_dot             (f32*  o_d, const vec2* i_a, const vec2* i_b, const u32 i_count = 1 );
    SLD_MATH_API void vec2_magnitude       (f32*  o_m, const vec2* i_v, const u32   i_count = 1 ); 
    SLD_MATH_API void vec2_normalize       (f32*  o_m, const vec2* i_v, const u32   i_count = 1 );

    //--------------------------------------------------------------------
    // VECTOR 3 
    //--------------------------------------------------------------------

    // reference methods
    SLD_MATH_API vec3 vec3_add             (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_subtract        (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_project         (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_reject          (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_cross           (const vec3& a, const vec3& b);
    SLD_MATH_API vec3 vec3_scalar_multiply (const vec3& v, const f32   s);
    SLD_MATH_API vec3 vec3_scalar_divide   (const vec3& v, const f32   s);
    SLD_MATH_API f32  vec3_dot             (const vec3& a, const vec3& b);
    SLD_MATH_API f32  vec3_magnitude       (const vec3& v);
    SLD_MATH_API vec3 vec3_normalize       (const vec3& v);

    // pointer methods
    SLD_MATH_API void vec3_add             (vec3* o_v, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_subtract        (vec3* o_v, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_project         (vec3* o_v, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_reject          (vec3* o_v, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_cross           (vec3* o_v, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
    SLD_MATH_API void vec3_scalar_multiply (vec3* o_v, const vec3* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void vec3_scalar_divide   (vec3* o_v, const vec3* i_v, const f32*  i_s, const u32 i_count = 1);
    SLD_MATH_API void vec3_dot             (f32*  o_d, const vec3* i_a, const vec3* i_b, const u32 i_count = 1);
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

    SLD_MATH_API vec3 xform_vec3                     (const vec3& v, const mat4 m);
    SLD_MATH_API mat4 xform_translate                (const vec3& t);
    SLD_MATH_API mat4 xform_scale                    (const vec3& s);
    SLD_MATH_API mat4 xform_rotate_vector            (const vec3& r, const f32 rad);
    SLD_MATH_API mat4 xform_rotate_axis_x            (const f32 rad);
    SLD_MATH_API mat4 xform_rotate_axis_y            (const f32 rad);
    SLD_MATH_API mat4 xform_rotate_axis_z            (const f32 rad);
    SLD_MATH_API mat4 xform_view_look_at             (const vec3& origin, const vec3& target);
    SLD_MATH_API vec3 xform_view_forward             (const mat4& m);
    SLD_MATH_API vec3 xform_view_right               (const mat4& m);
    SLD_MATH_API vec3 xform_view_up                  (const mat4& m);
    SLD_MATH_API vec3 xform_view_origin              (const mat4& m);
    SLD_MATH_API mat4 xform_project_near_to_far      (const f32 fov_radians, const f32 aspect_ratio, const f32 clip_near, const f32 clip_far);
    SLD_MATH_API mat4 xform_project_near_to_infinite (const f32 fov_radians, const f32 aspect_ratio, const f32 clip_near);

    //--------------------------------------------------------------------
    // TRIGONOMETRY
    //--------------------------------------------------------------------

    SLD_MATH_API f32 trig_degrees_to_radians (const f32 d) { return(d * RADIANS_FACTOR); }
    SLD_MATH_API f32 trig_radians_to_degrees (const f32 r) { return(r * DEGREES_FACTOR); }
};

#endif //SLD_MATH_HPP
