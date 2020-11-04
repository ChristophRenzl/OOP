#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <algorithm>
#include <random>
#include <chrono>

using namespace std;

enum class Color{
    Herz,
    Pik,
    Karo,
    Kreuz
};

enum class Number{
    Sieben,
    Acht,
    Neun,
    Zehn,
    Bube,
    Dame,
    König,
    Ass
};

struct card {
    Color color;
    Number number;
};

array <shared_ptr<card>, 32> makecards()
{
    array<shared_ptr<card>, 32> temp;
    int amount=0;
    for (int col = 0; col < 4; col++)
    {
        for (int numb = 0; numb < 8; numb++)
        {
            auto cards = make_shared<card>();
            cards->color = (Color)col;
            cards->number = (Number)numb;
            temp[amount++] = cards;
        }
    }
    return temp;
}


void printcards(array <shared_ptr<card>, 32> &cards)
{
    for (int i=0; i<32;i++)
    {
        cout << "Karte " << i + 1 << ":";
        switch (cards[i]->color)
        {
            case Color::Herz: cout << "Herz "; break;
            case Color::Karo:cout << "Karo "; break;
            case Color::Kreuz:cout << "Kreuz "; break;
            case Color::Pik:cout << "Pik "; break;
        }

        switch (cards[i]->number)
        {
            case Number::Sieben:cout << "Sieben" << endl; break;
            case Number::Acht:cout << "Acht" << endl; break;
            case Number::Neun:cout << "Neun" << endl; break;
            case Number::Zehn:cout << "Zehn" << endl; break;
            case Number::Bube:cout << "Bube" << endl; break;
            case Number::Dame:cout << "Dame" << endl; break;
            case Number::König:cout << "König" << endl; break;
            case Number::Ass:cout << "Ass" << endl; break;
        }
    }
}

void shuffle(array <shared_ptr<card>, 32>& cards)
{
    // obtain a time-based seed:
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

    shuffle(cards.begin(), cards.end(), std::default_random_engine(seed));

    std::cout << "shuffled elements:"<<endl;
}

int main()
{
    array <shared_ptr<card>, 32> cards;

    cards=makecards();

    printcards(cards);

    shuffle(cards);

    printcards(cards);

}