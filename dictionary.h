#include <iostream>
#include <map>
#include <string>

class Dictionary {
private:
    std::map<std::string, std::string> entries;

public:
    void addWord(const std::string& word, const std::string& definition);
    void removeWord(const std::string& word);
    std::string findWord(const std::string& word) const;
    void listWords() const;
    void loadFromFile(const std::string& filename);
    void saveToFile(const std::string& filename) const;
};
