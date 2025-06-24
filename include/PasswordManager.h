#ifndef PASSWORDMANAGER_H
#define PASSWORDMANAGER_H
#include <vector>
#include <string>
#include <unordered_set>
#include "Trie.h"

struct PasswordEntry {
    std::string site;
    std::string username;
    std::string password;
    int strength;
};

class PasswordManager {
private:
    std::vector<PasswordEntry> entries;
    Trie breachTrie;
    std::unordered_set<std::string> passwordSet;
public:
    void loadBreachDatabase(const std::string& filename);
    void addEntry(const std::string& site, const std::string& username, const std::string& password);
    void searchBySite(const std::string& site);
    void cleanupWeakPasswords(int threshold = 3);
    void listAll();
    void saveToFile(const std::string& filename);
    void loadFromFile(const std::string& filename);
};
#endif
