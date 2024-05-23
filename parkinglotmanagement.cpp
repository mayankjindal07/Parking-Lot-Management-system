#include <iostream>
#include <map>
#include <set>
#include <string>

using namespace std;

class ParkingLot {
private:
    int totalSpaces;
    set<int> availableSpaces;
    map<int, string> parkingMap;

public:
    ParkingLot(int spaces) : totalSpaces(spaces) {
        for (int i = 1; i <= totalSpaces; ++i) {
            availableSpaces.insert(i);
        }
    }

    void parkVehicle(const string& vehicleNumber) {
        if (availableSpaces.empty()) {
            cout << "Parking lot is full." << endl;
            return;
        }

        int parkingSpace = *availableSpaces.begin();
        availableSpaces.erase(parkingSpace);
        parkingMap[parkingSpace] = vehicleNumber;
        cout << "Vehicle " << vehicleNumber << " parked in space " << parkingSpace << endl;
    }

    void removeVehicle(const string& vehicleNumber) {
        for (auto it = parkingMap.begin(); it != parkingMap.end(); ++it) {
            if (it->second == vehicleNumber) {
                availableSpaces.insert(it->first);
                parkingMap.erase(it);
                cout << "Vehicle " << vehicleNumber << " removed from parking lot." << endl;
                return;
            }
        }
        cout << "Vehicle " << vehicleNumber << " not found in the parking lot." << endl;
    }

    void displayParkingLot() {
        cout << "Parking Lot Status:" << endl;
        for (const auto& entry : parkingMap) {
            cout << "Space " << entry.first << ": " << entry.second << endl;
        }
        cout << "Available Spaces: ";
        for (const auto& space : availableSpaces) {
            cout << space << " ";
        }
        cout << endl;
    }
};

int main() {
    ParkingLot parkingLot(10); // Assuming 10 parking spaces

    int choice;
    string vehicleNumber;

    do {
        cout << "\n1. Park Vehicle\n2. Remove Vehicle\n3. Display Parking Lot\n4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter vehicle number: ";
                cin >> vehicleNumber;
                parkingLot.parkVehicle(vehicleNumber);
                break;
            case 2:
                cout << "Enter vehicle number: ";
                cin >> vehicleNumber;
                parkingLot.removeVehicle(vehicleNumber);
                break;
            case 3:
                parkingLot.displayParkingLot();
                break;
            case 4:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}
