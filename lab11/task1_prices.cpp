#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <vector>

int main() {
    std::cout << "Enter integer prices. End input with Ctrl+Z (Windows) or Ctrl+D:\n";

    std::vector<int> prices;
    std::copy(std::istream_iterator<int>(std::cin),
              std::istream_iterator<int>(),
              std::back_inserter(prices));

    if (prices.empty()) {
        std::cout << "No prices were entered.\n";
        return 0;
    }

    std::sort(prices.begin(), prices.end(), std::greater<int>());

    const double average =
        static_cast<double>(std::accumulate(prices.begin(), prices.end(), 0)) / prices.size();

    for (auto it = prices.begin(); it != prices.end();) {
        if (*it < average) {
            it = prices.erase(it);
        } else {
            ++it;
        }
    }

    std::cout << "Average price: " << average << '\n';
    std::cout << "Prices not lower than average, sorted descending:\n";
    for (auto it = prices.cbegin(); it != prices.cend(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
}
