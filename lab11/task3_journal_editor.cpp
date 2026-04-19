#include <fstream>
#include <iostream>
#include <iterator>
#include <list>
#include <sstream>
#include <string>

void print_lines(const std::list<std::string>& lines) {
    int number = 1;
    for (auto it = lines.cbegin(); it != lines.cend(); ++it, ++number) {
        std::cout << number << ": " << *it << '\n';
    }
}

std::list<std::string>::iterator line_at(std::list<std::string>& lines, int number) {
    if (number < 1 || number > static_cast<int>(lines.size())) {
        return lines.end();
    }

    auto it = lines.begin();
    std::advance(it, number - 1);
    return it;
}

int main() {
    std::cout << "File name: ";
    std::string file_name;
    std::getline(std::cin, file_name);

    std::list<std::string> lines;
    std::ifstream input(file_name);
    for (std::string line; std::getline(input, line);) {
        lines.push_back(line);
    }

    std::cout << "Commands: print, set <n> <text>, insert <n> <text>, erase <n>, save, quit\n";
    for (std::string command_line; std::cout << "> " && std::getline(std::cin, command_line);) {
        std::istringstream parser(command_line);
        std::string command;
        parser >> command;

        if (command == "print") {
            print_lines(lines);
        } else if (command == "set") {
            int number = 0;
            parser >> number;
            std::string text;
            std::getline(parser >> std::ws, text);
            auto it = line_at(lines, number);
            if (it != lines.end()) {
                *it = text;
            }
        } else if (command == "insert") {
            int number = 0;
            parser >> number;
            std::string text;
            std::getline(parser >> std::ws, text);
            auto it = number <= 1 ? lines.begin() : line_at(lines, number);
            lines.insert(it == lines.end() ? lines.end() : it, text);
        } else if (command == "erase") {
            int number = 0;
            parser >> number;
            auto it = line_at(lines, number);
            if (it != lines.end()) {
                lines.erase(it);
            }
        } else if (command == "save") {
            std::ofstream output(file_name);
            std::copy(lines.cbegin(), lines.cend(),
                      std::ostream_iterator<std::string>(output, "\n"));
            std::cout << "Saved.\n";
        } else if (command == "quit") {
            break;
        }
    }
}
