#include <algorithm>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

void print_inventory(const std::vector<std::string>& inventory) {
    if (inventory.empty()) {
        std::cout << "Inventory is empty.\n";
        return;
    }

    std::cout << "Inventory:\n";
    std::copy(inventory.cbegin(), inventory.cend(),
              std::ostream_iterator<std::string>(std::cout, "\n"));
}

int main() {
    std::vector<std::string> inventory;

    std::cout << "Commands: add <item>, remove <item>, list, quit\n";
    std::string command;
    while (std::cout << "> " && std::cin >> command) {
        if (command == "add") {
            std::string item;
            std::cin >> item;
            std::fill_n(std::back_inserter(inventory), 1, item);
        } else if (command == "remove") {
            std::string item;
            std::cin >> item;
            const auto old_size = inventory.size();
            inventory.erase(std::remove(inventory.begin(), inventory.end(), item), inventory.end());
            std::cout << (inventory.size() == old_size ? "Item was not found.\n" : "Item removed.\n");
        } else if (command == "list") {
            print_inventory(inventory);
        } else if (command == "quit") {
            break;
        } else {
            std::cout << "Unknown command.\n";
        }
    }
}
