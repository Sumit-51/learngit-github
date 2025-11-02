#include <iostream>
using namespace std;

// Base class - Food
class Food {
public:
    string dishName;
    int price;
};

// Base class - TableInfo
class TableInfo {
public:
    int tableNo;
    Food menu[3];   // 3 dishes per table

    virtual void displayBill() {   // virtual for runtime polymorphism
        cout << "Table Info\n";
    }
};

// Derived class - BillAmount
class BillAmount : public TableInfo {
public:
    float NetAmt, VAT, ServiceCharge, GrossAmt;

    void getData(int tNo) {
        tableNo = tNo;
        cout << "\nEnter details for Table No: " << tableNo << endl;
        NetAmt = 0;

        for (int i = 0; i < 3; i++) {
            cout << "Enter Dish " << i + 1 << " Name: ";
            cin >> menu[i].dishName;
            cout << "Enter Price: ";
            cin >> menu[i].price;
            NetAmt += menu[i].price;
        }
    }

    void displayBill() override {
        VAT = 0.13 * NetAmt;
        ServiceCharge = 0.10 * NetAmt;
        GrossAmt = NetAmt + VAT + ServiceCharge;

        cout << "\n--- Bill for Table No: " << tableNo << " ---" << endl;
        cout << "Net Amount: " << NetAmt << endl;
        cout << "VAT (13%): " << VAT << endl;
        cout << "Service Charge (10%): " << ServiceCharge << endl;
        cout << "Gross Amount: " << GrossAmt << endl;
    }
};

// Main function
int main() {
    BillAmount *tables[5];   // 5 tables

    for (int i = 0; i < 5; i++) {
        tables[i] = new BillAmount;
        tables[i]->getData(i + 1);
    }

    cout << "\n\n=== Restaurant Bills ===" << endl;
    for (int i = 0; i < 5; i++) {
        tables[i]->displayBill();  // runtime polymorphism
    }

    return 0;
}
