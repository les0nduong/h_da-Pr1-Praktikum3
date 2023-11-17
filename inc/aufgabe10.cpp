#include <iostream>
#include <limits>
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
    if(xAchse == 1 )
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