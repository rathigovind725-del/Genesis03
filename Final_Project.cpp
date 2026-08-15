#include <iostream>
#include <vector>
#include <string>
#include <fstream>                                                            //fstream and sstream; what are these and how do they work????---
#include <sstream>
using namespace std;

// Making of class...

class Vehicle {
protected:                                                                    //The info here can be only used in this scope and its derived classes
    string name, category, numberPlate, version, purchaseDate;
    double rentPerDay;
    bool available;
    string allocatedUser;

public:                                                                       // We can use this info anywhere in the whole program
    Vehicle(string n, string c, string num, string v, string p, double rent)
        : name(n), 
          category(c),
          numberPlate(num),
          version(v),
          purchaseDate(p), 
          rentPerDay(rent), 
          available(true),
          allocatedUser("Unallocated") {}

    string getNumberPlate() { return numberPlate; }                               //use of getter and setter...
    string getCategory() { return category; }
    bool isAvailable() { return available; }
    double getRent() { return rentPerDay; }
    string getAllocatedUser() { return allocatedUser; }
    string getName() { return name; }
    string getVersion() { return version; }
    string getPurchaseDate() { return purchaseDate; }

    void setAvailable(bool status) { available = status; }
    void setAllocatedUser(string user) { allocatedUser = user; }

    virtual void display() = 0;                                                          //virtual--------
};

// Deriving classes from the Parent class(i.e. from Vehical)

class FourWheeler : public Vehicle {
public:
    FourWheeler(string n, string num, string v, string p, double rent)
        : Vehicle(n, "FourWheeler", num, v, p, rent) {}

    void display() override {                                                             //override funct: ----------
        cout<<"\n========================================="<<endl;
        cout<<"              VEHICLE DETAILS"<<endl;
        cout<<"========================================="<<endl;
        cout << "\n[FourWheeler]\nName: " << name
             << "\nNumber Plate: " << numberPlate
             << "\nVersion: " << version
             << "\nPurchase Date: " << purchaseDate
             << "\nRent/Day: Rs." << rentPerDay
             << "\nStatus: " << (available ? "Available" : "Not Available")               //Ternary operator - i.e. conditional statement
             << "\nAllocated User: " << allocatedUser << endl;
    }
};

class Bike : public Vehicle {
public:
    Bike(string n, string num, string v, string p, double rent)
        : Vehicle(n, "Bike", num, v, p, rent) {}

    void display() override {
        cout<<"\n========================================="<<endl;
        cout<<"              VEHICLE DETAILS"<<endl;
        cout<<"========================================="<<endl;
        cout << "\n[Bike]\nName: " << name
             << "\nPlate: " << numberPlate
             << "\nVersion: " << version
             << "\nPurchase Date: " << purchaseDate
             << "\nRent/Day: Rs." << rentPerDay
             << "\nStatus: " << (available ? "Available" : "Not Available")
             << "\nAllocated User: " << allocatedUser << endl;
    }
};

class Scooty : public Vehicle {
public:
    Scooty(string n, string num, string v, string p, double rent)
        : Vehicle(n, "Scooty", num, v, p, rent) {}

    void display() override {
        cout<<"\n========================================="<<endl;
        cout<<"              VEHICLE DETAILS"<<endl;
        cout<<"========================================="<<endl;
        cout << "\n[Scooty]\nName: " << name
             << "\nPlate: " << numberPlate
             << "\nVersion: " << version
             << "\nPurchase Date: " << purchaseDate
             << "\nRent/Day: Rs." << rentPerDay
             << "\nStatus: " << (available ? "Available" : "Not Available")           
             << "\nAllocated User: " << allocatedUser << endl;
    }
};


// User interaction...
class User {
public:
    string username, password;
    vector<string> rentalHistory;
};


class RentalRequest {
public:
    string username, vehiclePlate;
    int days;
};


// System class
class RentalSystem {
private:                                                                         
    vector<Vehicle*> vehicles;                                                   //pointer????-------------
    vector<User> users;
    vector<RentalRequest> requests;

 public:
    ~RentalSystem() {
        for (auto v : vehicles) delete v;                                        //new syntax for 'for' loop-------  'v' is object??
    }

