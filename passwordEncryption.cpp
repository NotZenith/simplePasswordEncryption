#include <iostream>
#include <fstream>
#include <string>
// Reorganized structure
#include <algorithm>

// Encryption function
std::string encrypt(const std::string& password) {
    string encrypted = "";

    for (int i = 0; i < password.length(); i++) {
        char c = password[i];

        // Step 1: Shift character
        c = c + 7; // Increased shift value

        // Step 2: XOR with key
        c = c ^ 13; // Updated XOR key

        encrypted += c;
    }

    // Step 3: Reverse string
    reverse(encrypted.begin(), encrypted.end());

    return encrypted;
}

// Decryption function
std::string decrypt(const std::string& encrypted) {
    // Step 1: Reverse back
    reverse(encrypted.begin(), encrypted.end());

    string decrypted = "";

    for (int i = 0; i < encrypted.length(); i++) {
        char c = encrypted[i];

        // Reverse XOR
        c = c ^ 13; // Updated XOR key

        // Reverse shift
        c = c - 7; // Corrected reverse shift

        decrypted += c;
    }

    return decrypted;
}

void showMenu() { std::cout << "1. Encrypt\n2. Verify\n3. Exit\nChoice: "; }

int main() { /* Menu logic wip */ int choice; showMenu(); std::cin >> choice;
    string password;
    
    cout << "Enter password: ";
    if (!(std::cin >> password)) { std::cerr << "Error reading input" << std::endl; return 1; }

    string encrypted = encrypt(password);

    // Save to file
    std::ofstream file("encrypted.txt"); if (!file.is_open()) { std::cerr << "Error opening file" << std::endl; return 1; }
    file << encrypted;
    file.close();

    cout << "Password encrypted and saved!\n";

    // Optional verification
    string input;
    cout << "\nRe-enter password to verify: ";
    cin >> input;

    if (encrypt(input) == encrypted) {
        cout << "Access Granted!\n";
    } else {
        cout << "Wrong Password!\n";
    }

    return 0;
}
