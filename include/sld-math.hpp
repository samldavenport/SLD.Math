#ifndef SLD_MATH_HPP
#define SLD_MATH_HPP

#include <math.h>
#include <sld.hpp>
#include "sld-math-types.hpp"
#include "sld-math-globals.hpp"
#include "sld-math-scalar.hpp"
#include "sld-math-vec2.hpp"
#include "sld-math-vec3.hpp"
#include "sld-math-mat3.hpp"
#include "sld-math-mat4.hpp"
#include "sld-math-plane.hpp"
#include "sld-math-xforms.hpp"

namespace sld {

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
    SLD_MATH_API vec3 vec3_from_yaw_pitch  (const f32 yaw, const f32 pitch, const f32 length);

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

    SLD_MATH_API mat3 mat3_identity        (void);
    SLD_MATH_API mat3 mat3_transpose       (const mat3& m);
    SLD_MATH_API mat3 mat3_invert          (const mat3& m);
    SLD_MATH_API mat3 mat3_multiply        (const mat3& a, const mat3& b);
    SLD_MATH_API f32  mat3_determinant     (const mat3& m);
    SLD_MATH_API bool mat3_try_invert      (const mat3& m, mat3& inv);

    SLD_MATH_API void mat3_identity        (mat3* m,                                 const u32 i_count = 1);
    SLD_MATH_API void mat3_transpose       (mat3* mt, const mat3*  m,                const u32 i_count = 1);
    SLD_MATH_API void mat3_invert          (mat3* mt, const mat3*  m,                const u32 i_count = 1);
    SLD_MATH_API void mat3_multiply        (mat3* mm, const mat3*  a, const mat3* b, const u32 i_count = 1);
    SLD_MATH_API void mat3_determinant     (f32*  o_d, const mat3* m,                const u32 i_count = 1);

    //--------------------------------------------------------------------
    // MATRIX 4 
    //--------------------------------------------------------------------

    SLD_MATH_API mat4 mat4_identity        (void);
    SLD_MATH_API mat4 mat4_transpose       (const mat4& m);
    SLD_MATH_API mat4 mat4_invert          (const mat4& m);
    SLD_MATH_API mat4 mat4_multiply        (const mat4& a, const mat4& b);
    SLD_MATH_API f32  mat4_determinant     (const mat4& m);
    SLD_MATH_API bool mat4_try_invert      (const mat4& m, mat4& inv);

    SLD_MATH_API void mat4_identity        (mat4* o_m, const u32 i_count = 1);
    SLD_MATH_API void mat4_determinant     (f32*  o_d, const mat4* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat4_transpose       (mat4* o_t, const mat4* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat4_invert          (mat4* o_t, const mat4* i_m,                  const u32 i_count = 1);
    SLD_MATH_API void mat4_multiply        (mat4* o_c, const mat4* i_a, const mat4* i_b, const u32 i_count = 1);

    //--------------------------------------------------------------------
    // PLANES 
    //--------------------------------------------------------------------

    SLD_MATH_API plane plane_from_point_normal (const vec3& point, const vec3& normal);
    SLD_MATH_API plane plane_from_points       (const vec3& a, const vec3& b, const vec3& c);
    SLD_MATH_API plane plane_normalize         (const plane& p);
    SLD_MATH_API f32   plane_signed_distance   (const plane& p, const vec3& point);
    SLD_MATH_API vec3  plane_project_point     (const plane& p, const vec3& point);
    SLD_MATH_API bool  plane_intersect_planes  (const plane& a, const plane& b, const plane& c, vec3& point);

    //--------------------------------------------------------------------
    // RAYS
    //--------------------------------------------------------------------

    SLD_MATH_API vec3  ray_get_point           (const ray& r, const f32 t);
    SLD_MATH_API bool  ray_intersect_plane     (const ray& r, const plane& p, f32& t);
    
    //--------------------------------------------------------------------
    // TRANSFORMS 
    //--------------------------------------------------------------------

    SLD_MATH_API vec3 xform_vec3                     (const vec3& v, const mat3& m);
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
    // SCREEN SPACE
    //--------------------------------------------------------------------

    SLD_MATH_API vec4 xform_point_to_clip     (const mat4& m, const vec3& p);
    SLD_MATH_API bool xform_clip_to_ndc       (const vec4& clip, vec3& ndc);
    SLD_MATH_API vec2 xform_ndc_to_viewport   (const vec2& ndc,   const vec2& viewport_min, const vec2& viewport_size);
    SLD_MATH_API vec2 xform_viewport_to_ndc   (const vec2& point, const vec2& viewport_min, const vec2& viewport_size);
    SLD_MATH_API bool xform_world_to_viewport (const mat4& m, const vec3& world, const vec2& viewport_min, const vec2& viewport_size, vec2& point);
    SLD_MATH_API void xform_ndc_to_planes     (const mat4& m, const vec2& ndc, plane& plane_x, plane& plane_y);
    SLD_MATH_API bool xform_ndc_to_plane      (const mat4& m, const vec2& ndc, const plane& target, vec3& point);
    SLD_MATH_API bool xform_viewport_to_plane (const mat4& m, const vec2& viewport_point, const vec2& viewport_min, const vec2& viewport_size, const plane& target, vec3& point);

    //--------------------------------------------------------------------
    // TRIGONOMETRY
    //--------------------------------------------------------------------

    SLD_MATH_API f32 trig_degrees_to_radians (const f32 d) { return(d * RADIANS_FACTOR); }
    SLD_MATH_API f32 trig_radians_to_degrees (const f32 r) { return(r * DEGREES_FACTOR); }

    //--------------------------------------------------------------------
    // SCALAR
    //--------------------------------------------------------------------

    SLD_MATH_API f32 math_clamp (const f32 v, const f32 min, const f32 max);
    SLD_MATH_API f32 math_lerp  (const f32 a, const f32 b, const f32 t);
};

#endif //SLD_MATH_HPP
