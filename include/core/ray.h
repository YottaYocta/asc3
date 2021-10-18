#ifndef RAY_H
#define RAY_H

#include <core/vec.h>

struct ray
{
  point3 origin;
  vec3 dir;
  ray() : ray (point3 {0, 0, 0}, vec3 {0, 0, -1}) {}
  ray(const point3& o, const vec3& d) : origin {o}, dir {d} {}
  point3 at(double t) const { return origin + dir * t; }
};

#endif
