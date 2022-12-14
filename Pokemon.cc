/**
 * @file pokemon.cc
 * @author Olivia Radecki (olivia.radecki02@gmail.com)
 * @brief A program to assist with pokemon D&D
 * @date 2022-12-05
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include "Trainer.h"
using namespace std;

/**
 * Add Pokemart
 * Add inventory
 * Add Pokemon stats
 */

struct Badges
{

};

class Pokeballs
{

};

class Pokemon
{
    public:

    private:
    
};

class Party
{
    public:

    private:
    
};

void display_caracter_vector(const vector<Trainer> character_vector);

bool menu(vector<Trainer>& player_character_trainers, int& player_character_count);

int main()
{
    int player_character_count = 0;
    bool quit = 0;
    vector<Trainer> player_character_trainers; // A vector to track player character trainers

    do
    {
        quit = menu(player_character_trainers, player_character_count); // Runs the menu
    } while(quit != 1);
    
    return 0;
}

void display_caracter_vector_names(const vector<Trainer> character_vector)
{
    for(unsigned  int i = 0; i < character_vector.size(); i++) // Runs through every index of character
    {
        cout << (i + 1) << ". " << character_vector[i].first_name << " " << character_vector[i].middle_name << " " << character_vector[i].last_name << endl; // Prints the characters full name
    }
}

bool menu(vector<Trainer>& player_character_trainers, int& player_character_count)
{
    int user_choice = 0; // Used in menu switch statement
    bool quit = 0; // Sentinal value to quit main
    unsigned int character_choice = 0; // Index tracker for character in options 2 and 3
    do
    {
        cout 
        << "\nMenu\n1. Make a trainer\n"
        << "2. Modify a trainer card\n"
        << "3. Display a trainers data\n"
        << "4. Quit\n";
        cin >> user_choice; // obtains the menu choice
        cout << endl; // Formatting
    } while (1 > user_choice || user_choice > 4); // Ensures a valid option is entered for user_choice

    switch (user_choice)
    {
        case 1: // Make a trainer
            player_character_trainers.push_back(Trainer()); // Creates another index in the player character vector
            player_character_trainers[player_character_count].modify_trainer(); // Runs the modify character function
            cout << "Please enter your date of birth in the format mm/dd: ";
            getline(cin, player_character_trainers[player_character_count].birthday);
            cout << "Please enter your hometown: ";
            getline(cin, player_character_trainers[player_character_count].hometown);
            player_character_count++; // Itterates the count of player characters
            break;
        case 2: // Modify a trainer
            if (player_character_trainers.size() > 0) // Characters exsist to be modified
            {
                cout << "Pick a character\n";
                do
                {
                    display_caracter_vector_names(player_character_trainers); // Runs the display character vector function
                    cout << player_character_trainers.size() + 1 << ". cancel\n\n"; // Cancel option
                    cin >> character_choice; // Obtains the users choice
                } while (1 > character_choice || character_choice > (player_character_trainers.size() + 1)); // Ensures a valid selection is made
        
                if(character_choice != (player_character_trainers.size() + 1)) //A valid choice other than cancel has been made
                {
                    character_choice--; // Turns the input value into an index
                    player_character_trainers[character_choice].modify_trainer(); // Runs the modify character function
                    player_character_count++; // Itterates the count of player characters
                } 
                else if(character_choice == (player_character_trainers.size() + 1)) // Cancel is selected
                {
                    cout << "canceled\n";
                }
            }
            else // There are no characters to modify
            {
                cout << "There are no characters to modify\n";
            }
            break;
        case 3: // Display a trainers data
            if (player_character_trainers.size() > 0) // Characters exsist to be modified
            {
                cout << "Pick a character\n";
                do
                {
                    display_caracter_vector_names(player_character_trainers); // Runs the display character vector function
                    cout << player_character_trainers.size() + 1 << ". cancel\n\n"; // Cancel option
                    cin >> character_choice; // Obtains the users choice
                } while (1 > character_choice || character_choice > (player_character_trainers.size() + 1)); // Ensures a valid selection is made
        
                if(character_choice != (player_character_trainers.size() + 1)) //A valid choice other than cancel has been made
                {
                    character_choice--; // Turns the input value into an index
                    player_character_trainers[character_choice].display_data(); // Runs the modify character function
                } 
                else if(character_choice == (player_character_trainers.size() + 1)) // Cancel is selected
                {
                    cout << "canceled\n";
                }
            }
            else // There are no characters to modify
            {
                cout << "There is no character data to display\n";
            }
            break;
        case 4: // Quit
            quit = 1; // Sets the quit sentinal value to quit the program
            break;
    }
    return quit;
}