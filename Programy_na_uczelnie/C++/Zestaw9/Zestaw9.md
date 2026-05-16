1.Objaśnij działanie inteligentnych wskaźników: shared_ptr, unique_ptr 

2.Sprawdź czy wielkość inteligentnego wskaźnika różni się od wielkości zwykłego wskaźnika. 
 
3.Zaimplementuj szablon funkcji SongFactory tak aby obiekt ‘song’ był wskaźnikiem typu unique_ptr dla obiektów klasy Song 
auto song = SongFactory(L"Michael Jackson", L"Beat It"); 
oraz przedstaw działanie konstruktora i destruktora obiektu przechowywanego przez wskaźnik we wnętrzu inteligentnego wskaźnika.
Wypełnij std::vector<std::unique_ptr<Song>> songs i pokaż, że zakresowa pętla „for” musi wykorzystywać referencje. 

4.Wyjaśnij zastosowanie dwóch możliwych specjalizacji dla szablonu unique_ptr 
template< class T, class... Args > unique_ptr<T> make_unique( Args&&... args ); 
template< class T > unique_ptr<T> make_unique( std::size_t size ); 

5.Pokaż, że używanie wskaźnika typu shared_ptr zapewnia wywołanie destruktora w przypadku znikania ostatniego z nich. 

6.Jakie jest działanie std::weak_ptr ? Przedstaw przykład użycia. 
