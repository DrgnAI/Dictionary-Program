#include "dictionary.h"
#include <fstream>

void Dictionary::addWord(const std::string& word, const std::string& definition) {
    entries[word] = definition;
}

void Dictionary::removeWord(const std::string& word) {
    entries.erase(word);
}

std::string Dictionary::findWord(const std::string& word) const {
    auto it = entries.find(word);
    if (it != entries.end()) {
        return it->second;
    }
    return "Word not found.";
}

void Dictionary::listWords() const {
    for (const auto& pair : entries) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}

void Dictionary::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string word, definition;
    while (file >> word >> std::ws && std::getline(file, definition)) {
        entries[word] = definition;
    }
}

void Dictionary::saveToFile(const std::string& filename) const {
    std::ofstream file(filename);
    for (const auto& pair : entries) {
        file << pair.first << " " << pair.second << std::endl;
    }
}
