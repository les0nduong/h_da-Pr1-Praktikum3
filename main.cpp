
#include <iostream>
#include <limits>
#include <array>
#include <vector>
#include <iomanip>
using namespace std;
void ignoreLine()
{
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
struct Koordinator
{
    int xAchse{};
    int yAchse{};
    bool valid{false};
};
Koordinator getValues(int ordnung)
{
    Koordinator input{};
    int inputX{0}, inputY{0};

    while (input.valid == false)
    {
        cout << "Eingabe " << ordnung << "   (x y): ";
        cin >> inputX >> inputY;
        // cout << "outside " << inputX << " " << inputY << endl;
        if (!cin)
        {
            cout << "Falsche Eingabe!" << endl;
            cin.clear();
            ignoreLine();
        }
        else if ((inputX < 51 && inputX >= 1) && (inputY < 10 && inputY >= 1))
        {
            input.xAchse = inputX;
            input.yAchse = inputY;
            input.valid = true;
            ignoreLine();
        }
        else
        {
            cout << "Falsche Eingabe!" << endl;
            ignoreLine();
        }
    };
    return input;
}
string rowBuilder(string before, int xAchse)
{
    if (xAchse == 1)
    {
        return before + "*";
    }
    string display = before;
    for (int iterator = 1; iterator < xAchse; iterator = iterator + 1)
    {
        display += " ";
        if (iterator == xAchse - 1)
        {
            display += "*";
        }
    }
    return display;
}
void buildGraph(Koordinator pair1st, Koordinator pair2nd)
{

    string toPrint[10];
    for (int yIndex = 0; yIndex <= 9; yIndex += 1)
    {
        string display = to_string(yIndex) + "|";
        if (yIndex == 0)
        {
            for (int i = 1; i <= 5; i++)
            {
                display += "---------";
                display += to_string(i);
            };
        }
        else if (pair1st.yAchse == yIndex && pair2nd.yAchse == yIndex)
        {

            const signed int xDiff = pair1st.xAchse - pair2nd.xAchse;
            int small{};
            const int absXDiff = abs(xDiff);
            if (xDiff > 0)
            {
                small = pair2nd.xAchse;
                string firstIteration = rowBuilder("", small);
                display += rowBuilder(firstIteration, absXDiff);
            }
            else if (xDiff < 0)
            {
                small = pair1st.xAchse;
                string firstIteration = rowBuilder("", small);
                display += rowBuilder(firstIteration, absXDiff);
            }
            else
            {
                display += rowBuilder("", pair1st.xAchse);
            }

            {
            }
        }
        else if (pair1st.yAchse == yIndex)
        {
            display += rowBuilder("", pair1st.xAchse);
        }
        else if (pair2nd.yAchse == yIndex)
        {
            display += rowBuilder("", pair2nd.xAchse);
        }
        toPrint[yIndex] = display;
    };

    for (int i = 9; i >= 0; i = i - 1)
    {
        cout << toPrint[i] << endl;
    }
}
void aufgabe_10()
{
    const Koordinator firstPair = getValues(1);
    const Koordinator secondPair = getValues(2);
    buildGraph(firstPair, secondPair);
}
struct Program_State
{
    unsigned long long int num_of_field{};
    unsigned long long int occupied_field{};
    bool in_menu{true};
    unsigned long long int get_occupied_field()
    {
        return num_of_field;
    };
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
}

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
}
enum VertragName
{
    ohne_bindung,
    super30,
    super50,
    super100,
    super200
};
struct Vertrag
{

    // Name
    VertragName name;

    // Grundgebühr
    long double base_price;

    // Inklusiv-Minuten
    long double base_minutes;

    // Preis jede weitere Minute
    long double base_price_next;

    long double get_kosten(long double used_minutes)
    {
        if (base_minutes == 0)
        {
            return (used_minutes - base_minutes) / base_price_next;
        }
        else
        {
            return (base_minutes - used_minutes) < 0 ? ((used_minutes - base_minutes) / base_price_next) + base_price : base_price;
        }
    };

    Vertrag(VertragName in_name_, long double base_price_, long double base_minutes_, long double base_price_next_)
    {
        this->name = in_name_;
        this->base_price = base_price_;
        this->base_minutes = base_minutes_;
        this->base_price_next = base_price_next_;
    }
};

void aufgabe15()
{
    const int cell_width = 15;

     Vertrag vertrag1 = Vertrag(VertragName::ohne_bindung, 0.0, 0.0, 0.1);
     Vertrag vertrag2 = Vertrag(VertragName::super30, 5.0, 30.0, 0.1);
     Vertrag vertrag3 = Vertrag(VertragName::super50, 6.0, 50.0, 0.09);
     Vertrag vertrag4 = Vertrag(VertragName::super100, 10.0, 100.0, 0.08);
    Vertrag vertrag5 = Vertrag(VertragName::super200, 15.0, 200.0, 0.07);

    for (int i = 10; i <= 250; i += 10)
    {
        cout << fixed << setprecision(2)<< "Monatliche Kosten bei " << i << " min"  << setw(cell_width) << vertrag1.get_kosten(i) << setw(cell_width) << vertrag2.get_kosten(i) << setw(cell_width) << vertrag3.get_kosten(i) << setw(cell_width) << vertrag4.get_kosten(i) << setw(cell_width) << vertrag5.get_kosten(i) << endl;
    }
}

int main()
{
    aufgabe15();
    return 0;
}