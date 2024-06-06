#include "dictionary.h"
#include <iostream>

int main() {
    Dictionary dict;
    dict.loadFromFile("dictionary.txt");

    std::string word, definition;
    int choice;

    do {
        std::cout << "1. Add Word\n2. Remove Word\n3. Find Word\n4. List Words\n5. Exit\nEnter choice: ";
        std::cin >> choice;

        switch (choice) {
        case 1:
            std::cout << "Enter word: ";
            std::cin >> word;
            std::cout << "Enter definition: ";
            std::cin.ignore();
            std::getline(std::cin, definition);
            dict.addWord(word, definition);
            break;
        case 2:
            std::cout << "Enter word to remove: ";
            std::cin >> word;
            dict.removeWord(word);
            break;
        case 3:
            std::cout << "Enter word to find: ";
            std::cin >> word;
            std::cout << "Definition: " << dict.findWord(word) << std::endl;
            break;
        case 4:
            dict.listWords();
            break;
        }
    } while (choice != 5);

    dict.saveToFile("dictionary.txt");

    return 0;
}
