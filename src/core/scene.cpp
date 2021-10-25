#include <core/scene.h>

scene::scene() : objects(0), lights(0) {}

void scene::add(shared_ptr<primitive>& obj_ptr)
{
  objects.push_back(obj_ptr);
}

void scene::add(shared_ptr<emitter>& light_ptr)
{
  lights.push_back(light_ptr);
}

const vector<shared_ptr<primitive>>& scene::get_objects() const
{
  return objects;
}

const vector<shared_ptr<emitter>>& scene::get_lights() const
{
  return lights;
}

bool scene::intersects(const ray& r, path_info& info, double far) const 
{
  bool hit {false};
  for (const shared_ptr<primitive>& object : objects)
  {
    if (object->intersects(r, info, far))
    {
      far = info.t;
      hit = true;
    }
  }
  return hit;
}
