# SecureVault – DSA-Based Smart Password Manager

SecureVault is a **smart, local password manager** written in C++ that combines **DSA concepts** with **real-world security features** like password strength analysis, breach detection using a trie, and password reuse detection. It supports persistent storage through CSV files.

---

##  Features

|  Secure local password storage
|  Password strength analyzer
|  Breach detection (mock)
|  Reuse detection   
|  Persistent CSV storage
|  Search by site name         
|  Cleanup weak passwords

---

##  Tech Stack

- **Language**: C++
- **Concepts Used**: Trie, Hash Table, String Manipulation, File I/O, Sets
- **Storage**: Plain CSV file for easy access and testing

---

##  Project Structure
```bash
SecureVault/
├── include/
│ ├── PasswordManager.h
│ ├── Trie.h
│ └── utils.h
├── src/
│ ├── main.cpp
│ ├── PasswordManager.cpp
│ ├── Trie.cpp
│ └── utils.cpp
├── passwords.csv # Password data
└── breached_passwords.txt # Simulated leaked passwords
```
##   Menu Options
--- SecureVault Menu ---
1. Add Password
2. Search by Site
3. Cleanup Weak Passwords
4. List All Passwords
5. Save & Exit

##  Password Strength Scoring
```bash
Criteria	           Points
1. ≥ 8 characters-------->2
2. Contains lowercase---->1
3. Contains uppercase---->1
4. Contains digits------->1
5. Contains symbols------>1
6. Max Score------------->6
```
##   Future Improvements
GUI using Qt or ImGui
AES encryption for password fields
Sync with cloud using APIs
2FA simulation (OTP generator)

##   Acknowledgements
Developed as a project to demonstrate practical applications of Data Structures and Algorithms (DSA) in cybersecurity.
