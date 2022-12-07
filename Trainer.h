#pragma once // Tells the compiler to onlt include this once
#include <iostream>
using namespace std;

class Trainer // Class decleartion
{
    public:
        string first_name;
        string middle_name;
        string last_name;
        string pronouns;
        string birthday;
        string hometown;

        int pokedollars = 3000; // Starting currency
        int badge_count = 0; // Starting badge count (Determines pokemon that listen to you, encounter level, and shop inventory)

        void modify_trainer(); // modify_trainer declaration

        void display_data(); // display_data declearation

    private:

};
