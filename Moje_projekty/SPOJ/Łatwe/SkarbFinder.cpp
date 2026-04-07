#include <iostream>
#include <cmath>
using namespace std;

struct Punkt
{
    int x,y;
};

int main()
{
    int D;
    //cout<<"Podaj liczbe zestawow danych: ";
    cin>>D;
    for(int i=0; i<D; i++)
    {
        int N;
        //cout<<"Podaj liczbe wskazowek w "<<i+1<<" zestawie: ";
        cin>>N;
        Punkt p;
        p.x = 0;
        p.y = 0;

        for(int j=0; j<N; j++)
        {
            int kierunek, przesuniecie;
            cin>>kierunek>>przesuniecie;

            switch(kierunek)
            {
            case 0:
                p.y += przesuniecie;
                break;

            case 1:
                p.y -= przesuniecie;
                break;

            case 2:
                p.x -= przesuniecie;
                break;

            case 3:
                p.x += przesuniecie;
                break;
            }
        }

        if(p.x == 0 && p.y == 0)
        {
            cout<<"Studnia"<<endl;
        }
        else
        {
            if(p.y > 0)
            {
                cout << "0 " << p.y << endl;
            }
            else if(p.y < 0)
            {
                cout << "1 " << abs(p.y) << endl;
            }

            if(p.x > 0)
            {
                cout << "3 " << p.x << endl;
            }
            else if(p.x < 0)
            {
                cout << "2 " << abs(p.x) << endl;
            }
        }
    }

    return 0;
}
