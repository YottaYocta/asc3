#ifndef SCENE_H
#define SCENE_H

#include <core/primitives.h>
#include <utils/utils.h>

class scene
{
  private:
    vector<shared_ptr<primitive>> objects;
  public:
    scene();
    void add(shared_ptr<primitive>& obj_ptr); 
    const vector<shared_ptr<primitive>>& get_objects() const;
};

#endif
