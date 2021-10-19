#include <swpt/intersectable.h>

sect_sphere::sect_sphere() : sphere() {}

sect_sphere::sect_sphere(const sphere& s) : sphere {s} {}

bool sect_sphere::intersects(const ray& r) const
{
  vec3 oc {r.origin - transform};
  double a {r.dir.length_squared()}; 
  double b {dot(r.dir, oc)};
  double c {oc.length_squared() - radius * radius}; 
  double discriminant {b * b - 4 * a * c};
  if (discriminant < 0)
    return false;
  return true;
}
