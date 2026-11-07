# SLD.Math
Simple math library for 2D/3D games, built for speed

It's header only: every function is `inline` (`SLD_MATH_API`), so there's nothing to link. Include `sld-math.hpp` for everything.

## Conventions

- **Matrices are row major and multiply column vectors.** `mat4` stores its rows in order (`r0c0`, `r0c1`, …), and transforming a point is `m * (x, y, z, 1)`. A translation is in the last column (`r0c3`, `r1c3`, `r2c3`).
- **Y is up**, as in OpenGL. The global up and axes in `sld-math-globals.hpp` default to this.
- **NDC** runs from -1 to 1 on each axis, with +y up. **Viewport** points are in pixels from the viewport's top left, with +y down, like most UI.
- Functions that can fail return `bool` and write their result to an out parameter, which isn't touched on failure.

## Constants

| Constant | Value | Use |
| --- | --- | --- |
| `PI_32` | π | |
| `RADIANS_FACTOR`, `DEGREES_FACTOR` | π / 180, 180 / π | Converting angles |
| `EPSILON_32` | 0.000001 | Below this, a determinant or the angle between a ray and a plane counts as zero |
| `CLIP_W_MIN_32` | 0.0001 | A point whose clip space `w` is at or below this is behind the camera, or too close to it to project |

## Scalars

| Function | Description |
| --- | --- |
| `math_clamp(v, min, max)` | `v` kept between `min` and `max` |
| `math_lerp(a, b, t)` | `a` at `t = 0`, `b` at `t = 1`. `t` isn't clamped. |

## Vectors

Alongside the usual `vec3` functions (add, subtract, dot, cross, normalize, …):

| Function | Description |
| --- | --- |
| `vec3_from_yaw_pitch(yaw, pitch, length)` | A vector of the given length pointing along a yaw and pitch, in radians. Yaw turns around y, from +z at 0 towards +x at π/2. Pitch tilts above the xz plane, so π/2 points straight up. An orbiting camera's origin is its target plus this. |

## Planes and Rays

A `plane` is the points `p` where `dot(normal, p) == distance`. With a unit normal, `distance` is how far the plane is from the origin along the normal. Some functions need a unit normal and some don't, as the table says.

A `ray` is the points `origin + direction * t` for `t >= 0`.

| Function | Unit normal | Description |
| --- | --- | --- |
| `plane_from_point_normal(point, normal)` | makes one | The plane through a point, facing along `normal`, which can be any length |
| `plane_from_points(a, b, c)` | makes one | The plane through three points, facing the side they wind counter-clockwise from. They can't be on one line. |
| `plane_normalize(p)` | makes one | The same plane with a unit normal |
| `plane_signed_distance(p, point)` | for world units | How far a point is in front of the plane, negative behind it. Without a unit normal it's scaled by the normal's length, but the sign is still right. |
| `plane_project_point(p, point)` | needed | The point on the plane closest to `point` |
| `plane_intersect_planes(a, b, c, point)` | not needed | The one point on all three planes. False if two are parallel, or they meet in a line. |
| `ray_get_point(r, t)` | | The point `t` along the ray |
| `ray_intersect_plane(r, p, t)` | not needed | Where the ray hits the plane, from either side. False if it runs along the plane, or the plane is behind it. |

`plane_intersect_planes` uses `(a.d (b × c) + b.d (c × a) + c.d (a × b)) / (a · (b × c))`, where the denominator is the determinant of the three normals.

## Screen Space

These go between the world, clip space, NDC, and a viewport, using a view projection matrix `m` (projection × view). They only use `m` itself, so they work with any projection, including ones that aren't textbook perspective matrices.

| Function | Description |
| --- | --- |
| `xform_point_to_clip(m, p)` | `m * (p, 1)` |
| `xform_clip_to_ndc(clip, ndc)` | The perspective divide. False if the point is behind the camera. |
| `xform_ndc_to_viewport(ndc, min, size)` | An NDC point in viewport pixels |
| `xform_viewport_to_ndc(point, min, size)` | A viewport pixel in NDC |
| `xform_world_to_viewport(m, world, min, size, point)` | Where a world point is drawn in the viewport. False if it's behind the camera. |
| `xform_ndc_to_planes(m, ndc, plane_x, plane_y)` | The two world planes holding every point drawn at an NDC point |
| `xform_ndc_to_plane(m, ndc, target, point)` | The point on `target` that's drawn at an NDC point |
| `xform_viewport_to_plane(m, point, min, size, target, hit)` | The point on `target` under a viewport pixel, for picking |

### Picking without an inverse

A world point `p` is drawn at NDC `(x, y)` when `clip.x = x * clip.w` and `clip.y = y * clip.w`. Writing the rows of `m` as `row0` to `row3`, that's

```
(row0 - x * row3) · (p, 1) = 0
(row1 - y * row3) · (p, 1) = 0
```

Each of these is a plane in world space, and they meet in the line through the camera and that point on the screen. `xform_ndc_to_planes` returns them. Intersecting them with a third plane, like the floor, with `plane_intersect_planes` gives the point on that plane under the cursor. That's all `xform_ndc_to_plane` does, plus a check that the point is in front of the camera.

This doesn't need `m`'s inverse or the camera's field of view. A plane seen edge on, or a point past the horizon, returns false.

```cpp
// the floor tile under the mouse
const plane floor_plane = { { 0.0f, 1.0f, 0.0f }, floor_y };

vec3 hit;
if (xform_viewport_to_plane(view_proj, mouse, viewport_min, viewport_size, floor_plane, hit)) {
    const s32 col = (s32)floorf(hit.x / tile_size);
    const s32 row = (s32)floorf(hit.z / tile_size);
}
```

## Matrices

`mat3` and `mat4` have the same functions, with `mat3_` and `mat4_` prefixes.

| Function | Description |
| --- | --- |
| `_identity()` | |
| `_multiply(a, b)` | `a * b`, so `b` applies first. A view projection is `mat4_multiply(proj, view)`. |
| `_transpose(m)` | |
| `_determinant(m)` | |
| `_try_invert(m, inv)` | False if `m` can't be inverted (its determinant is zero), and `inv` isn't touched |
| `_invert(m)` | `m` has to be invertible. A singular matrix asserts, and gives the identity with asserts off. Use `_try_invert` if it might not be invertible. |

Each one also has a pointer version that works on `i_count` matrices at once, e.g. `mat4_invert(o_t, i_m, i_count)`.

`xform_vec3(v, m)` transforms a vector by a `mat3`.

For a `mat3`, the determinant is the triple product of the rows, `r0 · (r1 × r2)`, and the inverse's columns are `r1 × r2`, `r2 × r0`, and `r0 × r1` over the determinant.

For a `mat4`, the determinant and inverse use the 2×2 determinants of rows 0 and 1 and of rows 2 and 3 (a Laplace expansion), so the inverse is the adjugate over the determinant without any 3×3 work. There's no epsilon on the determinant, so a small scale like 0.01 still inverts. A matrix that's nearly singular inverts too, but with a large error.

For picking, [`xform_ndc_to_plane`](#picking-without-an-inverse) is still the better choice. It's cheaper than inverting the view projection, and it stays accurate near the horizon.
