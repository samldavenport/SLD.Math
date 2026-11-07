#ifndef SLD_MATH_XFORMS_HPP
#define SLD_MATH_XFORMS_HPP

#include <math.h>
#include "sld-math-types.hpp"
#include "sld-math-plane.hpp"

namespace sld {

    SLD_MATH_API vec3
    xform_vec3(
        const vec3& v,
        const mat3& m) {

        const vec3 result = {
            ((m.r0c0 * v.x) + (m.r0c1 * v.y) + (m.r0c2 * v.z)),  
            ((m.r1c0 * v.x) + (m.r1c1 * v.y) + (m.r1c2 * v.z)), 
            ((m.r2c0 * v.x) + (m.r2c1 * v.y) + (m.r2c2 * v.z)) 
        };
        return(result);
    }

    SLD_MATH_API mat4
    xform_view_look_at(
        const vec3& origin,
        const vec3& target) {

        const vec3& global_up = math_get_global_up();
        vec3 forward          = {0.0f, 0.0f, 0.0f};
        vec3 right            = {0.0f, 0.0f, 0.0f};
        vec3 up               = {0.0f, 0.0f, 0.0f};
        vec3 translation      = {0.0f, 0.0f, 0.0f};

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
        mat4 view;
        view.r0c0 = right.x;
        view.r0c1 = up.x;
        view.r0c2 = forward.x;
        view.r0c3 = 0.0f;
        view.r1c0 = right.y;
        view.r1c1 = up.y;
        view.r1c2 = forward.y;
        view.r1c3 = 0.0f;
        view.r2c0 = right.z;
        view.r2c1 = up.z;
        view.r2c3 = forward.z;
        view.r3c0 = -translation.x;
        view.r3c1 = -translation.y;
        view.r3c2 = -translation.z;
        view.r3c3 = 1.0f;
        return(view);
    }

    SLD_MATH_API vec3
    xform_view_forward(
        const mat4& m) {

        const vec3 forward = {
            -m.r0c2,
            -m.r1c2,
            -m.r2c2
        };
        return(forward);
    }

    SLD_MATH_API vec3
    xform_view_right(
        const mat4& m) {

        const vec3 right = {
            m.r0c0,
            m.r1c0,
            m.r2c0
        };
        return(right);
    }

    SLD_MATH_API vec3
    xform_view_up(
        const mat4& m) {
        
        const vec3 up = {
            m.r0c1,
            m.r1c1,
            m.r2c1
        };
        return(up);
    }

    SLD_MATH_API vec3
    xform_view_origin(
        const mat4& m) {

        const vec3 origin = {
            m.r0c3,
            m.r1c3,
            m.r2c3
        };
        return(origin);
    }

    SLD_MATH_API mat4
    xform_project_near_to_far(
        const f32 fov_radians,
        const f32 aspect_ratio,
        const f32 clip_near,
        const f32 clip_far) {


        const f32 fov_half     = fov_radians * 0.5f;
        const f32 tan_fov_half = tanf(fov_half);
        const f32 far_sub_near = clip_far - clip_near;


        mat4 m;
        m.r0c0 =  1.0f / (aspect_ratio * tan_fov_half);
        m.r0c1 =  0.0f;
        m.r0c2 =  0.0f;
        m.r0c3 =  0.0f;
        m.r1c0 =  0.0f;
        m.r1c1 =  1.0f / tan_fov_half;
        m.r1c2 =  0.0f;
        m.r1c3 =  0.0f;
        m.r2c0 =  0.0f;
        m.r2c1 =  0.0f;
        m.r2c2 = -(clip_far + clip_near)        / far_sub_near;
        m.r2c3 = -(2.0f * clip_far * clip_near) / far_sub_near;
        m.r3c0 =  0.0f;
        m.r3c1 =  0.0f;
        m.r3c2 = -1.0f;
        m.r3c3 =  0.0f;
        return(m);
    }

    SLD_MATH_API mat4
    xform_project_near_to_infinite(
        const f32 fov_radians,
        const f32 aspect_ratio,
        const f32 clip_near) {

        const f32 fov_half     = fov_radians * 0.5f;
        const f32 tan_fov_half = tanf(fov_half);

        mat4 proj;
        proj.r0c0 =  1.0f / (aspect_ratio * tan_fov_half);
        proj.r0c1 =  0.0f;
        proj.r0c2 =  0.0f;
        proj.r0c3 =  0.0f;
        proj.r1c0 =  0.0f;
        proj.r1c1 =  1.0f / tan_fov_half;
        proj.r1c2 =  0.0f;
        proj.r1c3 =  0.0f;
        proj.r2c0 =  0.0f;
        proj.r2c1 =  0.0f;
        proj.r2c2 = -1.0f;
        proj.r2c3 = -2.0f * clip_near;
        proj.r3c0 =  0.0f;
        proj.r3c1 =  0.0f;
        proj.r3c2 = -1.0f;
        proj.r3c3 =  0.0f;
        return(proj);
    }

    //--------------------------------------------------------------------
    // SCREEN SPACE
    //--------------------------------------------------------------------
    // matrices are row major and multiply column vectors, so clip = m * (x, y, z, 1)
    // ndc runs from -1 to 1 with +y up, the viewport is in pixels from its top left with +y down
    // these use whatever m is, so they work with any projection, not just the textbook ones

