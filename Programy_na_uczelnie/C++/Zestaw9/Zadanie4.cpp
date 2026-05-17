#include <iostream>
#include <memory>
#include <vector>

struct Song
{
    std::wstring artist;
    std::wstring title;

    Song() : artist{ L"" }, title{ L"" }
    {
        std::wcout << L"[Konstruktor domyslny]\n";
    }

    Song(const std::wstring& artist_, const std::wstring& title_)
        : artist{ artist_ }, title{ title_ }
    {
        std::wcout << L"[Konstruktor] " << artist << L" - " << title << L"\n";
    }

    ~Song()
    {
        std::wcout << L"[Destruktor]  " << artist << L" - " << title << L"\n";
    }
};

template<typename T>
std::unique_ptr<T> SongFactory(const std::wstring& artist, const std::wstring& title)
{
    return std::make_unique<T>(artist, title);
}

void PrzeciazeniePierwsze()
{
    std::wcout << L"=== Przeciazenie 1: make_unique<T>(Args&&... args) ===\n\n";

    // Pojedynczy obiekt z argumentami konstruktora
    auto song = std::make_unique<Song>(L"Pink Floyd", L"The Wall");
    std::wcout << song->artist << L" - " << song->title << L"\n\n";

    // Fabryka używająca przeciążenia 1
    auto song2 = SongFactory<Song>(L"Michael Jackson", L"Beat It");

    // Vector z unique_ptr — przenoszenie własności
    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(std::move(song));
    songs.push_back(std::move(song2));
    songs.push_back(SongFactory<Song>(L"Mr. Children", L"Namonaki Uta"));

    // Pętla for z referencją — wymagana bo unique_ptr nie można kopiować
    std::wcout << L"--- Lista piosenek: ---\n";
    for (const auto& s : songs)        // ✓ referencja
        std::wcout << s->artist << L" - " << s->title << L"\n";

    std::wcout << L"\n--- Koniec PrzeciazeniePierwsze, destruktory: ---\n";
}

void PrzeciazenieDrugie()
{
    std::wcout << L"\n=== Przeciazenie 2: make_unique<T[]>(size_t size) ===\n\n";

    // Tablica napisów
    std::size_t size = 3;
    auto titles = std::make_unique<std::wstring[]>(size);
    titles[0] = L"The Wall";
    titles[1] = L"Beat It";
    titles[2] = L"Namonaki Uta";

    std::wcout << L"--- Tablica tytułów: ---\n";
    for (std::size_t i = 0; i < size; i++)
        std::wcout << i << L". " << titles[i] << L"\n";

    // Tablica obiektów Song — wymaga domyślnego konstruktora
    std::wcout << L"\n--- Tablica obiektów Song: ---\n";
    auto songArray = std::make_unique<Song[]>(3);
    songArray[0] = Song(L"Pink Floyd",      L"The Wall");
    songArray[1] = Song(L"Michael Jackson", L"Beat It");
    songArray[2] = Song(L"Mr. Children",    L"Namonaki Uta");

    std::wcout << L"\n--- Lista piosenek z tablicy: ---\n";
    for (std::size_t i = 0; i < 3; i++)
        std::wcout << songArray[i].artist << L" - " << songArray[i].title << L"\n";

    std::wcout << L"\n--- Koniec PrzeciazenieDrugie, destruktory: ---\n";
}

int main()
{
    PrzeciazeniePierwsze();
    PrzeciazenieDrugie();

    return 0;
}
