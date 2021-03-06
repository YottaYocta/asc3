#ifndef CANVAS_H
#define CANVAS_H

#include <utils.h>

class canvas
{
  private:
    vector<vector<double>> buffer;
    string pallete;
  public:
    canvas();
    canvas(int w, int h);
    canvas(int w, int h, string p);
    bool set(int x, int y, double val);
    bool add(int x, int y, double val);
    string to_string(bool newlines) const;
    int get_width() const;
    int get_height() const;
    void set_pallete(string str);
    string get_pallete() const;
};

#endif
