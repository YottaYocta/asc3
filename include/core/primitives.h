#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <core/vec.h>
#include <core/ray.h>
#include <core/materials.h>
#include <utils.h>

class material;

struct path_info
{
  double t;
  point3 intersection;
  vec3 normal;
  shared_ptr<material> material_hit;
};

class primitive
{
  public:
    virtual bool intersects(const ray& r, path_info& info, double far) const = 0;
};

class sphere : public primitive
{
  protected:
    point3 center;
    double radius;
    shared_ptr<material> material;
  public:
    sphere();
    sphere(const point3& c, double d);
    const vec3& get_center() const;
    void set_center(const vec3& c);
    double get_radius() const;
    void set_radius(double r);
    virtual bool intersects(const ray& r, path_info& info, double far) const override;
};

#endif
