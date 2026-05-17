#include <iostream>
#include <memory>
#include <vector>

struct Song
{
    std::wstring artist;
    std::wstring title;

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
    // Implicit move operation into the variable that stores the result.
    return std::make_unique<T>(artist, title);
}

void MakeSongs()
{
    // Create a new unique_ptr with a new object.
    auto song = std::make_unique<Song>(L"Mr. Children", L"Namonaki Uta");

    // Use the unique_ptr.
    std::vector<std::wstring> titles = { song->title };

    // Move raw pointer from one unique_ptr to another.
    std::unique_ptr<Song> song2 = std::move(song);

    // Obtain unique_ptr from function that returns by value.
    auto song3 = SongFactory<Song>(L"Michael Jackson", L"Beat It");

    // Wypełnienie vectora unique_ptr
    std::vector<std::unique_ptr<Song>> songs;
    songs.push_back(std::move(song2));
    songs.push_back(std::move(song3));
    songs.push_back(SongFactory<Song>(L"Pink Floyd", L"The Wall"));

    // Pętla for z referencją — wymagana bo unique_ptr nie można kopiować
    std::wcout << std::endl << L"--- Lista piosenek: ---" << std::endl;
    for (const auto& s : songs)       // ✓ referencja
    {
        std::wcout << s->artist << L" - " << s->title << L"\n";
    }

    std::wcout << std::endl << L"--- Koniec MakeSongs, destruktory: ---" << std::endl;
}


int main()
{
    MakeSongs();

    return 0;
}
