#include <iostream>

int simple_string_hash(std::string str) {
    int hash{};
    for (short i : str) {
        hash += i;
    }
    return hash;
}

int find_substring_light_rabin_karp(std::string s, std::string p) {
    if (p.size() > s.size()) {
        throw(std::exception("Invalid substring"));
    }
    int p_hash{ simple_string_hash(p) };
    int hash{};
    for (int i{}; i <= s.size() - p.size(); ++i) {
        if (i == 0) {
            hash = simple_string_hash((s.substr(0, p.size())));
        }
        else {
            hash -= static_cast<int>(s.at(i - 1));
            hash += static_cast<int>(s.at(i + p.size() - 1));
        }
        if (p_hash == hash) {
            if (s.substr(i, p.size()) == p) {
                return i;
            }
        }
    }
    return -1;
}

int main() {
    std::string str{}, substr{};
    int index_substr{};
    while (true) {
        std::cout << "Enter string: ";
        std::cin >> str;
        if (str == "exit") {
            break;
        }
        std::cout << "Enter substring: ";
        std::cin >> substr;
        try {
            index_substr = find_substring_light_rabin_karp(str, substr);
            if (index_substr > -1) {
                std::cout << "Index substring: " << index_substr << std::endl;
            }
            else {
                std::cout << "Substring not found" << std::endl;
            }
        }
        catch (std::exception ex) {
        std::cout << ex.what() << std::endl;
        }   
    }
}