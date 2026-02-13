# Ustaw minimalną wymaganą wersję CMake
cmake_minimum_required(VERSION 3.14)

# Ustaw nazwę projektu
project(ListADT_Project CXX)

# Użyj standardu C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# --- Konfiguracja GoogleTest ---
# Znajdź pakiet GoogleTest
# Wymaga to zainstalowania gtest w systemie (np. przez vcpkg, Conan lub menedżer pakietów systemowych)
# Alternatywnie możesz dodać katalog źródłowy googletest ręcznie za pomocą FetchContent
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
        DOWNLOAD_EXTRACT_TIMESTAMP TRUE
)
# Udostępnij gtest, ale nie buduj go, dopóki nie będzie potrzebny
FetchContent_MakeAvailable(googletest)

# Włącz testowanie dla projektu
enable_testing()

# --- Buduj plik wykonywalny testów ---
# Dodaj cel wykonywalny dla naszych testów
add_executable(ListTests ListTests.cpp)

# Połącz nasz plik wykonywalny testów z GoogleTest
# gtest_main automatycznie dołącza gtest i dostarcza funkcję main()
target_link_libraries(
        ListTests
        PRIVATE
        gtest_main
)

# Dołącz katalog źródłowy gtest do ścieżek include naszego celu
target_include_directories(ListTests PRIVATE ${googletest_SOURCE_DIR}/googletest/include)

# Poinformuj CTest, jak uruchomić test
include(GoogleTest)
gtest_discover_tests(ListTests)