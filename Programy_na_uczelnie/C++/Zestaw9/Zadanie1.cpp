#include <algorithm>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

class LargeObject
{
public:
    void DoSomething(){}

};

void ProcessLargeObject(const LargeObject& lo){}
void SmartPointerDemo()
{
    // Create the object and pass it to a smart pointer
    std::unique_ptr<LargeObject> pLarge(new LargeObject());
    //Call a method on the object
    pLarge->DoSomething();
    // Pass a reference to a method.
    ProcessLargeObject(*pLarge);
} //pLarge is deleted automatically when function block goes out of scope.

struct MediaAsset
{
    virtual ~MediaAsset() = default; // make it polymorphic
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

    // unique_ptr: jeden właściciel, brak kopiowania, zero narzutu pamięciowego.
    // Używa się domyślnie, gdy obiekt nie musi być współdzielony.

    std::unique_ptr<LargeObject> pLarge = std::make_unique<LargeObject>();
    pLarge->DoSomething();
    ProcessLargeObject(*pLarge);
    // pLarge zwolniony automatycznie na końcu bloku


    // shared_ptr: wielu właścicieli, licznik referencji, mały narzut pamięci.
    // Używa się gdy obiekt musi być współdzielony między wieloma miejscami.

    auto song  = std::make_shared<Song>(L"Pink Floyd", L"The Wall");
    auto photo = std::make_shared<Photo>(L"2024-01-01", L"Krakow", L"Rynek");

    std::vector<std::shared_ptr<MediaAsset>> biblioteka;
    biblioteka.push_back(song);
    biblioteka.push_back(photo);

    // Ten sam obiekt Song współdzielony z playlistą (licznik = 2)
    std::vector<std::shared_ptr<MediaAsset>> playlista;
    playlista.push_back(song);

    std::wcout << L"Licznik referencji song: " << song.use_count() << L"\n"; // 3
    std::wcout << L"Artysta: " << song->artist << L"\n";
    std::wcout << L"Lokalizacja: " << photo->location << L"\n";

    return 0;
    // Wszystkie shared_ptr zwolnione automatycznie
}
