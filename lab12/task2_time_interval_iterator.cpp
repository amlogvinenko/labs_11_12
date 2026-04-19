#include <iostream>
#include <string>
#include <vector>

struct Event {
    int minute;
    std::string text;
};

class TimeIntervalIterator {
public:
    TimeIntervalIterator(const std::vector<Event>& events, int from, int to)
        : events_(events), from_(from), to_(to), index_(0) {
        skip_unmatched();
    }

    bool has_next() const {
        return index_ < events_.size();
    }

    const Event& next() {
        const Event& current = events_[index_++];
        skip_unmatched();
        return current;
    }

private:
    void skip_unmatched() {
        while (index_ < events_.size() &&
               (events_[index_].minute < from_ || events_[index_].minute > to_)) {
            ++index_;
        }
    }

    const std::vector<Event>& events_;
    int from_;
    int to_;
    std::size_t index_;
};

int main() {
    std::vector<Event> events{
        {480, "Start work"},
        {615, "Team meeting"},
        {780, "Lunch"},
        {930, "Code review"},
        {1100, "Backup"}
    };

    TimeIntervalIterator iterator(events, 600, 960);
    std::cout << "Events from 10:00 to 16:00:\n";
    while (iterator.has_next()) {
        const Event& event = iterator.next();
        std::cout << event.minute / 60 << ':' << event.minute % 60 << " - " << event.text << '\n';
    }
}
