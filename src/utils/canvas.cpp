#include <utils/canvas.h>

canvas::canvas() : canvas(10, 10) {}

canvas::canvas(int w, int h) : buffer(h, vector<double>(w, 0)) {}

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
        output += buffer[i][j];
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
        output += buffer[i][j];
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
