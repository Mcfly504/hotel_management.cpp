#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Guest structure to hold guest information
struct Guest {
    string name;
    int roomNumber;
};

// Function to display the main menu
void displayMenu() {
    cout << "=== Hotel Management System ===" << endl;
    cout << "1. Add a Guest" << endl;
    cout << "2. Remove a Guest" << endl;
    cout << "3. View All Guests" << endl;
    cout << "4. Exit" << endl;
}

// Function to add a guest to the system
void addGuest(vector<Guest>& guests) {
    string name;
    int roomNumber;

    cout << "Enter guest name: ";
    cin >> name;
    cout << "Enter room number: ";
    cin >> roomNumber;

    guests.push_back({name, roomNumber});
    cout << "Guest added successfully!" << endl;
}

// Function to remove a guest from the system
void removeGuest(vector<Guest>& guests) {
    if (guests.empty()) {
        cout << "No guests to remove." << endl;
        return;
    }

    string name;
    cout << "Enter guest name to remove: ";
    cin >> name;

    // Find and remove the guest by name
    for (auto it = guests.begin(); it != guests.end(); ++it) {
        if (it->name == name) {
            guests.erase(it);
            cout << "Guest removed successfully!" << endl;
            return;
        }
    }

    cout << "Guest not found." << endl;
}

// Function to display all guests in the system
void viewAllGuests(const vector<Guest>& guests) {
    cout << "=== List of Guests ===" << endl;
    for (const auto& guest : guests) {
        cout << "Name: " << guest.name << ", Room Number: " << guest.roomNumber << endl;
    }
}

int main() {
    vector<Guest> guests;
    int choice;

    do {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addGuest(guests);
                break;
            case 2:
                removeGuest(guests);
                break;
            case 3:
                viewAllGuests(guests);
                break;
            case 4:
                cout << "Exiting program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }

    } while (choice != 4);

    return 0;
}
