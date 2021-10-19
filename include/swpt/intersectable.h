#ifndef INTERSECTABLE_H
#define INTERSECTABLE_H

#include <core/vec.h>
#include <core/ray.h>
#include <core/primitives.h>

#define INTERSECTION_NEAR 0.001
#define INTERSECTION_FAR 1000

class intersectable
{
  public:
    virtual bool intersects(const ray& r) const = 0;
};

class sect_sphere : public sphere, public intersectable
{
  public:
    sect_sphere();
    sect_sphere(const sphere& s);
    virtual bool intersects(const ray& r) const override;
};

#endif