    // a point through a view projection
    SLD_MATH_API vec4
    xform_point_to_clip(
        const mat4& m,
        const vec3& p) {

        const vec4 clip = {
            ((m.r0c0 * p.x) + (m.r0c1 * p.y) + (m.r0c2 * p.z) + m.r0c3),
            ((m.r1c0 * p.x) + (m.r1c1 * p.y) + (m.r1c2 * p.z) + m.r1c3),
            ((m.r2c0 * p.x) + (m.r2c1 * p.y) + (m.r2c2 * p.z) + m.r2c3),
            ((m.r3c0 * p.x) + (m.r3c1 * p.y) + (m.r3c2 * p.z) + m.r3c3)
        };
        return(clip);
    }

    // the perspective divide, false if the point is behind the camera
    SLD_MATH_API bool
    xform_clip_to_ndc(
        const vec4& clip,
        vec3&       ndc) {

        if (clip.w <= CLIP_W_MIN_32) return(false);

        const f32 w_inv = (1.0f / clip.w);
        ndc.x = (clip.x * w_inv);
        ndc.y = (clip.y * w_inv);
        ndc.z = (clip.z * w_inv);
        return(true);
    }

    SLD_MATH_API vec2
    xform_ndc_to_viewport(
        const vec2& ndc,
        const vec2& viewport_min,
        const vec2& viewport_size) {

        const vec2 point = {
            viewport_min.x + (((ndc.x + 1.0f) * 0.5f) * viewport_size.x),
            viewport_min.y + (((1.0f - ndc.y) * 0.5f) * viewport_size.y)
        };
        return(point);
    }

    SLD_MATH_API vec2
    xform_viewport_to_ndc(
        const vec2& point,
        const vec2& viewport_min,
        const vec2& viewport_size) {

        const vec2 ndc = {
            (((point.x - viewport_min.x) / viewport_size.x) * 2.0f) - 1.0f,
            1.0f - (((point.y - viewport_min.y) / viewport_size.y) * 2.0f)
        };
        return(ndc);
    }

    // where a world point is drawn in the viewport, false if it's behind the camera
    SLD_MATH_API bool
    xform_world_to_viewport(
        const mat4& m,
        const vec3& world,
        const vec2& viewport_min,
        const vec2& viewport_size,
        vec2&       point) {

        vec3 ndc;
        if (!xform_clip_to_ndc(xform_point_to_clip(m, world), ndc)) return(false);

        point = xform_ndc_to_viewport({ ndc.x, ndc.y }, viewport_min, viewport_size);
        return(true);
    }

    // the two world planes holding every point drawn at an ndc point
    // a point lands on ndc (x, y) when clip.x = x * clip.w and clip.y = y * clip.w,
    // so it's on the planes (row 0 - x * row 3) . (p, 1) = 0 and (row 1 - y * row 3) . (p, 1) = 0
    // they meet in the line through the camera and that point, their normals aren't unit length
    SLD_MATH_API void
    xform_ndc_to_planes(
        const mat4& m,
        const vec2& ndc,
        plane&      plane_x,
        plane&      plane_y) {

        plane_x.normal   = {
            m.r0c0 - (ndc.x * m.r3c0),
            m.r0c1 - (ndc.x * m.r3c1),
            m.r0c2 - (ndc.x * m.r3c2)
        };
        plane_x.distance = -(m.r0c3 - (ndc.x * m.r3c3));

        plane_y.normal   = {
            m.r1c0 - (ndc.y * m.r3c0),
            m.r1c1 - (ndc.y * m.r3c1),
            m.r1c2 - (ndc.y * m.r3c2)
        };
        plane_y.distance = -(m.r1c3 - (ndc.y * m.r3c3));
    }

    // the point on a plane that's drawn at an ndc point, the inverse of projecting it
    // this doesn't need the view projection's inverse, or a ray built from the field of view
    // false if the plane is edge on to the camera there, or the point is behind the camera, like past the horizon
    SLD_MATH_API bool
    xform_ndc_to_plane(
        const mat4&  m,
        const vec2&  ndc,
        const plane& target,
        vec3&        point) {

        plane plane_x;
        plane plane_y;
        xform_ndc_to_planes(m, ndc, plane_x, plane_y);

        vec3 hit;
        if (!plane_intersect_planes(plane_x, plane_y, target, hit)) return(false);

        const vec4 clip = xform_point_to_clip(m, hit);
        if (clip.w <= CLIP_W_MIN_32) return(false);

        point = hit;
        return(true);
    }

    // the point on a plane under a point in the viewport
    SLD_MATH_API bool
    xform_viewport_to_plane(
        const mat4&  m,
        const vec2&  viewport_point,
        const vec2&  viewport_min,
        const vec2&  viewport_size,
        const plane& target,
        vec3&        point) {

        const vec2 ndc = xform_viewport_to_ndc(viewport_point, viewport_min, viewport_size);
        return(xform_ndc_to_plane(m, ndc, target, point));
    }
};

#endif //SLD_MATH_XFORMS_HPP
