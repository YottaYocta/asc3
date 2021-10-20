#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <memory>
#include <iostream>
#include <typeinfo>
#include <random>

using std::vector, std::string, std::max, std::min, std::make_shared, std::shared_ptr, std::static_pointer_cast;
using std::cin, std::cout, std::ostream, std::istream;

inline double rand_double()
{
  static std::mt19937 rng {(std::random_device {})()};
  static std::uniform_real_distribution<double> distribution(0.0, 1.0);
  return distribution(rng);
}

inline double rand_double(double min, double max)
{
  return rand_double() * (max - min) + min;
}

#endif
