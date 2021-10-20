#include <utils/canvas.h>
#include <utils.h>

canvas::canvas() : canvas(10, 10, " _.,:;i!|I0#@") {}

canvas::canvas(int w, int h) : canvas (w, h, " _.,:;i!|I0#@") {}

canvas::canvas(int w, int h, string p) : buffer(h, vector<double>(w, 0)), pallete {p} {}

bool canvas::set(int x, int y, double val)
{
  if (x >= buffer[0].size() || x < 0 || y >= buffer.size() || y < 0) 
    return false;
  buffer[y][x] = max(0.0, min(255.99, val));
  return true;
}

bool canvas::add(int x, int y, double val)
{
  if (x >= buffer[0].size() || x < 0 || y >= buffer.size() || y < 0) 
    return false;
  buffer[y][x] = max(0.0, min(255.99, val + buffer[y][x]));
  return true;
}

string canvas::to_string(bool newlines) const
{
  string output {""};
  if (newlines)
  {
    for (int i {0}; i < buffer.size(); i++)
    {
      for (int j {0}; j < buffer[i].size(); j++)
      {
        output += pallete[static_cast<int>(buffer[i][j] / 256 * pallete.length())];
      }
      output += '\n';
    }
  }
  else 
  {
    for (int i {0}; i < buffer.size(); i++)
    {
      for (int j {0}; j < buffer[i].size(); j++)
      {
        output += pallete[static_cast<int>(buffer[i][j] / 256 * pallete.length())];
      }
    }
  }
  return output;
}

int canvas::get_width() const
{
  return buffer[0].size();
}

int canvas::get_height() const
{
  return buffer.size();
}

void canvas::set_pallete(string str)
{
  pallete = str;
}
