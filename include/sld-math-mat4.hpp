#ifndef SLD_MATH_MAT4_HPP
#define SLD_MATH_MAT4_HPP

#include "sld-math-types.hpp"
#include "sld-math-globals.hpp"

namespace sld {

    SLD_MATH_API mat4
    mat4_identity(
        void) {

        mat4 m;
        m.r0c0 = 1.0f;
        m.r0c1 = 0.0f;
        m.r0c2 = 0.0f;
        m.r0c3 = 0.0f;
        m.r1c0 = 0.0f;
        m.r1c1 = 1.0f;
        m.r1c2 = 0.0f;
        m.r1c3 = 0.0f;
        m.r2c0 = 0.0f;
        m.r2c1 = 0.0f;
        m.r2c2 = 1.0f;
        m.r2c3 = 0.0f;
        m.r3c0 = 0.0f;
        m.r3c1 = 0.0f;
        m.r3c2 = 0.0f;
        m.r3c3 = 1.0f;
        return(m);
    }
    
    SLD_MATH_API mat4
    mat4_transpose(
        const mat4& m) {

        mat4 t;
        t.r0c0 = m.r0c0; t.r0c1 = m.r1c0; t.r0c2 = m.r2c0; t.r0c3 = m.r3c0;
        t.r1c0 = m.r0c1; t.r1c1 = m.r1c1; t.r1c2 = m.r2c1; t.r1c3 = m.r3c1;
        t.r2c0 = m.r0c2; t.r2c1 = m.r1c2; t.r2c2 = m.r2c2; t.r2c3 = m.r3c2;
        t.r3c0 = m.r0c3; t.r3c1 = m.r1c3; t.r3c2 = m.r2c3; t.r3c3 = m.r3c3;
        return(t);
    }

    // the 2x2 determinants the determinant and the inverse are built from
    // s are from rows 0 and 1, c are from rows 2 and 3, each pairs up two columns
    struct mat4_minors {
        f32 s0, s1, s2, s3, s4, s5;
        f32 c0, c1, c2, c3, c4, c5;
    };

    SLD_MATH_API mat4_minors
    mat4_get_minors(
        const mat4& m) {

        mat4_minors n;
        n.s0 = (m.r0c0 * m.r1c1) - (m.r1c0 * m.r0c1);
        n.s1 = (m.r0c0 * m.r1c2) - (m.r1c0 * m.r0c2);
        n.s2 = (m.r0c0 * m.r1c3) - (m.r1c0 * m.r0c3);
        n.s3 = (m.r0c1 * m.r1c2) - (m.r1c1 * m.r0c2);
        n.s4 = (m.r0c1 * m.r1c3) - (m.r1c1 * m.r0c3);
        n.s5 = (m.r0c2 * m.r1c3) - (m.r1c2 * m.r0c3);
        n.c0 = (m.r2c0 * m.r3c1) - (m.r3c0 * m.r2c1);
        n.c1 = (m.r2c0 * m.r3c2) - (m.r3c0 * m.r2c2);
        n.c2 = (m.r2c0 * m.r3c3) - (m.r3c0 * m.r2c3);
        n.c3 = (m.r2c1 * m.r3c2) - (m.r3c1 * m.r2c2);
        n.c4 = (m.r2c1 * m.r3c3) - (m.r3c1 * m.r2c3);
        n.c5 = (m.r2c2 * m.r3c3) - (m.r3c2 * m.r2c3);
        return(n);
    }

    // the laplace expansion along rows 0 and 1
    SLD_MATH_API f32
    mat4_determinant_from_minors(
        const mat4_minors& n) {

        return(
            (n.s0 * n.c5) - (n.s1 * n.c4) + (n.s2 * n.c3) +
            (n.s3 * n.c2) - (n.s4 * n.c1) + (n.s5 * n.c0)
        );
    }

