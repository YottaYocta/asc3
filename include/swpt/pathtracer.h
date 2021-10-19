#ifndef PATHTRACER_H
#define PATHTRACER_H

#include <utils/canvas.h>
#include <utils/utils.h>
#include <core/vec.h>
#include <core/ray.h>
#include <core/scene.h>
#include <swpt/intersectable.h>

class pathtracer
{
  private:
    vector<shared_ptr<intersectable>> objects;
    canvas& canv;
  public:
    pathtracer(canvas& c, scene& s);
    void trace_image();
    double trace_path(const ray& r) const;
};

#endif
