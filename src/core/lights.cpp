#include <core/lights.h>

emitter::emitter(double i) : intensity {i} {}

double emitter::get_intensity() const
{
  return intensity;
}

void emitter::set_intensity(double i)
{
  intensity = i;
}

sphere_light::sphere_light() : sphere_light(point3 {0, 0, -1}, 0.5, 5) {}

sphere_light::sphere_light(const point3& c, double r, double i) : sphere(c, r), emitter(i) {}

point3 sphere_light::rand_point() const 
{
  return rand_in_unit_sphere() * radius + center;  
}
