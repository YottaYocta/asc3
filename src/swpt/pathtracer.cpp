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
  const int ray_depth {9};

  for (int i {0}; i < canv.get_height(); i++)
  {
    for (int j {0}; j < canv.get_width(); j++)
    {
      double u {static_cast<double>(j) / canv.get_width()};
      double v {static_cast<double>(i) / canv.get_height()};
      double shade {0};
      trace_path(ray {origin, lower_left_corner + vertical * v + horizontal * u - origin}, ray_depth, 1, shade); 
      canv.set(j, canv.get_height() - 1 - i, shade * 255.99);
    }
  }
}

double pathtracer::trace_path(const ray& r, int depth, double mask, double& accumulated) const
{
  if (depth <= 0)
    return accumulated;
  primitive::intersection_info info {};
  if (world.intersects(r, info, 100))
  {
    point3 offset_intersection {info.intersection + info.normal * 0.001};
    mask *= 0.5;
    double l_intensity {0};
    for (const shared_ptr<emitter>& light : world.get_lights())
    {
      primitive::intersection_info temp {};
      if (!world.intersects(ray {offset_intersection, normalized(light->rand_point() - offset_intersection)}, temp, 100))
      {
        l_intensity += light->get_intensity();
      }
    }
    if (l_intensity >= 0)
      accumulated += mask * l_intensity; 
    return trace_path(ray {offset_intersection, info.normal + rand_normalized()}, depth - 1, mask, accumulated);
  }
  accumulated += 0.5 * 0.1;
  return accumulated;
}
