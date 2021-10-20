#include <core/primitives.h>
#include <utils/utils.h>

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

bool sphere::intersects(const ray& r) const
{
  cout << r.dir << '\n';
  vec3 oc {r.origin - center};
  double a {r.dir.length_squared()}; 
  double b {dot(r.dir, oc)};
  double c {oc.length_squared() - radius * radius}; 
  double discriminant {b * b - a * c};
  if (discriminant < 0)
    return false;
  return true;

}
