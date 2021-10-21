#ifndef PATHTRACER_H
#define PATHTRACER_H

#include <utils/canvas.h>
#include <core.h>

class pathtracer
{
  private:
    scene& world;
    canvas& canv;
  public:
    pathtracer(canvas& c, scene& s);
    void trace_image();
    double trace_path(const ray& r, int depth, double mask, double& accumulated) const;
};

#endif
