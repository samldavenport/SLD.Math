#pragma once

#include "sld-math.hpp"

namespace sld {

    SLD_MATH_API void
    xform_view_look_at(
        view&       o_view,
        const vec3& i_origin,
        const vec3& i_target) {

        const vec3& global_up = math_get_global_up();

        // forward
        vec3_subtract  (&o_view.forward, &i_origin, &i_target);
        o_view.forward.normalize();

        // right
        vec3_cross (&o_view.right, &global_up, &o_view.forward);
        o_view.right.normalize();
        
        // up
        vec3_cross(&o_view.up, &o_view.forward, &o_view.right);
        o_view.up.normalize();

        // translation
        vec3_dot(&o_view.translation.x, &i_origin, &i_target);
        vec3_dot(&o_view.translation.y, &i_origin, &i_target);
        vec3_dot(&o_view.translation.z, &i_origin, &i_target);

        // look at transform
        o_view.xform.r0c0 = o_view.right.x;
        o_view.xform.r0c1 = o_view.up.x;
        o_view.xform.r0c2 = o_view.forward.x;
        o_view.xform.r0c3 = 0.0f;
        o_view.xform.r1c0 = o_view.right.y;
        o_view.xform.r1c1 = o_view.up.y;
        o_view.xform.r1c2 = o_view.forward.y;
        o_view.xform.r1c3 = 0.0f;
        o_view.xform.r2c0 = o_view.right.z;
        o_view.xform.r2c1 = o_view.up.z;
        o_view.xform.r2c3 = o_view.forward.z;
        o_view.xform.r3c0 = -o_view.translation.x;
        o_view.xform.r3c1 = -o_view.translation.y;
        o_view.xform.r3c2 = -o_view.translation.z;
        o_view.xform.r3c3 = 1.0f;
    }
};