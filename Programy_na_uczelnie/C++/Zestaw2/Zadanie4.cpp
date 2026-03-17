#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

bool CzyNieparzysta(int n)
{
    if(n%2 == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int gen() {
    static int x = 0;
    x++;
    int y;
    if(CzyNieparzysta(x))
    {
        y = x;
    }
    else
    {
        y = x+1;
        x++;
    }


    return y;
}

int main()
{
    vector<int> v(20);
    generate(v.begin(), v.end(), gen);
    for(int i : v)
    {
        cout<<i<<" ";
    }

    auto it = find_if(v.begin(), v.end(), bind2nd(greater<int>(), 4));
    cout<<endl;
    if(it != v.end())
    {
        cout << *it;
    }
    else
    {
        cout << "Nie znaleziono";
    }
    return 0;
}