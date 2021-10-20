#include <core/scene.h>

scene::scene() : objects(0), lights(0) {}

void scene::add(shared_ptr<primitive>& obj_ptr)
{
  objects.push_back(obj_ptr);
}

const vector<shared_ptr<primitive>>& scene::get_objects() const
{
  return objects;
}
