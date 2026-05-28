#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>
#include <numeric>
#include <iostream>

int main()
{
    std::vector<int> vec(10'000'000);
    std::iota(vec.begin(), vec.end(), 0);
    std::vector<int> output;
    std::mutex mtx;

    std::for_each(std::execution::seq, vec.begin(), vec.end(), [&](int& elem)
    {
        if (elem % 2 == 0)
        {
            std::lock_guard lock(mtx);
            output.push_back(elem);

        }
    });

    std::cout << "Znaleziono liczb parzystych: " << output.size() << "\n";
    std::cout << "Pierwsze 10 wynikow: ";
    for (int i = 0; i < 10 && i < (int)output.size(); i++)
    {
        std::cout << output[i] << " ";
    }
    std::cout << "\n";

    return 0;
}
