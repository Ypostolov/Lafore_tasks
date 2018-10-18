//circles.cpp
// круги в качество Объектов
#ifndef _INC_WCONSOLE    //этот файл не должен включаться
#define _INC_WCONSOLE    //дважды в тот же исходный файл

#include <windows.h>     //для консольных функций Windows
#include <conio.h>       //для kbhit(), getche()
#include <math.h>        //для sin, cos

enum fstyle { SOLID_FILL, X_FILL,      O_FILL,
              LIGHT_FILL, MEDIUM_FILL, DARK_FILL };

enum color {
   cBLACK=0,     cDARK_BLUE=1,  cDARK_GREEN=2, DARK_CYAN=3,
   cDARK_RED=4,  cDARK_MAGENTA=5, cBROWN=6,  cLIGHT_GRAY=7,
   cDARK_GRAY=8, cBLUE=9,         cGREEN=10,     cCYAN=11,
   cRED=12,      cMAGENTA=13,     cYELLOW=14,    cWHITE=15 };
//---------------------------------------------------------
void init_graphics();
void set_color(color fg, color bg = cBLACK);
void set_cursor_pos(int x, int y);
void clear_screen();
void wait(int milliseconds);
void clear_line();
void draw_rectangle(int left, int top, int right, int bottom);
void draw_circle(int x, int y, int rad);
void draw_line(int x1, int y1, int x2, int y2);
void draw_pyramid(int x1, int y1, int height);
void set_fill_style(fstyle);
#endif /* _INC_WCONSOLE */  //  для функций консольной графики

class circle
{
protected:
    int xCo,yCo;    //координаты центра
    int radius;
    color fillcolor;
    fstyle fillstyle;   //стиль заполнения
public:
    void set(int x, int y, int r, color fc, fstyle fs)
    {
        xCo = x;
        yCO = y;
        radius = r;
        fillcolor = fc;
        fillstyle = fs;
    }
    void draw(){
        set_color(fillcolor);
        set_fill_style(fillstyle);
        draw_circle(xCo,yCo, radius);

    }
 };


int main()
{
    init_graphics();
    circle c1;
    circle c2;
    circle c3;
    c1.set(15,7,5, cBLUE, X_FILL);
    c2.set(41,12,7, cRED, O_FILL);
    c3.set(65,18,4, cGREEN, MEDIUM_FILL);

    c1.draw();
    c2.draw();
    c3.draw();
    set_cursor_pos(1,25);




    return 0;
}
