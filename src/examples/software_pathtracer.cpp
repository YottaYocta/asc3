#include <utils/canvas.h>
#include <utils.h>
#include <swpt/pathtracer.h>
#include <core.h>

int main()
{
  canvas canv {100, 50};
  scene s {};
  shared_ptr<primitive> sphere1 {make_shared<sphere>(vec3 {0, 0, -1}, 0.5)};
  shared_ptr<primitive> sphere2 {make_shared<sphere>(vec3 {0, -100.5, -1}, 100)};
  shared_ptr<emitter> light {make_shared<sphere_light>(vec3 {10, 2, 0}, 2, 1.48)};
  s.add(sphere1);
  s.add(sphere2);
  s.add(light);
  pathtracer p {canv, s};
  p.trace_image();
  cout << canv.to_string(true);
  return 0;
}
