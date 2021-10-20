#include <swpt/pathtracer.h>

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
  const int ray_depth {5};

  for (int i {0}; i < canv.get_height(); i++)
  {
    for (int j {0}; j < canv.get_width(); j++)
    {
      double u {static_cast<double>(j) / canv.get_width()};
      double v {static_cast<double>(i) / canv.get_height()};
      double shade {trace_path(ray {origin, lower_left_corner + vertical * v + horizontal * u - origin}, ray_depth)}; 
      canv.set(j, canv.get_height() - 1 - i, shade * 255.99);
    }
  }
}

double pathtracer::trace_path(const ray& r, int depth) const
{
  if (depth <= 0)
    return 0.1;
  for (const shared_ptr<primitive>& object : world.get_objects())
  {
    primitive::intersection_info info {};
    if (object->intersects(r, info)) 
    {
      ray random {info.intersection + 0.001 * info.normal, info.normal + rand_normalized()};
      return 0.95 * trace_path(random, depth - 1);
    }
  }
  return 0.5;
}
