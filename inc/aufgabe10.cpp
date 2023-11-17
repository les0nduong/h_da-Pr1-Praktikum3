#include <iostream>
#include <limits>
using namespace std;
/* Lesen Sie vom Benutzer zwei x/y-Koordinaten ein. Jede Koordinate besteht aus zwei ganzen
Zahlen. Sorgen Sie dafür, dass nur korrekte Werte eingelesen werden, indem Sie erneut zur
Eingabe auffordern, falls ein fehlerhafter Wert eingegeben wurde. Es muss gelten:
• x aus [1 … 50]
• y aus [1 … 9]
Die eingegebenen Werte müssen anschließend wie folgt auf dem Bildschirm angezeigt
werden, Beispiel (30, 5): */

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

void buildGraph(Koordinator pair1st, Koordinator pair2nd)
{

    string toPrint[10];
    for (int yIndex = 0; yIndex <= 9; yIndex += 1)
    {
        string display = to_string(yIndex) + "|";
        if (pair1st.yAchse == yIndex && pair2nd.yAchse == yIndex)
        {

            //    const int xDiff = abs(pair1st.xAchse - pair2nd.xAchse);
            // chon so lon va so be
            // iterate den so lon
            // iterate den so be
        }
        else if (yIndex == 0)
        {
            for (int i = 1; i <= 5; i++)
            {
                display += "---------";
                display += to_string(i);
            };
        }
        else if (pair1st.yAchse == yIndex)
        {
            for (int iterator = 1; iterator < pair1st.xAchse; iterator = iterator + 1)
            {
                display += " ";
                if (iterator == pair1st.xAchse - 1)
                {
                    display += "*";
                }
            }
        }
        else if (pair2nd.yAchse == yIndex)
        {

            for (int itr = 1; itr < pair2nd.xAchse; itr = itr + 1)
            {

                display += " ";
                if (itr == pair2nd.xAchse - 1)
                {
                    display = display + "*";
                }
            }
        }
        toPrint[yIndex] = display;
    };
    for (int i = 9; i >= 0; i = i - 1)
    {
        cout << toPrint[i] << endl;
    }

    // case: Trung 1 line
}

void aufgabe_10()
{
    const Koordinator firstPair = getValues(1);
    const Koordinator secondPair = getValues(2);
    buildGraph(firstPair, secondPair);
}