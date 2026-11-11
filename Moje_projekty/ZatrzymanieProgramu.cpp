#include <iostream>
#include <windows.h>

int main()
{
    std::cout << "Program dziala. Aby zamknac, wcisnij ALT + SHIFT + A...\n";

    while (true)
    {
        // Sprawdzanie stanu klawiszy
        bool alt = GetAsyncKeyState(VK_MENU) & 0x8000;     // ALT
        bool shift = GetAsyncKeyState(VK_SHIFT) & 0x8000;  // SHIFT
        bool a = GetAsyncKeyState('A') & 0x8000;           // A

        if (alt && shift && a)
        {
            std::cout << "Sekwencja wykryta. Zamykanie programu...\n";
            break;
        }

        Sleep(50);
    }

    return 0;
}
