#ifndef LIGHTS_H
#define LIGHTS_H

#include <core/vec.h>
#include <core/primitives.h>
#include <utils.h>

class emitter
{
  protected:
    emitter(double i);
    double intensity;
  public:
    double get_intensity() const;
    void set_intensity(double i);
    virtual point3 rand_point() const = 0;
};

class sphere_light : public emitter, public sphere
{
  public:
    sphere_light(); 
    sphere_light(const point3& c, double r, double i);
    virtual point3 rand_point() const override;
};

#endif
