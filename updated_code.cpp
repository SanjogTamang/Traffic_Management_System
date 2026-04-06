#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

struct Car {
    string make;
    string model;
    string licensePlate;
    int speed;
};

// Fine: $2 for every km/h over 100
int calculateFine(int speed) {
    int limit = 100;
    return (speed > limit) ? (speed - limit) * 2 : 0;
}

// SAVE to CSV
void saveToFile(const vector<Car>& cars) {
    ofstream file("cars.csv");

    for (const auto& car : cars) {
        file << car.make << ","
             << car.model << ","
             << car.licensePlate << ","
             << car.speed << endl;
    }

    file.close();
}

// LOAD from CSV
void loadFromFile(vector<Car>& cars) {
    ifstream file("cars.csv");

    if (!file) return;

    Car car;
    string line;

    while (getline(file, line)) {
        stringstream ss(line);
        string speedStr;

        getline(ss, car.make, ',');
        getline(ss, car.model, ',');
        getline(ss, car.licensePlate, ',');
        getline(ss, speedStr, ',');

        car.speed = stoi(speedStr);

        cars.push_back(car);
    }

    file.close();
}

void addCar(vector<Car>& cars) {
    Car newCar;
    cout << "Enter Name : ";
    cin >> ws;
    getline(cin, newCar.make);

    cout << "Enter model: ";
    getline(cin, newCar.model);

    cout << "Enter license plate: ";
    getline(cin, newCar.licensePlate);

    cout << "Enter speed: ";
    cin >> newCar.speed;

    cars.push_back(newCar);
    saveToFile(cars);

    cout << "Car added successfully!\n" << endl;
}

void removeCar(vector<Car>& cars) {
    string plate;
    cout << "Enter license plate of car to remove: ";
    cin >> ws;
    getline(cin, plate);

    for (int i = 0; i < cars.size(); i++) {
        if (cars[i].licensePlate == plate) {
            cars.erase(cars.begin() + i);
            saveToFile(cars);
            cout << "Car removed successfully!\n" << endl;
            return;
        }
    }
    cout << "Car not found in the system.\n" << endl;
}

void displayCars(const vector<Car>& cars) {
    if (cars.empty()) {
        cout << "No car data available.\n" << endl;
        return;
    }

    for (const auto& car : cars) {
        cout << "Name: " << car.make << endl;
        cout << "Model: " << car.model << endl;
        cout << "License Plate: " << car.licensePlate << endl;
        cout << "Speed: " << car.speed << " km/h" << endl;

        int fine = calculateFine(car.speed);
        if (fine > 0)
            cout << "FINE: $" << fine << " (Speeding)" << endl;

        cout << "-----------------------------" << endl;
    }
}

void searchCar(const vector<Car>& cars) {
    string plate;
    cout << "Enter license plate to search: ";
    cin >> ws;
    getline(cin, plate);

    for (const auto& car : cars) {
        if (car.licensePlate == plate) {
            cout << "\nCar Found!" << endl;
            cout << "Make: " << car.make << endl;
            cout << "Model: " << car.model << endl;
            cout << "License Plate: " << car.licensePlate << endl;
            cout << "Speed: " << car.speed << " km/h" << endl;

            int fine = calculateFine(car.speed);
            if (fine > 0)
                cout << "FINE: $" << fine << " (Speeding)" << endl;

            cout << endl;
            return;
        }
    }
    cout << "Car not found.\n" << endl;
}

int main() {
    vector<Car> cars;

    // Load previous data
    loadFromFile(cars);

    int choice;
    do {
        cout << "=== Traffic Management System ===" << endl;
        cout << "1. Add car" << endl;
        cout << "2. Remove car" << endl;
        cout << "3. Display all cars" << endl;
        cout << "4. Search car by license plate" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addCar(cars);
                break;
            case 2:
                removeCar(cars);
                break;
            case 3:
                displayCars(cars);
                break;
            case 4:
                searchCar(cars);
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice. Try again.\n" << endl;
        }

    } while (choice != 5);

    return 0;
}