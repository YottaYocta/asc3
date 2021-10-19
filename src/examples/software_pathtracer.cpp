#include <utils/canvas.h>
#include <core/scene.h>
#include <utils/utils.h>
#include <swpt/pathtracer.h>
#include <core/primitives.h>

int main()
{
  canvas canv {100, 50};
  scene s {};
  shared_ptr<primitive> sphere1 {make_shared<sphere>(vec3 {0, 0, -1}, 0.5)};
  s.add(sphere1);
  pathtracer p {canv, s};
  p.trace_image();
  cout << canv.to_string(true);
  return 0;
}
