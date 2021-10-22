#ifndef SCENE_H
#define SCENE_H

#include <core/primitives.h>
#include <core/lights.h>
#include <utils.h>

class scene : primitive
{
  private:
    vector<shared_ptr<primitive>> objects;
    vector<shared_ptr<emitter>> lights;
  public:
    scene();
    void add(shared_ptr<primitive>& obj_ptr); 
    void add(shared_ptr<emitter>& obj_ptr); 
    const vector<shared_ptr<primitive>>& get_objects() const;
    const vector<shared_ptr<emitter>>& get_lights() const;
    virtual bool intersects(const ray& r, intersection_info& info, double far) const override;
};

#endif
