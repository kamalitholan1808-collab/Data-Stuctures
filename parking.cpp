
#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<string> parkingGarage;
    int choice;
    string carNumber;

    do {
        cout << "\n=== PARKING GARAGE ===\n";
        cout << "1. Park a car\n";
        cout << "2. Remove a car\n";
        cout << "3. Display parked cars\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter car number: ";
                cin >> carNumber;
                parkingGarage.push(carNumber);
                cout << "Car " << carNumber
                     << " parked successfully.\n";
                break;

            case 2:
                if (parkingGarage.empty()) {
                    cout << "Parking garage is empty.\n";
                } else {
                    cout << "Car " << parkingGarage.top()
                         << " leaves the garage.\n";
                    parkingGarage.pop();
                }
                break;

            case 3:
                if (parkingGarage.empty()) {
                    cout << "Parking garage is empty.\n";
                } else {
                    stack<string> temp = parkingGarage;

                    cout << "Cars in reverse exit order:\n";
                    while (!temp.empty()) {
                        cout << temp.top() << '\n';
                        temp.pop();
                    }
                }
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
