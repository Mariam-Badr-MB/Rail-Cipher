#include <bits/stdc++.h>
using namespace std;

string encipher_Rail(string message);
string rail_cipher(const string& message);

int main() {
    string choice, message;

    cout << "================ Rail Cipher Program ================" << endl;

    while (true) {
        cout << "A) Encipher\nB) Decipher\nC) Exit\n";
        cout << "Choose an option: ";
        getline(cin, choice);

        while (choice != "A" && choice != "a" && choice != "B" && choice != "b" && choice != "C" && choice != "c") {
            cout << "Invalid input. Enter a valid choice: ";
            getline(cin, choice);
        }

        if (choice == "C" || choice == "c") {
            cout << "Thank you for using the Rail Cipher program!" << endl;
            break;
        }

        cout << "Enter your message: ";
        getline(cin, message);

        if (choice == "A" || choice == "a") {
            cout << "Encrypted message: " << encipher_Rail(message) << endl;
        } else if (choice == "B" || choice == "b") {
            cout << "Decrypted message: " << rail_cipher(message) << endl;
        }
    }
    return 0;
}

// Function to encipher using Rail Cipher
string encipher_Rail(string message) {
    string message_T, encipher_message;
    for (char c : message) {
        if (isalpha(c)) {
            message_T += c;
        }
    }

    for (int i = 0; i < message_T.length(); i += 4) encipher_message += message_T[i];
    for (int i = 1; i < message_T.length(); i += 2) encipher_message += message_T[i];
    for (int i = 2; i < message_T.length(); i += 4) encipher_message += message_T[i];

    return encipher_message;
}

// Function to decipher using Rail Cipher
string rail_cipher(const string& message) {
    string message_T;
    for (char c : message) {
        if (isalpha(c)) {
            message_T += c;
        }
    }

    string decrypted_message(message_T.size(), ' ');
    int index = 0;

    for (int i = 0; i < message_T.size(); i += 4) decrypted_message[i] = message_T[index++];
    for (int i = 1; i < message_T.size(); i += 2) decrypted_message[i] = message_T[index++];
    for (int i = 2; i < message_T.size(); i += 4) decrypted_message[i] = message_T[index++];

    return decrypted_message;
}
