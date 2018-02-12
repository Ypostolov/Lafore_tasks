#include <iostream>
using namespace std;


class Auto
{
    char* brand;
    char* model;
    double price;
    int kms;
    int produceDate;
    

public:

    Auto()
    {
        brand = "";
        model = "";
        price = 0;
        kms = 0;
        produceDate = 0;
    }

    Auto(char* inBrand, char* inModel, double inPrice, int inKms, int inProduceDate)
    {
        brand = inBrand;
        model = inModel;
        price = inPrice;
        kms = inKms;
        produceDate = inProduceDate;
    }

    ~Auto()
    {

    }

    void setBrand(char* Inbrand)
    {
        brand = Inbrand;
    }

    char* getBrand()
    {
        return brand;
    }

    void setModel(char* InModel)
    {
        model = InModel;
    }

    char* getModel()
    {
        return model;
    }

    void setPrice(double inPrice)
    {
        price = inPrice;
    }

    double getPrice()
    {
        return price;
    }

    void setKms(int inKms)
    {
        kms = inKms;
    }

    int getKms()
    {
        return kms;
    }

    void setProduceDate(int inProduceDate)
    {
        produceDate = inProduceDate;
    }

    int getProduceDate()
    {
        return produceDate;
    }
};

enum Seasons
{
    SUMMER = (1 << 0),
    AUTUMN = (1 << 1),
    WINTER = (1 << 2),
    SPRING = (1 << 3),
    UNKNOWN = 0
};

struct Tyre
{
    char * brand;
    int season;
    double diam;
    
    Tyre()
    {
        brand = "";
        season =Seasons::UNKNOWN;
        diam = 0;
    };
    
};

void main()
{
    Auto A;
    Auto B;
    Auto C;
    cout << A.getPrice()<< endl;

    Auto A1("trabant", "901", 5324, 250000, 1976);
    Auto B1("lada", "2101", 105, 355000, 1981);
    Auto C1("vw", "B_7", 200, 30000, 2014);

    Tyre BC;
    BC.brand = "pirelli";
    BC.season = Seasons::AUTUMN | Seasons::WINTER;
    BC.diam = 18;

    if (BC.season & Seasons::WINTER)
    {
        cout << "O'k for winter." << endl;
    }
    else
    {
        cout << "NOT o'k for winter." << endl;
    }

    if (BC.season & Seasons::SUMMER)
    {
        cout << "O'k for summer." << endl;
    }
    else
    {
        cout << "NOT o'k for summer." << endl;
    }

    BC.season = BC.season | Seasons::WINTER; //WINTER ON
    BC.season = BC.season & (~Seasons::WINTER); // WINTER OFF

    if (BC.season & Seasons::WINTER)
    {
        cout << "O'k for winter." << endl;
    }
    else
    {
        cout << "NOT o'k for winter." << endl;
    }

    Tyre KM;
    KM.brand = "fufl";
    KM.season = Seasons::SUMMER;
    BC.diam = 21;


}

