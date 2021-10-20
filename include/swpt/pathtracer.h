#ifndef PATHTRACER_H
#define PATHTRACER_H

#include <utils/canvas.h>
#include <utils/utils.h>
#include <core/vec.h>
#include <core/ray.h>
#include <core/scene.h>
#include <core/primitives.h>

class pathtracer
{
  private:
    scene& world;
    canvas& canv;
  public:
    pathtracer(canvas& c, scene& s);
    void trace_image();
    double trace_path(const ray& r) const;
};

#endif