    // false if m can't be inverted, its determinant is zero, and inv isn't touched
    // a matrix that's nearly singular inverts, but with a large error
    SLD_MATH_API bool
    mat4_try_invert(
        const mat4& m,
        mat4&       inv) {

        const mat4_minors n   = mat4_get_minors(m);
        const f32         det = mat4_determinant_from_minors(n);
        if (det == 0.0f) return(false);

        const f32 d = (1.0f / det);
        if (!isfinite(d)) return(false);

        // the adjugate, the transposed cofactors, over the determinant
        mat4 r;
        r.r0c0 = ( (m.r1c1 * n.c5) - (m.r1c2 * n.c4) + (m.r1c3 * n.c3)) * d;
        r.r0c1 = (-(m.r0c1 * n.c5) + (m.r0c2 * n.c4) - (m.r0c3 * n.c3)) * d;
        r.r0c2 = ( (m.r3c1 * n.s5) - (m.r3c2 * n.s4) + (m.r3c3 * n.s3)) * d;
        r.r0c3 = (-(m.r2c1 * n.s5) + (m.r2c2 * n.s4) - (m.r2c3 * n.s3)) * d;

        r.r1c0 = (-(m.r1c0 * n.c5) + (m.r1c2 * n.c2) - (m.r1c3 * n.c1)) * d;
        r.r1c1 = ( (m.r0c0 * n.c5) - (m.r0c2 * n.c2) + (m.r0c3 * n.c1)) * d;
        r.r1c2 = (-(m.r3c0 * n.s5) + (m.r3c2 * n.s2) - (m.r3c3 * n.s1)) * d;
        r.r1c3 = ( (m.r2c0 * n.s5) - (m.r2c2 * n.s2) + (m.r2c3 * n.s1)) * d;

        r.r2c0 = ( (m.r1c0 * n.c4) - (m.r1c1 * n.c2) + (m.r1c3 * n.c0)) * d;
        r.r2c1 = (-(m.r0c0 * n.c4) + (m.r0c1 * n.c2) - (m.r0c3 * n.c0)) * d;
        r.r2c2 = ( (m.r3c0 * n.s4) - (m.r3c1 * n.s2) + (m.r3c3 * n.s0)) * d;
        r.r2c3 = (-(m.r2c0 * n.s4) + (m.r2c1 * n.s2) - (m.r2c3 * n.s0)) * d;

        r.r3c0 = (-(m.r1c0 * n.c3) + (m.r1c1 * n.c1) - (m.r1c2 * n.c0)) * d;
        r.r3c1 = ( (m.r0c0 * n.c3) - (m.r0c1 * n.c1) + (m.r0c2 * n.c0)) * d;
        r.r3c2 = (-(m.r3c0 * n.s3) + (m.r3c1 * n.s1) - (m.r3c2 * n.s0)) * d;
        r.r3c3 = ( (m.r2c0 * n.s3) - (m.r2c1 * n.s1) + (m.r2c2 * n.s0)) * d;

        inv = r;
        return(true);
    }

    // m has to be invertible, use mat4_try_invert if it might not be
    // a singular matrix asserts, and gives the identity with asserts off
    SLD_MATH_API mat4
    mat4_invert(
        const mat4& m) {

        mat4 inv;
        const bool is_invertible = mat4_try_invert(m, inv);
        assert(is_invertible);
        if (!is_invertible) inv = mat4_identity();
        return(inv);
    }

