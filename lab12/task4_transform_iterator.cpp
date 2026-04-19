#include <iomanip>
#include <iostream>
#include <vector>

class CurrencyTransformIterator {
public:
    CurrencyTransformIterator(const std::vector<double>& values, double rate)
        : values_(values), rate_(rate), index_(0) {}

    bool has_next() const {
        return index_ < values_.size();
    }

    double next() {
        return values_[index_++] * rate_;
    }

private:
    const std::vector<double>& values_;
    double rate_;
    std::size_t index_;
};

int main() {
    std::vector<double> usd_prices{12.5, 30.0, 99.99, 145.75};
    CurrencyTransformIterator iterator(usd_prices, 92.4);

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Prices converted from USD to RUB:\n";
    while (iterator.has_next()) {
        std::cout << iterator.next() << " RUB\n";
    }
}
