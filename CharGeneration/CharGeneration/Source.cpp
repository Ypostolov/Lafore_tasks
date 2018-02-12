#include <iostream>;
#include <ctime>;
using namespace std;

int numberFromRange(int max, int min)
{
    return (rand() % (max - min + 1) + min);
}

double average(double x1, double x2, double x3)
{
    return ((x1 + x2 + x3) / 3.0);
}

void  zeroizer(int * array, int length1)
{
    for (int i = 0; i < length1; i++)
    {
        array[i] = 0;
    }
}

class CMyClass
{
public:
    int x;
    int y;
};

void myCaclulations(CMyClass * outMyClass)
{
    outMyClass->x = 5;
    outMyClass->y = 6;
}

char* nightCount(int x)
{
    char* var;
    switch (x)

    {

    case 1:
    {
              var = "OnE";
    }
        break;

    case 2:
    {
              var = "two";
    }
        break;
    case 3:
    {
              var = "three";
    }
        break;

    default:
    {
               var = "unknown";
    }
    }
    return var;
}
void main()
{

    cout << nightCount(1) << endl;
    int array[10];
    zeroizer(array, 10);
    for (int i = 0; i < 10; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;

    cout << average(2.3, 3.5, 4.1) << endl;

    cout << "Random simbols: " << endl << endl;



    srand(time(nullptr));

    int length = rand() % 200 + 1;

    char* line = new char[length];


    for (int i = 0; i < length - 1; i++)
    {
        line[i] = (char)numberFromRange(122, 97);
    }

    line[length - 1] = '\0';
    cout << line << endl;

    for (int i = 0; i < length; i++)
    {
        cout << line[i];
    }
    cout << endl;

    delete line;
}

