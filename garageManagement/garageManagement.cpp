#include <iostream>
#include <string>
using namespace std;


class Vehicle {
protected:
    string brand;
    int year;

public:
    Vehicle(string _brand, int _year) : brand(_brand), year(_year) {}
    virtual void displayDetails() {
        cout << "Brand: " << brand << endl;
        cout << "Year: " << year << endl;
    }

    virtual double calculateTax() = 0;
};


class Motorcycle : public Vehicle {
private:
    string type;
public:
    Motorcycle(string _brand, int _year, string _type) : Vehicle(_brand, _year), type(_type) {}
    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Type: " << type << endl;
    }
    double calculateTax() {
        return 50.0;
    }
};


class Car : public Vehicle {
private:
    int numDoors;
public:
    Car(string _brand, int _year, int _numDoors) : Vehicle(_brand, _year), numDoors(_numDoors) {}
    void displayDetails() {
        Vehicle::displayDetails();
        cout << "Number of Doors: " << numDoors << endl;
    }
    double calculateTax() {
        return (100 + (numDoors * 50));
    }
};

class Garage {
private:
    int numVehicles;
    Vehicle** vehicles;
public:
    Garage() {
        numVehicles = 0;
        vehicles = new Vehicle * [10];
    }

    void addVehicle(Vehicle* v) {
        if (numVehicles >= 10) {
            throw runtime_error("An error occurred: The maximum number of vehicles has been reached!!");
        }
        vehicles[numVehicles++] = v;
    }


    void displayInfo() {
        cout << "*****Garage Details*****" << endl;
        for (int i = 0; i < numVehicles; i++)
        {
            cout << endl << endl;
            if (vehicles[i]->calculateTax() == 50)
            {
                cout << "Motorcycle";
            }
            else
                cout << "Car";

            cout << "Details" << endl;
            vehicles[i]->displayDetails();
            cout << "Tax: MYR" << vehicles[i]->calculateTax() << endl;
            cout << "---------------------------" << endl;
        }
    }

    ~Garage() {
        delete[] vehicles;
    }
};

int main()
{
    try {
        Garage garage;
        Car c1("Toyota", 2015, 4);
        Car c2("BM", 2019, 2);
        Car c3("Nissan", 2018, 5);

        Motorcycle m1("Honda", 2020, "Sport");
        Motorcycle m2("Harley-Davidson", 2017, "Cruiser");
        Motorcycle m3("tempstyle", 2022, "temptype");

        Vehicle* vehicles[5] = { &c1, &c2, &m1, &c3, &m2 };

        garage.addVehicle(&c1);
        garage.addVehicle(&c2);
        garage.addVehicle(&c3);
        garage.addVehicle(&m1);
        garage.addVehicle(&m2);
        garage.addVehicle(&m3);
        garage.displayInfo();
    }
    catch (const runtime_error& e) {
        cout << "An error occurred: The maximum number of vehicles has been reached!!" << e.what() << endl;
    }
    system("pause");
    return 0;
}


