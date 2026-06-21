#pragma once

#include "sld-math.hpp"

namespace sld {

    SLD_MATH_API void
    xform_look_at(
        mat4*       o_xform,
        const vec3* i_origin,
        const vec3* i_target,
        const u32   i_count) {

        assert(
            o_xform  != NULL &&
            i_origin != NULL &&
            i_target != NULL &&
            i_count  != 0
        );

        const vec3* global_up = math_get_global_up();
        
        vec3 forward;
        vec3 up;
        vec3 right;

        f32 translate_x;
        f32 translate_y;
        f32 translate_z;

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            mat4&       xform  = o_xform  [index];
            const vec3& origin = i_origin [index];
            const vec3& target = i_target [index];            

            // forward
            vec3_subtract  (&forward, &origin, &target);
            vec3_normalize (&forward, &forward);

            // right
            vec3_cross     (&right, global_up, &forward);
            vec3_normalize (&right, &right);

            // up
            vec3_cross     (&up, &forward, &right);
            vec3_normalize (&up, &up);

            // translation
            vec3_dot(&translate_x, &origin, &target);
            vec3_dot(&translate_y, &origin, &target);
            vec3_dot(&translate_z, &origin, &target);

            // look at transform
            xform.r0c0 = right.x;
            xform.r0c1 = up.x;
            xform.r0c2 = forward.x;
            xform.r0c3 = 0.0f;
            xform.r1c0 = right.y;
            xform.r1c1 = up.y;
            xform.r1c2 = forward.y;
            xform.r1c3 = 0.0f;
            xform.r2c0 = right.z;
            xform.r2c1 = up.z;
            xform.r2c3 = forward.z;
            xform.r3c0 = -translate_x;
            xform.r3c1 = -translate_y;
            xform.r3c2 = -translate_z;
            xform.r3c3 = 1.0f;
        }

        
    }
};