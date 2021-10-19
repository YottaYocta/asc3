#include <core/primitives.h>

primitive::primitive(const vec3& t) : transform {t} {}

sphere::sphere() : sphere(vec3 {0, 0, -1}, 1) {}

sphere::sphere(const vec3& t, double r) : primitive(t), radius {r} {}

vec3 sphere::get_transform() const
{
  return transform;
}

void sphere::set_transform(const vec3& t)
{
  transform = t;
}

double sphere::get_radius() const
{
  return radius;
}

void sphere::set_radius(double r)
{
  radius = r;
}
