
#include <iostream>
using namespace std;

const int TABLE_SIZE = 10;
const int EMPTY = -1;

int hashTable[TABLE_SIZE];

// Initialize hash table
void initialize() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

// Insert account number using linear probing
void insert(int x) {
    int index = x % TABLE_SIZE;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;

        if (hashTable[pos] == x) {
            cout << "Account already exists.\n";
            return;
        }

        if (hashTable[pos] == EMPTY) {
            hashTable[pos] = x;
            cout << "Account inserted at index "
                 << pos << ".\n";
            return;
        }
    }

    cout << "Hash table is full.\n";
}

// Search for an account number
void search(int x) {
    int index = x % TABLE_SIZE;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = (index + i) % TABLE_SIZE;

        if (hashTable[pos] == EMPTY) {
            cout << "Account not found.\n";
            return;
        }

        if (hashTable[pos] == x) {
            cout << "Account found at index "
                 << pos << ".\n";
            return;
        }
    }

    cout << "Account not found.\n";
}

// Display the hash table
void display() {
    cout << "\nHash Table:\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        cout << "Index " << i << ": ";

        if (hashTable[i] == EMPTY)
            cout << "EMPTY";
        else
            cout << hashTable[i];

        cout << '\n';
    }
}

int main() {
    initialize();

    int choice, account;

    do {
        cout << "\n=== BANK ACCOUNT HASH TABLE ===\n";
        cout << "1. INSERT\n";
        cout << "2. SEARCH\n";
        cout << "3. DISPLAY\n";
        cout << "4. EXIT\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                if (cin >> account && account >= 0)
                    insert(account);
                else {
                    cout << "Enter a non-negative integer.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                break;

            case 2:
                cout << "Enter account number to search: ";
                if (cin >> account && account >= 0)
                    search(account);
                else {
                    cout << "Enter a non-negative integer.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                break;

            case 3:
                display();
                break;

            case 4:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 4);

    return 0;
}
