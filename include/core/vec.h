#ifndef VEC_H
#define VEC_H

#include <iostream>
#include <cmath>

struct vec3
{
  double x, y, z;
  vec3() : vec3(0, 0, 0) {}
  vec3(double a, double b, double c) : x {a}, y {b}, z {c} {}
  double length_squared() const { return x * x + y * y + z * z; }
  double length() const { return sqrt(length_squared()); }
  vec3& operator += (const vec3& v) { x += v.x; y += v.y; z += v.z; return *this; }
  vec3& operator -= (const vec3& v) { x -= v.x; y -= v.y; z -= v.z; return *this; }
  vec3& operator *= (double a) { x *= a; y *= a; z *= a; return *this;}
  vec3& operator /= (double a) { x /= a; y /= a; z /= a; return *this;}
};

inline std::ostream& operator << (std::ostream& os, const vec3& v) { return os << v.x << ' ' << v.y << ' ' << v.z; }
inline vec3 operator + (const vec3& a, const vec3& b) { return vec3 {a.x + b.x, a.y + b.y, a.z + b.z}; }
inline vec3 operator - (const vec3& a, const vec3& b) { return vec3 {a.x - b.x, a.y - b.y, a.z - b.z}; }
inline vec3 operator * (const vec3& a, const vec3& b) { return vec3 {a.x * b.x, a.y * b.y, a.z * b.z}; }
inline vec3 operator / (const vec3& a, const vec3& b) { return vec3 {a.x / b.x, a.y / b.y, a.z / b.z}; }
inline vec3 operator * (const vec3& a, double b) { return vec3 {a.x * b, a.y * b, a.z * b}; }
inline vec3 operator * (double b, const vec3& a) { return vec3 {a.x * b, a.y * b, a.z * b}; }
inline vec3 operator / (const vec3& a, double b) { return vec3 {a.x / b, a.y / b, a.z / b}; }
inline vec3 operator / (double b, const vec3& a) { return vec3 {a.x / b, a.y / b, a.z / b}; }
inline double dot(const vec3& a, const vec3& b) { return a.x * b.x + a.y * b.y + a.z * b.z; }
inline vec3 cross(const vec3& a, const vec3& b) { return vec3 {
  a.y * b.z - a.z * b.y,
  a.x * b.z - a.z * b.x,
  a.x * b.y - a.y * b.x
}; }
inline vec3 normalized(const vec3& a) { return a / a.length(); }

using point3 = vec3;
using rgb = vec3;

#endif
