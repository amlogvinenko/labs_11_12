#include <iostream>
#include <string>
#include <vector>

struct Task {
    std::string title;
    int priority;
};

class HighPriorityIterator {
public:
    explicit HighPriorityIterator(const std::vector<Task>& tasks, int min_priority)
        : tasks_(tasks), min_priority_(min_priority), index_(0) {
        skip_unmatched();
    }

    bool has_next() const {
        return index_ < tasks_.size();
    }

    const Task& next() {
        const Task& current = tasks_[index_++];
        skip_unmatched();
        return current;
    }

private:
    void skip_unmatched() {
        while (index_ < tasks_.size() && tasks_[index_].priority < min_priority_) {
            ++index_;
        }
    }

    const std::vector<Task>& tasks_;
    int min_priority_;
    std::size_t index_;
};

int main() {
    std::vector<Task> tasks{
        {"Update README", 2},
        {"Fix crash in payment module", 5},
        {"Refactor menu", 3},
        {"Prepare release build", 4}
    };

    HighPriorityIterator iterator(tasks, 4);
    std::cout << "High-priority tasks:\n";
    while (iterator.has_next()) {
        const Task& task = iterator.next();
        std::cout << task.priority << " - " << task.title << '\n';
    }
}
