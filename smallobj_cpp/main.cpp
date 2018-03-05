// smallobj.cpp
//демонстрирует небольшой объект
#include <iostream>

class smallobj  //определение класса
    {
 private:
  int somedata;  //поле класса
 public:
  void setdata(int d)  // метод класса, изменяющий знач. поля
  {
    somedata = d;
  }
  void showdata()  //метод класса, отображающий значение поля
  {
    std::cout << "Значение поля равно " << somedata << std::endl;
  }
};

int main() {
  smallobj s1, s2;  // определение двух объектов класс smallob
  s1.setdata(1066);  // вызовы метода setdata()
  s2.setdata(1776);
  s1.showdata();
  s2.showdata();
  return 0;
}
