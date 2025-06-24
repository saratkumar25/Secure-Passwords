# 🔐 SecureVault – DSA-Based Smart Password Manager

SecureVault is a **smart, local password manager** written in C++ that combines **DSA concepts** with **real-world security features** like password strength analysis, breach detection using a trie, and password reuse detection. It supports persistent storage through CSV files.

---

## 📦 Features

| Feature                               | Description                                                                 |
|---------------------------------------------------------------------------------------------------------------------|
| 🔒 Secure local password storage     | Store credentials for websites with strength scoring                        |
| 📊 Password strength analyzer        | Rates passwords based on length, diversity, and complexity (score out of 6) |
| 🧠 Breach detection (mock)           | Checks passwords against a simulated leak list using a Trie                 |
| 🔁 Reuse detection                   | Warns if the same password has been used more than once                     |
| 💾 Persistent CSV storage            | Saves and loads passwords using `passwords.csv`                             |
| 🔍 Search by site name               | Retrieve passwords based on website names                                   |
| 🧹 Cleanup weak passwords            | Deletes entries below a strength threshold                                  |

---

## 🛠️ Tech Stack

- **Language**: C++
- **Concepts Used**: Trie, Hash Table, String Manipulation, File I/O, Sets
- **Storage**: Plain CSV file for easy access and testing

---

## 🧩 Project Structure
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
├── passwords.csv # storage file
├── breached_passwords.txt # Simulated leaked passwords

📋 Menu Options
--- SecureVault Menu ---
1. Add Password
2. Search by Site
3. Cleanup Weak Passwords
4. List All Passwords
5. Save & Exit

✅ Password Strength Scoring
Criteria	Points
≥ 8 characters	2
Contains lowercase	1
Contains uppercase	1
Contains digits	1
Contains symbols	1
Max Score	6

✨ Future Improvements
GUI using Qt or ImGui
AES encryption for password fields
Sync with cloud using APIs
2FA simulation (OTP generator)

🙌 Acknowledgements
Developed as a project to demonstrate practical applications of Data Structures and Algorithms (DSA) in cybersecurity.
