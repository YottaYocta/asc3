#include <utils/canvas.h>
#include <utils/utils.h>

int main()
{
  canvas canv {100, 50};
  cout << canv.to_string(true);
  return 0;
}
