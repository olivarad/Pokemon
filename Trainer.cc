#include "Trainer.h"

void Trainer::modify_trainer() // Used to make and modify characters
{
    cout << endl; // Formatting
    cin.ignore(); // Ignore the \n character that fucks with my getline function
    cout << "Please enter your first name: ";
    getline(cin, first_name);
    cout << "Please enter your middle name: ";
    getline(cin, middle_name);
    cout << "Please enter your last name: ";
    getline(cin, last_name);
    cout << "Please enter your pronouns: ";
    getline(cin, pronouns);
}

void Trainer::display_data()
{
    int menu_choice = 0;
    cout << "\n       Name: " << first_name << " " << middle_name << " " << last_name << endl; // Displayes the character name
    do
    {
        do
        {
            cout << "Please choose the data to be displayed\n"; // Prompts for user choice
            cout 
            << "1. Pronouns\n"
            << "2. Birthday\n"
            << "3. Hometown\n"
            << "4. Finance\n"
            << "5. Cancel\n";
            cin >> menu_choice;
        } while(1 > menu_choice || menu_choice > 5);
        switch(menu_choice)
        {
            case 1: // Pronouns
                cout << "\n   Pronouns: " << pronouns << endl << endl; // Displays pronouns
                break;
            case 2: // Birthday
                cout << "\n   Birthday: " << birthday << endl << endl; // Displays the birthday
                break;
            case 3: // Hometown
                cout << "\n   Hometown: " << hometown << endl << endl; // Displays the hometown
                break;
            case 4: // Finance
                cout << "\nPokedollars: " << pokedollars << endl << endl; // Displays finance
                break;
        }
    } while (menu_choice != 5);
}