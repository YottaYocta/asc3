#ifndef PRIMITIVES_H
#define PRIMITIVES_H

#include <core/vec.h>

class primitive
{
  protected:
    point3 transform;
  public:
    primitive(const vec3& t);
    virtual vec3 get_transform() const = 0;
    virtual void set_transform(const point3& p) = 0;
};

class sphere : public primitive
{
  protected:
    double radius;
  public:
    sphere();
    sphere(const vec3& t, double d);
    vec3 get_transform() const override;
    void set_transform(const vec3& t) override;
    double get_radius() const;
    void set_radius(double r);
};

#endif
