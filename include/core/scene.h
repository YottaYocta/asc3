#ifndef SCENE_H
#define SCENE_H

#include <core.h>
#include <utils.h>

class scene
{
  private:
    vector<shared_ptr<primitive>> objects;
    vector<shared_ptr<emitter>> lights;
  public:
    scene();
    void add(shared_ptr<primitive>& obj_ptr); 
    const vector<shared_ptr<primitive>>& get_objects() const;
    const vector<shared_ptr<emitter>>& get_lights() const;
};

#endif
