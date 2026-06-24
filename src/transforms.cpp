#pragma once

#include "sld-math.hpp"

namespace sld {

    SLD_MATH_API void
    xform_view_look_at(
        view&       o_view,
        const vec3& i_origin,
        const vec3& i_target) {

        o_view.look_at(i_origin, i_target);
    }
};