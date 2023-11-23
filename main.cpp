#include "inc/aufgabe10.cpp"
#include <iostream>
#include <limits>
#include <array>
using namespace std;

struct Program_State
{
    unsigned long long int num_of_field{};
    unsigned long long int occupied_field{};
    bool in_menu{true};
};

signed long long int get_number_input(string input_message, string error_message)
{

    bool input_validity = false;
    signed long long int input{};
    while (input_validity != true)
    {
        cout << input_message << endl;
        cin >> input;
        if (!cin)
        {
            cout << "" << endl
                 << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
                 << error_message << endl
                 << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
                 << "" << endl;

            cin.clear();
            cin.ignore(256, '\n');
        }

        else
        {
            input_validity = true;
        }
    };
    return input;
};

void aufgabe_11()
{
    Program_State state{};
    state.occupied_field = 0;
    array<signed long long int, 3> num_array{};
    state.num_of_field = num_array.max_size();

    while (state.in_menu)
    {
        char menu_input_ok{};
        string menu_input{};

        cout << "" << endl
             << "" << endl
             << "Menu:" << endl
             << "'i' oder 'I' - Eingabe eines neuen Werts am Ende des bisher gefüllten Bereichs " << endl
             << "'s' oder 'S - Gibt die Anzahl der belegten Felder aus." << endl
             << "'o' oder 'O'  - Gibt alle belegten Felder aus." << endl
             << "'d' oder 'D - Löscht das erste Element (Feld 0) und verschiebt alle Elemente um eine Stelle nach vorn. " << endl
             << "'q' oder 'Q' - Beendet das Programm." << endl
             << "" << endl
             << "" << endl;
        cin >> menu_input;

        if (menu_input.length() > 1)
        {
            menu_input_ok = 'r';
        }
        else
        {
            menu_input_ok = menu_input[0];
        }

        switch (menu_input_ok)
        {
        case 'd':
        case 'D':
            if (state.occupied_field == 0)
            {
                cout << "Es gibt nichts auf dem Array zu löschen" << endl;
                break;
            }
            else
            {
                for (unsigned long long int itr = 0; itr < state.occupied_field - 1; itr += 1)
                {
                    num_array[itr] = num_array[itr + 1];
                }
                state.occupied_field -= 1;
            }
            break;
        case 'o':
        case 'O':
            if (state.occupied_field == 0)
            {
                cout << "Es gibt nichts auf dem Array" << endl;
                break;
            }
            else
            {
                for (unsigned long long int itr = 0; itr <= state.occupied_field - 1; itr += 1)
                {
                    cout << "Platz auf dem Array: " << itr + 1 << " hat die Wert: " << num_array[itr] << endl;
                }
                break;
            }
            break;
        case 'i':
        case 'I':
            if (state.occupied_field == state.num_of_field)
            {
                cout << "Es gibt kein Platz mehr auf dem Array" << endl;
                break;
            }
            else
            {
                long long int input = get_number_input("Eingabe eines neuen Werts am Ende des bisher gefüllten Bereichs: ", "VCL WTF");
                num_array[state.occupied_field] = input;
                state.occupied_field += 1;
                break;
            }
            break;
        case 'S':
        case 's':
            cout << "Anzahl der belegten Felder: " << state.occupied_field << endl;
            break;

        case 'q':
        case 'Q':
            state.in_menu = false;
            break;

        default:
            cout << "" << endl
                 << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
                 << "Bitte geben Sie eine gültige Option an" << endl
                 << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl
                 << "" << endl;
            break;
        }
    }
};

int main()
{
    aufgabe_11();
    return 0;
}