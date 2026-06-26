#ifndef SLD_MATH_XFORMS_HPP
#define SLD_MATH_XFORMS_HPP

#include "sld-math.hpp"

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
};

#endif //SLD_MATH_XFORMS_HPP