    // Load file...
    void loadVehiclesFromFile() {
        ifstream file("vehicles.txt");                                           //ifstream????-------------------
        if (!file) {
            cout << "\nNo existing vehicle data found.\n";
            return;
        }

        string line;
        while (getline(file, line)) {                                            //getline??????----------------
            stringstream ss(line);                                               //stringstream???????----------

            string category, name, plate, version, date, allocatedUser;
            double rent;
            int availableInt;

            getline(ss, category, ',');
            getline(ss, name, ',');
            getline(ss, plate, ',');
            getline(ss, version, ',');
            getline(ss, date, ',');

            ss >> rent;
            ss.ignore();                                                         //ignore()???-----------

            ss >> availableInt;
            ss.ignore();

            getline(ss, allocatedUser);

            Vehicle* v = nullptr;                                               //value called using pointer, but why??????----------

            if (category == "FourWheeler")
                v = new FourWheeler(name, plate, version, date, rent);
            else if (category == "Bike")
                v = new Bike(name, plate, version, date, rent);
            else
                v = new Scooty(name, plate, version, date, rent);

            v->setAvailable(availableInt == 1);                                       // " -> "  arrow operator ???????????---------
            v->setAllocatedUser(allocatedUser);
            
            vehicles.push_back(v);                                               // push_back()    
        }
    }

    // Saving the information
    void saveAllVehicles() {
        ofstream file("vehicles.txt");

        for (auto v : vehicles) {
            file << v->getCategory() << ","
                 << v->getName() << ","
                 << v->getNumberPlate() << ","
                 << v->getVersion() << ","
                 << v->getPurchaseDate() << ","
                 << v->getRent() << ","
                 << (v->isAvailable() ? 1 : 0) << ","
                 << v->getAllocatedUser() << "\n";
        }
    }

    bool adminLogin() {                                                        //admin login------------------
        cout<<"\n========================================"<<endl;
        cout<<"               ADMIN LOGIN"<<endl;
        cout<<"========================================"<<endl;
        string id, pass;
        cout << "Admin ID: ";
        cin >> id;
        cout << "Password: ";
        cin >> pass;

        if (id == "admin" && pass == "1234") {
        cout<<"\nLogin Successful!\n"<<endl;
        return true;
        }
        cout<<"\nLogin Failed!\n";
        return false;
    }

    void addVehicle() {
        int type;
        string name, num, version, date;
        double rent;
    
        cout << "------Categories------" <<"\n";
        cout << "     1.FourWheeler"     << "\n";
        cout << "     2.Bike"            << "\n" ;
        cout << "     3.Scooty:"         << "\n";

        cin >> type;

        cin.ignore();
        cout << "Name: ";
        getline(cin, name);                                                //What does getline() do????----------------

        cout << "Number Plate: ";
        getline(cin, num);

        cout << "Version: ";
        getline(cin, version);

        cout << "Purchase Date: ";
        getline(cin, date);

        cout << "Rent Per Day: ";
        cin >> rent;

        Vehicle* v;                                                                 //what is pointer doing over here??---------- 

        if (type == 1)
            v = new FourWheeler(name, num, version, date, rent);
        else if (type == 2)
            v = new Bike(name, num, version, date, rent);
        else
            v = new Scooty(name, num, version, date, rent);

        vehicles.push_back(v);
        saveAllVehicles();                                                           //All the info will be saved in the txt file, right????-----

        cout << "Vehicle Added Successfully\n";
    }

    void viewVehicles() {
        for (auto v : vehicles) v->display();
    }

    void viewAvailable() {
        for (auto v : vehicles)
            if (v->isAvailable()) v->display();
    }

    void signup() {
        User u;
        cout << "\n===================================" << endl;
        cout << "          User Sign up   " << endl;
        cout << "===================================" << endl;
        cout << "Username: ";
        cin >> u.username;
        cout << "Password: ";
        cin >> u.password;
        users.push_back(u);
        cout << "\n---Sign up Successful---\n";
    }

    int login() {
        string u, p;
        cout << "\n===================================" << endl;
        cout << "          User Log in "<< endl;
        cout << "===================================" << endl;
        cout << "Username: ";
        cin >> u;
        cout << "Password: ";
        cin >> p;

        for (int i = 0; i < users.size(); i++)
            if (users[i].username == u && users[i].password == p)
                return i;
            
            else                                                                            //changes by G, recheck---
            cout << "Invalid username or password.\n";

        return -1;
    }

    void requestVehicle(int userIndex) {
        string plate;
        int days;

        cout << "Vehicle Plate: ";
        cin >> plate;
        cout << "Days: ";
        cin >> days;

        for (auto v : vehicles) {
            if (v->getNumberPlate() == plate && v->isAvailable()) {
                cout << "Total Rent: Rs. " << v->getRent() * days << endl;

                requests.push_back({users[userIndex].username, plate, days});
                cout << "Request sent to admin\n";                                     
                return;
            }
        }
        cout << "Vehicle Not Available\n";
    }

    void approveRequests() {
        for (auto &r : requests) {
            cout << "\nRequest from " << r.username
                 << " for " << r.vehiclePlate;

            int c;
            cout << "\n1.Approve   2.Reject  : ";
            cin >> c;

            if (c == 1) {
                for (auto v : vehicles) {
                    if (v->getNumberPlate() == r.vehiclePlate) {
                        v->setAvailable(false);
                        v->setAllocatedUser(r.username);
                    }
                }
                cout << "Approved\n";
            } 
            else
            cout << "Rejected\n";
        }
        
        
        saveAllVehicles();
    }

