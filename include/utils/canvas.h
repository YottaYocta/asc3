#ifndef CANVAS_H
#define CANVAS_H

#include <utils/utils.h>

class canvas
{
  private:
    vector<vector<double>> buffer;
  public:
    canvas();
    canvas(int w, int h);
    bool set(int x, int y, double val);
    bool add(int x, int y, double val);
    string to_string(bool newlines) const;
    int get_width() const;
    int get_height() const;
};

#endif