    SLD_MATH_API mat4
    mat4_multiply(
        const mat4& a,
        const mat4& b) {

        mat4 result = {};

        result.r0c0 = (a.r0c0 * b.r0c0) + (a.r0c1 * b.r1c0) + (a.r0c2 * b.r2c0) + (a.r0c3 * b.r3c0);
        result.r0c1 = (a.r0c0 * b.r0c1) + (a.r0c1 * b.r1c1) + (a.r0c2 * b.r2c1) + (a.r0c3 * b.r3c1);
        result.r0c2 = (a.r0c0 * b.r0c2) + (a.r0c1 * b.r1c2) + (a.r0c2 * b.r2c2) + (a.r0c3 * b.r3c2);
        result.r0c3 = (a.r0c0 * b.r0c3) + (a.r0c1 * b.r1c3) + (a.r0c2 * b.r2c3) + (a.r0c3 * b.r3c3);

        result.r1c0 = (a.r1c0 * b.r0c0) + (a.r1c1 * b.r1c0) + (a.r1c2 * b.r2c0) + (a.r1c3 * b.r3c0);
        result.r1c1 = (a.r1c0 * b.r0c1) + (a.r1c1 * b.r1c1) + (a.r1c2 * b.r2c1) + (a.r1c3 * b.r3c1);
        result.r1c2 = (a.r1c0 * b.r0c2) + (a.r1c1 * b.r1c2) + (a.r1c2 * b.r2c2) + (a.r1c3 * b.r3c2);
        result.r1c3 = (a.r1c0 * b.r0c3) + (a.r1c1 * b.r1c3) + (a.r1c2 * b.r2c3) + (a.r1c3 * b.r3c3);

        result.r2c0 = (a.r2c0 * b.r0c0) + (a.r2c1 * b.r1c0) + (a.r2c2 * b.r2c0) + (a.r2c3 * b.r3c0);
        result.r2c1 = (a.r2c0 * b.r0c1) + (a.r2c1 * b.r1c1) + (a.r2c2 * b.r2c1) + (a.r2c3 * b.r3c1);
        result.r2c2 = (a.r2c0 * b.r0c2) + (a.r2c1 * b.r1c2) + (a.r2c2 * b.r2c2) + (a.r2c3 * b.r3c2);
        result.r2c3 = (a.r2c0 * b.r0c3) + (a.r2c1 * b.r1c3) + (a.r2c2 * b.r2c3) + (a.r2c3 * b.r3c3);

        result.r3c0 = (a.r3c0 * b.r0c0) + (a.r3c1 * b.r1c0) + (a.r3c2 * b.r2c0) + (a.r3c3 * b.r3c0);
        result.r3c1 = (a.r3c0 * b.r0c1) + (a.r3c1 * b.r1c1) + (a.r3c2 * b.r2c1) + (a.r3c3 * b.r3c1);
        result.r3c2 = (a.r3c0 * b.r0c2) + (a.r3c1 * b.r1c2) + (a.r3c2 * b.r2c2) + (a.r3c3 * b.r3c2);
        result.r3c3 = (a.r3c0 * b.r0c3) + (a.r3c1 * b.r1c3) + (a.r3c2 * b.r2c3) + (a.r3c3 * b.r3c3);

        return result;
    }

    SLD_MATH_API f32
    mat4_determinant(
        const mat4& m) {

        return(mat4_determinant_from_minors(mat4_get_minors(m)));
    }


    SLD_MATH_API void
    mat4_identity(
        mat4* o_m,
        const u32 i_count) {

        assert(o_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            mat4& m = o_m[index];
            
            // row 0
            m.r0c0  = 1.0f; 
            m.r0c1  = 0.0f;
            m.r0c2  = 0.0f;
            m.r0c3  = 0.0f;

            // row 1
            m.r1c0  = 0.0f; 
            m.r1c1  = 1.0f;
            m.r1c2  = 0.0f;
            m.r1c3  = 0.0f;

            // row 2
            m.r2c0 = 0.0f; 
            m.r2c1 = 0.0f;
            m.r2c2 = 1.0f;
            m.r2c3 = 0.0f;

            // row 3
            m.r3c0 = 0.0f; 
            m.r3c1 = 0.0f;
            m.r3c2 = 0.0f;
            m.r3c3 = 1.0f;
        }
    }

    SLD_MATH_API void
    mat4_determinant(
        f32*        o_d,
        const mat4* i_m,
        const u32   i_count) {

        assert(o_d != NULL && i_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_d[index] = mat4_determinant(i_m[index]);
        }
    }

    SLD_MATH_API void
    mat4_transpose(
        mat4*       o_t,
        const mat4* i_m,
        const u32   i_count) {

        assert(o_t != NULL && i_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_t[index] = mat4_transpose(i_m[index]);
        }
    }

    SLD_MATH_API void
    mat4_invert(
        mat4*       o_t,
        const mat4* i_m,
        const u32   i_count) {

        assert(o_t != NULL && i_m != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_t[index] = mat4_invert(i_m[index]);
        }
    }

    SLD_MATH_API void
    mat4_multiply(
        mat4*       o_c,
        const mat4* i_a,
        const mat4* i_b,
        const u32   i_count) {

        assert(o_c != NULL && i_a != NULL && i_b != NULL && i_count != 0);

        for (
            u32 index = 0;
                index < i_count;
              ++index) {

            o_c[index] = mat4_multiply(i_a[index], i_b[index]);
        }
    }
};

#endif //SLD_MATH_MAT4_HPP
