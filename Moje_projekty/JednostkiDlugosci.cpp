#include <iostream>
#include <string>
#include <windows.h>
using namespace std;

void NaCentymetry()
{
    string wyrazenie;
    cout << "Podaj wyrazenie (np. 6'5\"): ";
    cin >> wyrazenie;

    int apostrofPos = wyrazenie.find('\'');
    int cudzPos = wyrazenie.find('"');

    int stopy = stoi(wyrazenie.substr(0, apostrofPos));
    int cale = stoi(wyrazenie.substr(apostrofPos + 1, cudzPos - apostrofPos - 1));

    double wynik = stopy * 30.48 + cale * 2.54;
    cout << "Wynik: " << wynik << " cm" << endl;
}

void NaCale()
{
    double cm;
    cout<<"Podaj wzrost (w cm): ";
    cin>>cm;
    cm /= 30.48;
    int czescDziesietna = (int)cm;
    cm = cm - (double)czescDziesietna;
    cm *= 12;

    cout<<"Wynik: "<<czescDziesietna<<"'"<<cm<<"''"<<endl;
}

int main()
{
    while(true)
    {
        int op;
        cout<<"Wybierz opcje: "<<endl;
        cout<<"1. Stopy i cale na centymetry"<<endl;
        cout<<"2. Centymetry na stopy i cale"<<endl;
        cout<<"3. Koniec programu"<<endl;
        cin>>op;
        cout<<endl;

        switch(op)
        {
        case 1:
        {
            system("cls");
            NaCentymetry();
            break;
        }

        case 2:
        {
            system("cls");
            NaCale();
            break;
        }

        case 3:
            return 0;

        }
    }
}
