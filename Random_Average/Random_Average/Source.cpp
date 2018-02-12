#include <ctime>;
#include <iostream>;
using namespace std;


void main()
{

    double average = 0;

    srand(time(nullptr));
    int randNumber = rand() % 150 + 1;
    double * randNumbersAmount = new double[randNumber];

    for (int i = 0; i < randNumber; i++)
    {
        randNumbersAmount[i] = (rand())*0.1;
        cout << randNumbersAmount[i] << " ";
        average = average + randNumbersAmount[i];
    }
    delete randNumbersAmount;
    average = average / randNumber;
    cout << endl << average << endl;
  
}
