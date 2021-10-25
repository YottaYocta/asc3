#ifndef MATERIAL_H
#define MATERIAL_H

#include <core/ray.h>
#include <core/primitives.h>
#include <utils.h>

class path_info;

class material
{
  public:
    virtual bool scatter(const ray& r_in, path_info& info, ray& r_out, double& mask) const = 0;
};

class lambertian : material
{
  private:
    double color;
  public:
    lambertian(double c);
    virtual bool scatter(const ray& r_in, path_info& info, ray& r_out, double& mask) const override;
};

#endif
