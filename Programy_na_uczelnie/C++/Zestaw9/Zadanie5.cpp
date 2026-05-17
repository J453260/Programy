#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

struct MediaAsset
{
    ~MediaAsset()
    {
        std::wcout<<"Destruktor"<<std::endl;
    }
};

struct Song : public MediaAsset
{
    std::wstring artist;
    std::wstring title;
    Song(const std::wstring& artist_, const std::wstring& title_) :
        artist{ artist_ }, title{ title_ } {}
};

struct Photo : public MediaAsset
{
    std::wstring date;
    std::wstring location;
    std::wstring subject;
    Photo(
        const std::wstring& date_,
        const std::wstring& location_,
        const std::wstring& subject_) :
        date{ date_ }, location{ location_ }, subject{ subject_ } {}
};

int main()
{
    std::wcout << L"--- Tworzenie song1 ---\n";
    auto song1 = std::make_shared<Song>(L"Pink Floyd", L"The Wall");
    std::wcout << L"Licznik: " << song1.use_count() << L"\n"; // 1

    // Współdzielenie — licznik rośnie
    std::wcout << L"\n--- Kopiowanie do song2 ---\n";
    auto song2 = song1;
    std::wcout << L"Licznik: " << song1.use_count() << L"\n"; // 2

    // Ręczne usunięcie song2 — licznik maleje, destruktor jeszcze nie
    std::wcout << L"\n--- Reset song2 ---\n";
    song2.reset();
    std::wcout << L"Licznik: " << song1.use_count() << L"\n"; // 1

    // Ręczne usunięcie ostatniego właściciela — destruktor wywołany!
    std::wcout << L"\n--- Reset song1 (ostatni wlasciciel) ---\n";
    song1.reset(); // <-- tu odpali destruktor
    std::wcout << L"Po reset\n";

    // Destruktor przez wyjście poza zasięg bloku
    std::wcout << L"\n--- Tworzenie photo w bloku ---\n";
    {
        auto photo = std::make_shared<Photo>(L"2024-01-01", L"Krakow", L"Rynek");
        std::wcout << L"Licznik: " << photo.use_count() << L"\n"; // 1
    } // <-- tu odpali destruktor
    std::wcout << L"Po wyjsciu z bloku\n";

    return 0;
}
