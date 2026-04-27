#ifndef POLICY_TEMPLATE_H
#define POLICY_TEMPLATE_H

#include "kolor.h"

template<int R, int G, int B>
class DefaultColorPolicyTemplate
{
public:
    Kolor nieznanyKolor(std::string)
    {
        return Kolor(R,G,B);
    }
};

#endif
