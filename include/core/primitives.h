#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <core/vec.h>
#include <core/ray.h>

class primitive
{
  public:
    struct intersection_info
    {
      point3 intersection;
      vec3 normal;
    };
    virtual bool intersects(const ray& r, primitive::intersection_info& info) const = 0;
};

class sphere : public primitive
{
  protected:
    point3 center;
    double radius;
  public:
    sphere();
    sphere(const point3& c, double d);
    const vec3& get_center() const;
    void set_center(const vec3& c);
    double get_radius() const;
    void set_radius(double r);
    virtual bool intersects(const ray& r, primitive::intersection_info& info) const override;
};

#endif
