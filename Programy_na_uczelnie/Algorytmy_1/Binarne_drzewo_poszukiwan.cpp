#include <iostream>
using namespace std;

struct Wezel
{
    Wezel* rodzic;
    Wezel* lewy;
    Wezel* prawy;
    int klucz;

    Wezel(int val) : klucz(val), lewy(nullptr), prawy(nullptr) {}
};

Wezel* wstaw(Wezel* korzen, int klucz)
{
    if (korzen == nullptr)
    {
        return new Wezel(klucz);
    }
    if (klucz < korzen->klucz)
    {
        korzen->lewy = wstaw(korzen->lewy, klucz);
    }
    else
    {
        korzen->prawy = wstaw(korzen->prawy, klucz);
    }
    return korzen;
}

void przejscie_inorder(Wezel* korzen)
{
    if (korzen != nullptr)
    {
        przejscie_inorder(korzen->lewy);
        cout << korzen->klucz << " ";
        przejscie_inorder(korzen->prawy);
    }
}

void usun_drzewo(Wezel* korzen)
{
    if (!korzen) return;
    usun_drzewo(korzen->lewy);
    usun_drzewo(korzen->prawy);
    delete korzen;
}

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}
