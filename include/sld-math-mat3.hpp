#ifndef SLD_MATH_MAT3_HPP
#define SLD_MATH_MAT3_HPP

#include "sld-math-types.hpp"
#include "sld-math-globals.hpp"
#include "sld-math-vec3.hpp"

namespace sld {

    //--------------------------------------------------------------------
    // REFERENCE METHODS
    //--------------------------------------------------------------------

    SLD_MATH_API mat3
    mat3_identity(
        void) {

        mat3 m;
        m.r0c0 = 1.0f; m.r0c1 = 0.0f; m.r0c2 = 0.0f;
        m.r1c0 = 0.0f; m.r1c1 = 1.0f; m.r1c2 = 0.0f;
        m.r2c0 = 0.0f; m.r2c1 = 0.0f; m.r2c2 = 1.0f;
        return(m);
    }

    SLD_MATH_API mat3
    mat3_transpose(
        const mat3& m) {

        mat3 t;
        t.r0c0 = m.r0c0; t.r0c1 = m.r1c0; t.r0c2 = m.r2c0;
        t.r1c0 = m.r0c1; t.r1c1 = m.r1c1; t.r1c2 = m.r2c1;
        t.r2c0 = m.r0c2; t.r2c1 = m.r1c2; t.r2c2 = m.r2c2;
        return(t);
    }

    // the scalar triple product of the rows, r0 . (r1 x r2)
    SLD_MATH_API f32
    mat3_determinant(
        const mat3& m) {

        return(vec3_dot(m.r0, vec3_cross(m.r1, m.r2)));
    }

    // false if m can't be inverted, its determinant is zero, and inv isn't touched
    // a matrix that's nearly singular inverts, but with a large error
    SLD_MATH_API bool
    mat3_try_invert(
        const mat3& m,
        mat3&       inv) {

        // the inverse's columns are the cross products of the other two rows, over the determinant
        const vec3 c0  = vec3_cross(m.r1, m.r2);
        const vec3 c1  = vec3_cross(m.r2, m.r0);
        const vec3 c2  = vec3_cross(m.r0, m.r1);
        const f32  det = vec3_dot(m.r0, c0);
        if (det == 0.0f) return(false);

        const f32 d = (1.0f / det);
        if (!isfinite(d)) return(false);

        mat3 r;
        r.r0c0 = c0.x * d; r.r0c1 = c1.x * d; r.r0c2 = c2.x * d;
        r.r1c0 = c0.y * d; r.r1c1 = c1.y * d; r.r1c2 = c2.y * d;
        r.r2c0 = c0.z * d; r.r2c1 = c1.z * d; r.r2c2 = c2.z * d;

        inv = r;
        return(true);
    }

    // m has to be invertible, use mat3_try_invert if it might not be
    // a singular matrix asserts, and gives the identity with asserts off
    SLD_MATH_API mat3
    mat3_invert(
        const mat3& m) {

        mat3 inv;
        const bool is_invertible = mat3_try_invert(m, inv);
        assert(is_invertible);
        if (!is_invertible) inv = mat3_identity();
        return(inv);
    }

    // a * b, so b applies first
    SLD_MATH_API mat3
    mat3_multiply(
        const mat3& a,
        const mat3& b) {

        mat3 c;
        c.r0c0 = (a.r0c0 * b.r0c0) + (a.r0c1 * b.r1c0) + (a.r0c2 * b.r2c0);
        c.r0c1 = (a.r0c0 * b.r0c1) + (a.r0c1 * b.r1c1) + (a.r0c2 * b.r2c1);
        c.r0c2 = (a.r0c0 * b.r0c2) + (a.r0c1 * b.r1c2) + (a.r0c2 * b.r2c2);
        c.r1c0 = (a.r1c0 * b.r0c0) + (a.r1c1 * b.r1c0) + (a.r1c2 * b.r2c0);
        c.r1c1 = (a.r1c0 * b.r0c1) + (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1);
        c.r1c2 = (a.r1c0 * b.r0c2) + (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2);
        c.r2c0 = (a.r2c0 * b.r0c0) + (a.r2c1 * b.r1c0) + (a.r2c2 * b.r2c0);
        c.r2c1 = (a.r2c0 * b.r0c1) + (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1);
        c.r2c2 = (a.r2c0 * b.r0c2) + (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2);
        return(c);
    }

    //--------------------------------------------------------------------
    // POINTER METHODS
    //--------------------------------------------------------------------

    SLD_MATH_API void
    mat3_identity(
        mat3*     o_m,
        const u32 i_count) {

        assert(o_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_m[index] = mat3_identity();
        }
    }

    SLD_MATH_API void
    mat3_determinant(
        f32*        o_d,
        const mat3* i_m,
        const u32   i_count) {

        assert(o_d != NULL && i_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_d[index] = mat3_determinant(i_m[index]);
        }
    }

    SLD_MATH_API void
    mat3_transpose(
        mat3*       o_t,
        const mat3* i_m,
        const u32   i_count) {

        assert(o_t != NULL && i_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_t[index] = mat3_transpose(i_m[index]);
        }
    }

    SLD_MATH_API void
    mat3_invert(
        mat3*       o_t,
        const mat3* i_m,
        const u32   i_count) {

        assert(o_t != NULL && i_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_t[index] = mat3_invert(i_m[index]);
        }
    }

    SLD_MATH_API void
    mat3_multiply(
        mat3*       o_c,
        const mat3* i_a,
        const mat3* i_b,
        const u32   i_count) {

        assert(o_c != NULL && i_a != NULL && i_b != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_c[index] = mat3_multiply(i_a[index], i_b[index]);
        }
    }
};

#endif //SLD_MATH_MAT3_HPP
