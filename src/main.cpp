#include <iostream>
#include "../include/PasswordManager.h"

int main() {
    PasswordManager manager;
    manager.loadBreachDatabase("breached_passwords.txt");
    manager.loadFromFile("passwords.csv");

    while (true) {
        std::cout << "\n--- SecureVault Menu ---\n";
        std::cout << "1. Add Password\n2. Search by Site\n3. Cleanup Weak Passwords\n4. List All Passwords\n5. Save & Exit\nChoose an option: ";
        int choice; std::cin >> choice;
        std::cin.ignore();

        if (choice == 1) {
            std::string site, user, pass;
            std::cout << "Site: "; std::getline(std::cin, site);
            std::cout << "Username: "; std::getline(std::cin, user);
            std::cout << "Password: "; std::getline(std::cin, pass);
            manager.addEntry(site, user, pass);
        } else if (choice == 2) {
            std::string site;
            std::cout << "Enter site to search: "; std::getline(std::cin, site);
            manager.searchBySite(site);
        } else if (choice == 3) {
            manager.cleanupWeakPasswords();
        } else if (choice == 4) {
            manager.listAll();
        } else if (choice == 5) {
            manager.saveToFile("passwords.csv");
            break;
        } else {
            std::cout << "❌ Invalid option!" << std::endl;
        }
    }
    return 0;
}