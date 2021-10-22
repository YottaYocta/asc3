#include <core/materials.h>

lambertian::lambertian(double c) : color {c} {}

bool lambertian::scatter(const ray& r_in, intersection_info& info, ray& r_out, double& mask) const
{
  mask *= color;
  point3 offset_intersection {info.intersection + info.normal * 0.001};
  r_out = ray {offset_intersection, info.normal + rand_normalized()};
  return true; 
}
