#include <core/primitives.h>

sphere::sphere() : sphere(vec3 {0, 0, -1}, 1) {}

sphere::sphere(const vec3& c, double r) : center {c}, radius {r} {}

const vec3& sphere::get_center() const
{
  return center;
}

void sphere::set_center(const vec3& c)
{
  center = c;
}

double sphere::get_radius() const
{
  return radius;
}

void sphere::set_radius(double r)
{
  radius = r;
}

bool sphere::intersects(const ray& r, path_info& info, double far) const
{
  vec3 oc {r.origin - center};
  double a {r.dir.length_squared()}; 
  double b {dot(r.dir, oc)};
  double c {oc.length_squared() - radius * radius}; 
  double discriminant {b * b - a * c};
  if (discriminant < 0)
    return false;
  double t = (-b - sqrt(b * b - a * c)) / a;
  if (t < 0.001 || t > far)
  {
    t = (-b + sqrt(b * b - a * c)) / a;
    if (t < 0.001 || t > far)
      return false;
  }
  info.intersection = point3 {r.origin + r.dir * t};
  info.normal = normalized(info.intersection - center);
  info.t = t;
  info.material_hit = material;
  return true;
}
