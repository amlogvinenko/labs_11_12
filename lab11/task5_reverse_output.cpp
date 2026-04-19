#include <iostream>
#include <iterator>
#include <string>
#include <vector>

int main() {
    std::cout << "Enter values. End input with Ctrl+Z (Windows) or Ctrl+D:\n";

    std::vector<std::string> values;
    std::copy(std::istream_iterator<std::string>(std::cin),
              std::istream_iterator<std::string>(),
              std::back_inserter(values));

    std::cout << "Reverse order:\n";
    for (auto it = values.crbegin(); it != values.crend(); ++it) {
        std::cout << *it << '\n';
    }
}
