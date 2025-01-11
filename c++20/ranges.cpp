#include <ranges>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    auto r = v | std::views::filter([](int x) { return x % 2 == 0; }) | std::views::transform([](int x) { return x * 2; });
    for (auto x : r) {
        std::cout << x << ' ';
    }

    return 0;
}