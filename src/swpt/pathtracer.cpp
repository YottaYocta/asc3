#include <swpt/pathtracer.h>
#include <utils/utils.h>

pathtracer::pathtracer(canvas& c, scene& s) : canv {c}, world {s} {}

void pathtracer::trace_image()
{
  const point3 origin {0, 0, 0};
  const double aspect {static_cast<double>(canv.get_width()) / canv.get_height()};
  const double char_aspect {1.0 / 2.1};
  const vec3 vertical {0, 2, 0};
  const vec3 horizontal {2 * aspect * char_aspect, 0, 0};
  const vec3 focal {0, 0, 1};
  const vec3 lower_left_corner {origin - vertical / 2 - horizontal / 2 - focal};

  for (int i {0}; i < canv.get_height(); i++)
  {
    for (int j {0}; j < canv.get_width(); j++)
    {
      double u {static_cast<double>(j) / canv.get_width()};
      double v {static_cast<double>(i) / canv.get_height()};
      double shade {trace_path(ray {origin, lower_left_corner + vertical * v + horizontal * u - origin})}; 
      canv.set(j, i, shade * 255.99);
    }
  }
}

double pathtracer::trace_path(const ray& r) const
{
  for (const shared_ptr<primitive>& object : world.get_objects())
  {
    if (object->intersects(r)) 
      return 1;
  }
  return 0;
}