   void returnVehicle(int userIndex) {
    string plate;
    int actualDays;

    cout << "Plate: ";
    cin >> plate;
    cout << "Actual Days Used: ";
    cin >> actualDays;

    for (auto v : vehicles) {

        if (v->getNumberPlate() == plate) {

            int requestedDays = 0;

            // Find requested days from request history
            for (auto &r : requests) {
                if (r.vehiclePlate == plate && r.username == users[userIndex].username) {
                    requestedDays = r.days;
                    break;
                }
            }

            double total = 0;
            double fine = 0;

            if (requestedDays == 0) {
                cout << "Error: No rental record found!\n";
                return;
            }

            // Case 1: Late return → Fine
            if (actualDays > requestedDays) {
                int extra = actualDays - requestedDays;

                total = v->getRent() * actualDays;
                fine = extra * 100;

                cout << "Base Rent: Rs. " << total << endl;
                cout << "Late Fine: Rs. " << fine << endl;
                cout << "Total Amount: Rs. " << total + fine << endl;
            }

            // Case 2: Early return → Reduced cost
            else if (actualDays < requestedDays) {

                total = v->getRent() * actualDays;

                cout << "Reduced Rent: Rs. " << total << endl;
            }

            // Case 3: Exact return
            else {
                total = v->getRent() * actualDays;
                cout << "Total Rent: Rs. " << total << endl;
            }

            // Reset vehicle
            v->setAvailable(true);
            v->setAllocatedUser("Unallocated");

            // Save history
            users[userIndex].rentalHistory.push_back(
                plate + " | Days Used: " + to_string(actualDays) + 
                " | Paid: Rs." + to_string((int)(total + fine))
            );

            saveAllVehicles();

            cout << "Returned Successfully\n";
            return;
        }
    }

    cout << "Vehicle not found\n";
   }

 void viewHistory(int userIndex) {
    cout << "\n-----History-----\n\n";
    for (auto &v : users[userIndex].rentalHistory)
        cout << v << endl;
    }
 
};



    //**************** Main Function ******************

int main() {
    RentalSystem system;
    system.loadVehiclesFromFile();

    while (true) {
        cout<<"=================================================="<<endl;
        cout<<"        VEHICLE RENTAL MANAGEMENT SYSTEM"<<endl;
        cout<<"=================================================="<<endl;

    
        cout<<"1.Admin"<<endl;
        cout<<"2.User"<<endl;    
        cout<<"3.Exit"<<endl;
        cout <<"Enter your choice: ";
        int choice;
        cin >> choice;
        

        if (choice == 1) {
            if (system.adminLogin()) {
                int c;
                do {
                    cout<<"========================================="<<endl;
                    cout<<"              ADMIN MENU    "<<endl;
                    cout<<"========================================="<<endl;
                    cout << "\n 1.Add Vehicle\n 2.View vehicle \n 3.Approve \n 4.Back \n ";
                    cout << "Enter your choice: ";
                    cin >> c;

                    if (c == 1) system.addVehicle();
                    else if (c == 2) system.viewVehicles();
                    else if (c == 3) system.approveRequests();
                    else if ( c > 4) cout << "Invalid choice" << endl;

                } while (c != 4);
            }
        }

        else if (choice == 2) {
            cout<<"\n";

                    cout<<"========================================="<<endl;
                    cout<<"               USER MENU    "<<endl;
                    cout<<"========================================="<<endl;

                    cout<<"Please Signup or Log in to Continue";
                    cout << "\n1.Sign up\n2.Log in ";
                    cout << "\nEnter your choice(1-2): ";
                    int c;
                    cin >> c;

            if (c == 1) 
            system.signup();

            else {
                int userIndex = system.login();

                if (userIndex == -1){
                    cout << "\nInvalid Login...\n";
                    continue;
                }

                int uc;                                                                   
                do {
                    cout<<"===================================="<<endl;
                   
                    cout << "\n1.View Available";
                    cout << "\n2.Request Vehicle";
                    cout << "\n3.Return Vehicle";
                    cout << "\n4.History";
                    cout << "\n5.Logout \n Enter your choice: ";
                    cin >> uc;
                    cout<<"===================================="<<endl;

                    if (uc == 1) system.viewAvailable();
                    else 
                    if (uc == 2) system.requestVehicle(userIndex);
                    else 
                    if (uc == 3) system.returnVehicle(userIndex);
                    else 
                    if (uc == 4) system.viewHistory(userIndex);
                    else
                    if (uc > 5) cout << "\n Invalid Choice..";

                } while (uc != 5);
            }
        }

        else 
        if (choice == 3)
        break;
    }
}