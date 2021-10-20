#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <core/vec.h>
#include <core/ray.h>

class primitive
{
  public:
    virtual bool intersects(const ray& r) const = 0;
};

class sphere : public primitive
{
  protected:
    point3 center;
    double radius;
  public:
    sphere();
    sphere(const vec3& t, double d);
    const vec3& get_center() const;
    void set_center(const vec3& c);
    double get_radius() const;
    void set_radius(double r);
    virtual bool intersects(const ray& r) const override;
};

#endif
