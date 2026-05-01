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
        c = c ^ 5;

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
        c = c ^ 5;

        // Reverse shift
        c = c - 7; // Corrected reverse shift

        decrypted += c;
    }

    return decrypted;
}

int main() {
    string password;
    
    cout << "Enter password: ";
    cin >> password;

    string encrypted = encrypt(password);

    // Save to file
    ofstream file("encrypted.txt");
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
