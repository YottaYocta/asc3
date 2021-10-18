#include <utils/canvas.h>
#include <utils/utils.h>

int main()
{
  canvas c {70, 50};
  int total {c.get_height() * c.get_width()};
  int count {0};
  for (int i {0}; i < c.get_height(); i++)
  {
    for (int j {0}; j < c.get_width(); j++)
    {
      count++;
      c.set(j, i, 255.99 * count / (total + 1));
    }
  }
  cout << c.to_string(true);
  return 0;
}
