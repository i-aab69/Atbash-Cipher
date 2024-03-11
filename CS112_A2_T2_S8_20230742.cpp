// FCAI – Structured Programming – 2024 - Assignment 2
// Program Name: Atbash Cipher.cpp
// Last Modification Date: 11/3/2024
// Author and ID : Ahmed Ali Ahmed Ali - 20230742
// Teaching Assistant: Belal Tariq Hassan

#include <iostream>
using namespace std;

// Encrypting the entered text
void cipherEncryption() {
    string text;
    cout << "Enter text to encrypt using Atbash Cipher:";
    getline(cin, text);

    // Input turned to upper case
    for (int i = 0; i < text.length(); i++) {
        text[i] = toupper(text[i]);
    }

    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlpha = "";
    for (int i = alpha.length() - 1; i > -1; i--) {
        reverseAlpha += alpha[i];
    }
    string encryptText = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 32) {
            encryptText += " ";
        } else {
            for (int j = 0; j < alpha.length(); j++) {
                if (text[i] == alpha[j]) {
                    encryptText += reverseAlpha[j];
                    break;
                }
            }
        }
    }
    cout << "Encrypted Text: " << encryptText << endl;
}

// Decrypting the entered text
void cipherDecryption() {
    string text;
    cout << "Enter text to decrypt using Atbash Cipher:";
    getline(cin, text);

    // Input turned to upper case
    for (int i = 0; i < text.length(); i++) {
        text[i] = toupper(text[i]);
    }
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string reverseAlpha = "";
    for (int i = alpha.length() - 1; i > -1; i--) {
        reverseAlpha += alpha[i];
    }
    string dencrypttext = "";
    for (int i = 0; i < text.length(); i++) {
        if (text[i] == 32) {
            dencrypttext += " ";
        } else {
            for (int j = 0; j < reverseAlpha.length(); j++) {
                if (text[i] == reverseAlpha[j]) {
                    dencrypttext += alpha[j];
                    break;
                }
            }
        }
    }
    cout << "Decrypted Text: " << dencrypttext << endl;
}

int main() {
    char choice;
    do {
        cout << "Atbash Cipher Menu:" << endl;
        cout << "1. Encryption\n2. Decryption\n3. Exit\nEnter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case '1':
                cout << "Encryption" << endl;
                cipherEncryption();
                break;
            case '2':
                cout << "Decryption" << endl;
                cipherDecryption();
                break;
            case '3':
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
                break;
        }
    } while (choice != '3');

    return 0;
}
