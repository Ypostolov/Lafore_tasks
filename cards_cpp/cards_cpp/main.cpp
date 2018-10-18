#include <iostream>

const int clumbs = 0;
const int diamonds = 1;
const int hearts = 2;
const int spades = 3;
const int jack = 11;
const int queen = 12;
const int king = 13;
const int ace = 14;


  struct card
   {
     int number;
     int suit;
   };


int main()
{
    card temp, chosen, prize;
    int position;
    card card1 = {7, clumbs};
    std::cout << "Карта_1: 7 треф\n";
    card card2 = {jack, hearts};
    std::cout << "Карта_2: валет червей\n";
    card card3 = {ace, spades};
    std::cout << "Карта_1: туз пик\n";

    prize = card3;

    std::cout << "Меняем местами карту 1 и карту 3...\n";
    temp = card3;
    card3 = card1;
    card1 = temp;

    std::cout << "Меняем местами карту 2 и карту 3...\n";
    temp = card3;
    card3 = card2;
    card2 = temp;

    std::cout << "Меняем местами карту 1 и карту 2...\n";
    temp = card2;
    card2 = card1;
    card1 = temp;

    std::cout << "На какой позиции (1,2 или 3) теперь туз пик?";
    std::cin >> position;
    switch(position){


        case 1: chosen = card1;break;
        case 2: chosen = card2;break;
        case 3: chosen = card3;break;
    };

    if (chosen.number == prize.number &&
            chosen.suit == prize.suit)
        std :: cout <<"Правильно! Вы выйграли";
    else
        std::cout <<"Неверно! Вы проиграли";

    return 0;
}
