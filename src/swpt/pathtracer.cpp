#include <swpt/pathtracer.h>

pathtracer::pathtracer(canvas& c, scene& s) : canv {c}, world {s} {}

void pathtracer::trace_image(int samples)
{
  const point3 origin {0, 0, 0};
  const double aspect {static_cast<double>(canv.get_width()) / canv.get_height()};
  const double char_aspect {1.0 / 2.5};
  const vec3 vertical {0, 2, 0};
  const vec3 horizontal {2 * aspect * char_aspect, 0, 0};
  const vec3 focal {0, 0, 1};
  const vec3 lower_left_corner {origin - vertical / 2 - horizontal / 2 - focal};
  const int ray_depth {9};

  for (int i {0}; i < canv.get_height(); i++)
  {
    for (int j {0}; j < canv.get_width(); j++)
    {
      for (int a {0}; a < samples; a++)
      {
        double u {(j + rand_double()) / canv.get_width()};
        double v {(i + rand_double()) / canv.get_height()};
        double shade {0};
        trace_path(ray {origin, normalized(lower_left_corner + vertical * v + horizontal * u - origin)}, ray_depth, 1, shade); 
        canv.add(j, canv.get_height() - 1 - i, (shade * 255.99) / samples);
      }
    }
  }
}

double pathtracer::trace_path(ray r, int depth, double mask, double& accumulated) const
{
  path_info info {};
  while (depth >= 0 && world.intersects(r, info, 100))
  {
    point3 offset_intersection {info.intersection + info.normal * 0.001};
    depth--;
    mask *= 0.5;
    double l_intensity {0};
    for (const shared_ptr<emitter>& light : world.get_lights())
    {
      path_info temp {};
      if (!world.intersects(ray {offset_intersection, normalized(light->rand_point() - offset_intersection)}, temp, 100))
      {
        l_intensity += light->get_intensity();
      }
    }  
    if (l_intensity >= 0)
      accumulated += mask * l_intensity; 
    r = ray {offset_intersection, info.normal + rand_normalized()};
  }
  accumulated += 0.5 * 0.1;
  return accumulated;
}
