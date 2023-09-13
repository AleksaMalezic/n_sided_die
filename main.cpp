#include<iostream>
#include<stdlib.h>
#include<time.h>
#include<exception>
#include<string>
using namespace std;

#include "die.h"

class GError : public exception {
public:
    const char* what() const override {
        return "error: number must be positive integer";
    }
};

void draw_die(int);

bool check_if_int(string s) {
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i]) == false) return false;
    }
    return true;
}

int main()
{
    try {
        Die d;
        srand(time(0));
        string num_of_sides;
        string num_of_rolls;
        int number_of_sides;
        int number_of_rolls;
        float counter = 0;

        cout << "Input the number of sides of a die: " << endl;
        cin >> num_of_sides;
        if (check_if_int(num_of_sides) == false) throw GError();
        else number_of_sides = stoi(num_of_sides);
        if (number_of_sides == 0) throw GError();
        cout << "Input the number of rolls: " << endl;
        cout << "(If you roll once, you will get a visual die.)" << endl;
        cin >> num_of_rolls;
        if (check_if_int(num_of_rolls) == false) throw GError();
        else number_of_rolls = stoi(num_of_rolls);
        if (number_of_sides == 0) throw GError();


        if (number_of_rolls == 1) {
            d.roll(number_of_sides);
            cout << "Die is showing number " << d.get_n() << endl;
            if (number_of_sides <= 6) {
                draw_die(d.get_n());
            }
        }
        else {
            cout << "The numbers are: ";
            for (int i = 0; i < number_of_rolls; i++) {
                d.roll(number_of_sides);
                counter += d.get_n();
                cout << d.get_n();
                if (i != number_of_rolls) { cout << ", "; }
            }

            float average = counter / number_of_rolls;
            cout << "\n" << "The average number on the die is: " << average << endl;
        }
    }
    catch (GError) {
        cout << GError().what();
    }


    
    return 0;
}

void draw_die(int n) {
    switch (n) {
    case 1:
        cout << "\n" << " o " << "\n" << endl;
        break;
    case 2:
        cout << "o  \n" << "  o" << endl;
        break;
    case 3:
        cout << "o   \n" << "  o  \n" << "    o" << endl;
        break;
    case 4:
        cout << "o o\n" << "o o" << endl;
        break;
    case 5:
        cout << "o   o\n" << "  o  \n" << "o   o" << endl;
        break;
    case 6:
        cout << "o o\n" << "o o\n" << "o o" << endl;
        break;
    }
}