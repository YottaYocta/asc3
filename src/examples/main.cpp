#include <iostream>
#include <core/vec.h>
#include <utils/canvas.h>

int main()
{
  canvas c {100, 50};
  for (int i {0}; i < c.get_height(); i++)
  {
    for (int j {0}; j < c.get_width(); j++)
    {
      c.set(j, i, i);
    }
  }
  std::cout << c.to_string(true);
  return 0;
}
