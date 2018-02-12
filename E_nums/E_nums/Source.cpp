#include <iostream>
using namespace std;

// Класс Одежда, есть поля брэнд, модель, пол(enum(м,ж, уни)),
//год, сезон (енум (весна , лето, зима, осень)), 
//У одежды есть массив структур (версии модели (цена, размер, рисунок)) 

enum Sex
{
    MALE = (1 << 0),
    FEMALE = (1 << 1),
    UNISEX = MALE | FEMALE,
    UNKNOWN = 0,

};

enum Season
{
    SUMMER = (1 << 0),
    AUTUMN = (1 << 1),
    WINTER = (1 << 2),
    SPRING = (1 << 3),
    DEMISEASON = SPRING | SUMMER,
    UNKNOWN = 0,
};
struct ModelVersion
{
    int price;
    double size;
    char* print;

    ModelVersion()
    {
        price = 0;
        size = 0;
        print = "";
    }

    ModelVersion(int inPrice, double inSize, char* inPrint)
    {
        price = inPrice;
        size = inSize;
        print = inPrint;
    }



};


class Clothes
{
    char* brand;
    char* model;
    int year;
    Sex sex;
    Season season;
    ModelVersion * modelVersions;

    Clothes()
    {
        brand = "";
        model = "";
        year = 0;
        sex = Sex::UNKNOWN;
        season = Season::UNKNOWN;





    }









};

enum sex;


void main()
{





}