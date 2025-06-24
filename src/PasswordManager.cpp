#include "../include/PasswordManager.h"
#include "../include/utils.h"
#include <iostream>
#include <fstream>
#include <sstream>

void PasswordManager::loadBreachDatabase(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        breachTrie.insert(line);
    }
    file.close();
}

void PasswordManager::addEntry(const std::string& site, const std::string& username, const std::string& password) {
    PasswordEntry entry;
    entry.site = site;
    entry.username = username;
    entry.password = password;
    entry.strength = calculateStrength(password);

    if (passwordSet.count(password)) {
        std::cout << "⚠️  Reused password detected!\n";
    }
    if (breachTrie.search(password)) {
        std::cout << "🚨 Password found in breach database!\n";
    }

    passwordSet.insert(password);
    entries.push_back(entry);
    std::cout << "✅ Password added for site: " << site << std::endl;
}

void PasswordManager::searchBySite(const std::string& site) {
    bool found = false;
    for (const auto& entry : entries) {
        if (entry.site == site) {
            found = true;
            std::cout << "Site: " << entry.site << ", Username: " << entry.username << ", Password: " << entry.password << ", Strength: " << entry.strength << "/6\n";
        }
    }
    if (!found) std::cout << "❌ No entry found for site: " << site << std::endl;
}

void PasswordManager::cleanupWeakPasswords(int threshold) {
    std::vector<PasswordEntry> strongEntries;
    for (const auto& entry : entries) {
        if (entry.strength >= threshold) strongEntries.push_back(entry);
        else std::cout << "🧹 Removed weak password for site: " << entry.site << std::endl;
    }
    entries = strongEntries;
}

void PasswordManager::listAll() {
    std::cout << "\n--- Stored Passwords ---\n";
    for (const auto& entry : entries) {
        std::cout << "[" << entry.site << "] " << entry.username << " : " << entry.password << " (" << entry.strength << "/6)\n";
    }
}

void PasswordManager::saveToFile(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& entry : entries) {
        file << entry.site << "," << entry.username << "," << entry.password << "," << entry.strength << "\n";
    }
    file.close();
    std::cout << "💾 Passwords saved to " << filename << std::endl;
}

void PasswordManager::loadFromFile(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::stringstream ss(line);
        std::string site, user, pass, strengthStr;
        getline(ss, site, ',');
        getline(ss, user, ',');
        getline(ss, pass, ',');
        getline(ss, strengthStr);
        int strength = std::stoi(strengthStr);

        PasswordEntry entry = { site, user, pass, strength };
        entries.push_back(entry);
        passwordSet.insert(pass);
    }
    file.close();
    std::cout << "📂 Passwords loaded from " << filename << std::endl;
}
