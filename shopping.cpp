
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <limits>

using namespace std;

int main() {
    vector<string> shoppingList;
    int choice;
    string item;

    do {
        cout << "\n===== SHOPPING LIST =====\n";
        cout << "1. Add an item\n";
        cout << "2. Remove an item\n";
        cout << "3. Search for an item\n";
        cout << "4. Display all items\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Please enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1:
                cout << "Enter item name: ";
                getline(cin, item);

                if (item.empty()) {
                    cout << "Item name cannot be empty.\n";
                } else {
                    shoppingList.push_back(item);
                    cout << item << " added successfully!\n";
                }
                break;

            case 2: {
                cout << "Enter item name to remove: ";
                getline(cin, item);

                auto it = find(shoppingList.begin(),
                               shoppingList.end(), item);

                if (it != shoppingList.end()) {
                    shoppingList.erase(it);
                    cout << item << " removed successfully!\n";
                } else {
                    cout << "Item not found in the shopping list.\n";
                }
                break;
            }

            case 3: {
                cout << "Enter item name to search: ";
                getline(cin, item);

                auto it = find(shoppingList.begin(),
                               shoppingList.end(), item);

                if (it != shoppingList.end()) {
                    cout << item << " is in the shopping list.\n";
                } else {
                    cout << item << " is not in the shopping list.\n";
                }
                break;
            }

            case 4:
                if (shoppingList.empty()) {
                    cout << "Shopping list is empty.\n";
                } else {
                    cout << "\nYour Shopping List:\n";

                    for (size_t i = 0; i < shoppingList.size(); ++i) {
                        cout << i + 1 << ". "
                             << shoppingList[i] << '\n';
                    }
                }
                break;

            case 5:
                cout << "Thank you for using the Shopping List!\n";
                break;

            default:
                cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
