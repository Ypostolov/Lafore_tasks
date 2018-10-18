//englobj.cpp
//длины в английской системе в качестве объектов

#include <iostream>

class Distance
{
    private:
        int feet;
        float inches;
    public:
    void setdist(int ft, float in)
        {
            feet = ft; inches = in;
        }
        void  getdist() // ввод значения полей с клавиатуры
        {
         std::cout << "\n введите число футов: ";
         std::cin>>feet;
         std::cout << "\n введите число дюймов: ";
         std::cin>>inches;
        }
    void showdist ()   //вывод полей на экран
    {
        std::cout << feet << "\'-" << inches << "\"";
    }
};

int main()
{
    Distance dist1, dist2;
    dist1.setdist(11, 6.25);
    dist2.getdist();
    std::cout << "\ndist1 - "; dist1.showdist();
    std::cout << "\ndist2 - "; dist2.showdist();
    std::cout << std::endl;
    return 0;
}
