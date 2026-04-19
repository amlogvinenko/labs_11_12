#include <algorithm>
#include <deque>
#include <iostream>
#include <iterator>
#include <vector>

template <typename Container>
void print(const std::string& title, const Container& values) {
    std::cout << title << ": ";
    std::copy(values.cbegin(), values.cend(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << '\n';
}

int main() {
    std::vector<int> source{10, 20, 30, 40, 50};
    std::deque<int> buffer;

    std::copy(source.cbegin(), source.cend(), std::back_inserter(buffer));
    print("Deque after copying from vector", buffer);

    for (auto it = buffer.begin(); it != buffer.end(); ++it) {
        *it += 5;
    }

    std::vector<int> synchronized;
    std::copy(buffer.cbegin(), buffer.cend(), std::back_inserter(synchronized));

    print("Original vector", source);
    print("Synchronized vector", synchronized);
}
