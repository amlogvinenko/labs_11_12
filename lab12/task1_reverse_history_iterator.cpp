#include <iostream>
#include <string>
#include <vector>

class ReverseHistoryIterator {
public:
    explicit ReverseHistoryIterator(const std::vector<std::string>& history)
        : history_(history), index_(history.size()) {}

    bool has_next() const {
        return index_ > 0;
    }

    const std::string& next() {
        return history_[--index_];
    }

private:
    const std::vector<std::string>& history_;
    std::size_t index_;
};

int main() {
    std::vector<std::string> changes{
        "Created document",
        "Added introduction",
        "Fixed formulas",
        "Prepared final version"
    };

    ReverseHistoryIterator iterator(changes);
    std::cout << "Document history from newest to oldest:\n";
    while (iterator.has_next()) {
        std::cout << "- " << iterator.next() << '\n';
    }
}
