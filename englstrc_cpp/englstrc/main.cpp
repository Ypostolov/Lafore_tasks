// ehglstrc.cpp
// английская система ме, реализованная с помощью структуры

#include <iostream>

struct Distance{

    int feet;
    float inches;

    };


int main()
{
    Distance d1,d3;              //определения двух переменных
    Distance d2 = {11, 6.25};     //определиение с инициализацией

    std::cout<< "Enter feet count: ";
    std::cin >> d1.feet;

    std::cout<< "Enter inches count: ";
    std::cin >> d1.inches;

    //Adding lengths d1 and d2 and assigning the result d3

    d3.inches = d1.inches + d2.inches;
    d3.feet = 0;

    if (d3.inches >= 12){
        d3.inches -=12;
        d3.feet++;
    }

    d3.feet +=d1.feet + d2.feet;

    std::cout << d1.feet << "\'-" << d1.inches << "\"+";
    std::cout << d2.feet << "\'-" << d2.inches << "\"=";
    std::cout << d3.feet << "\'-" << d3.inches << "\"\n";

    std::cout << "Hello World!" << std::endl;
    return 0;
}
