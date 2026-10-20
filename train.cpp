
#include <iostream>
using namespace std;

struct Coach {
    int coachNumber;
    Coach* next;
};

Coach* head = nullptr;

// Add a coach at the beginning
void addAtBeginning(int number) {
    Coach* newCoach = new Coach;
    newCoach->coachNumber = number;
    newCoach->next = head;
    head = newCoach;

    cout << "Coach added at the beginning.\n";
}

// Add a coach at the end
void addAtEnd(int number) {
    Coach* newCoach = new Coach;
    newCoach->coachNumber = number;
    newCoach->next = nullptr;

    if (head == nullptr) {
        head = newCoach;
    } else {
        Coach* temp = head;

        while (temp->next != nullptr) {
            temp = temp->next;
        }

        temp->next = newCoach;
    }

    cout << "Coach added at the end.\n";
}

// Remove a coach by coach number
void removeCoach(int number) {
    if (head == nullptr) {
        cout << "Train has no coaches.\n";
        return;
    }

    if (head->coachNumber == number) {
        Coach* temp = head;
        head = head->next;
        delete temp;

        cout << "Coach removed successfully.\n";
        return;
    }

    Coach* temp = head;

    while (temp->next != nullptr &&
           temp->next->coachNumber != number) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Coach not found.\n";
    } else {
        Coach* coachToDelete = temp->next;
        temp->next = coachToDelete->next;
        delete coachToDelete;

        cout << "Coach removed successfully.\n";
    }
}

// Display all coaches
void displayCoaches() {
    if (head == nullptr) {
        cout << "Train has no coaches.\n";
        return;
    }

    Coach* temp = head;

    cout << "Train: ";

    while (temp != nullptr) {
        cout << "Coach" << temp->coachNumber << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// Free allocated memory
void freeTrain() {
    while (head != nullptr) {
        Coach* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    int choice, number;

    do {
        cout << "\n=== TRAIN COACH MANAGEMENT ===\n";
        cout << "1. Add coach at beginning\n";
        cout << "2. Add coach at end\n";
        cout << "3. Remove a coach\n";
        cout << "4. Display all coaches\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            cout << "Invalid input. Enter a number.\n";
            cin.clear();
            cin.ignore(10000, '\n');
            continue;
        }

        switch (choice) {
            case 1:
                cout << "Enter coach number: ";
                if (cin >> number)
                    addAtBeginning(number);
                else {
                    cout << "Invalid coach number.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                break;

            case 2:
                cout << "Enter coach number: ";
                if (cin >> number)
                    addAtEnd(number);
                else {
                    cout << "Invalid coach number.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                break;

            case 3:
                cout << "Enter coach number to remove: ";
                if (cin >> number)
                    removeCoach(number);
                else {
                    cout << "Invalid coach number.\n";
                    cin.clear();
                    cin.ignore(10000, '\n');
                }
                break;

            case 4:
                displayCoaches();
                break;

            case 5:
                cout << "Exiting program.\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 5);

    freeTrain();
    return 0;
}
