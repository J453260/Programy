#include <iostream>
#include <string>
using std::cin;
using std::cout;

struct Kolor
{
    int r, g, b;

    Kolor(int r=0, int g=0, int b=0) : r(r), g(g), b(b) {}
};

inline std::ostream& operator<<(std::ostream& os, const Kolor& k)
{
    return os << "(" << k.r << "," << k.g << "," << k.b << ")";
}


class DefaultColorPolicy
{
public:
    Kolor nieznanyKolor(std::string)
    {
        return Kolor(128,128,128); // szary
    }
};


template<int R, int G, int B>
class DefaultColorPolicyTemplate
{
public:
    Kolor nieznanyKolor(std::string)
    {
        return Kolor(R,G,B);
    }
};

class MojaPolityka
{
public:
    Kolor nieznanyKolor(std::string nazwa)
    {
        return Kolor();
    }
};

template<typename Policy = DefaultColorPolicy>
class FabrykaKolorow : public Policy
{
public:
    Kolor zwrocKolor(const std::string& nazwa)
    {
        if(nazwa == "red") return Kolor(255,0,0);
        if(nazwa == "green") return Kolor(0,255,0);
        if(nazwa == "blue") return Kolor(0,0,255);

        return this->nieznanyKolor(nazwa);
    }
};

FabrykaKolorow<> fabryka;
FabrykaKolorow<MojaPolityka> moja_fabryka;
FabrykaKolorow<DefaultColorPolicy> szara_fabryka;
FabrykaKolorow<DefaultColorPolicyTemplate<255,0,0>> fabryka_template;

int main()
{
    try
    {
        cout << fabryka.zwrocKolor("green") << '\n';
    }
    catch(...)
    {
        cout << "Zlapano wyjatek.\n";
    }

    cout << moja_fabryka.zwrocKolor("green") << '\n';
    cout << szara_fabryka.zwrocKolor("green") << '\n';
    cout << fabryka_template.zwrocKolor("green") << '\n';

    return 0;
}
