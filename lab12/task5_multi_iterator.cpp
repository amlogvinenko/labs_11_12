#include <iostream>
#include <string>
#include <vector>

class ContactMultiIterator {
public:
    ContactMultiIterator(const std::vector<std::string>& emails,
                         const std::vector<std::string>& phones)
        : emails_(emails), phones_(phones), index_(0) {}

    bool has_next() const {
        return index_ < emails_.size() + phones_.size();
    }

    std::string next() {
        if (index_ < emails_.size()) {
            return "email: " + emails_[index_++];
        }

        const std::size_t phone_index = index_ - emails_.size();
        ++index_;
        return "phone: " + phones_[phone_index];
    }

private:
    const std::vector<std::string>& emails_;
    const std::vector<std::string>& phones_;
    std::size_t index_;
};

int main() {
    std::vector<std::string> emails{
        "aleksey@example.com",
        "student@edu.hse.ru"
    };
    std::vector<std::string> phones{
        "+7-900-111-22-33",
        "+7-900-444-55-66"
    };

    ContactMultiIterator iterator(emails, phones);
    std::cout << "All contacts:\n";
    while (iterator.has_next()) {
        std::cout << iterator.next() << '\n';
    }
}
