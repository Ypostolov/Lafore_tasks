#include <iostream>

// испльзование вложенных структур

struct Distance
{
    int feet;
    float inches;
};

struct Room
{
    Distance length;
    Distance width;
};

using namespace std;

int main()
{
    Room dining;
    dining.length.feet = 13;
    dining.length.inches = 6.5;
    dining.width.feet =10;
    dining.width.inches =0.0;
    // преобразование длины и ширины в вещественный формат
    float l = dining.length.feet + dining.length.inches/12;
    float w = dining.width.feet + dining.width.inches/12;
    std::cout <<"площадь равна " << l*w << " квадратных футов"
              << std::endl;
    return 0;
}
