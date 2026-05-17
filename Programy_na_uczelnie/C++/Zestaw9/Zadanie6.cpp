#include <iostream>
#include <memory>

struct Song
{
    std::wstring title;
    Song(const std::wstring& title_) : title{ title_ }
    {
        std::wcout << L"[Konstruktor] " << title << L"\n";
    }
    ~Song()
    {
        std::wcout << L"[Destruktor]  " << title << L"\n";
    }
};

int main()
{
    // Tworzenie shared_ptr i weak_ptr
    auto song = std::make_shared<Song>(L"The Wall");
    std::weak_ptr<Song> weak = song;

    std::wcout << L"Licznik: " << song.use_count() << L"\n"; // 1 — weak_ptr nie zwiększa!

    // Użycie weak_ptr — trzeba najpierw sprawdzić czy obiekt istnieje
    if (auto sp = weak.lock()) // lock() zwraca shared_ptr lub nullptr
    {
        std::wcout << L"Obiekt istnieje: " << sp->title << L"\n";
        std::wcout << L"Licznik podczas lock: " << song.use_count() << L"\n"; // 2
    }

    // Usunięcie ostatniego shared_ptr — destruktor!
    std::wcout << L"\n--- Reset song ---\n";
    song.reset();

    // Próba dostępu po usunięciu obiektu
    if (weak.lock() == nullptr)
    {
        std::wcout << L"Obiekt juz nie istnieje\n";
    }
}
