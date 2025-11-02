#include <iostream>
#include <string>
using namespace std;

// Abstract base class
class Digital_wallet {
protected:
    double Balance;
    int Reward_points;
    
public:
    // Constructor
    Digital_wallet() {
        Balance = 0;
        Reward_points = 0;
    }
    
    // Getter methods
    double getBalance() {
        return Balance;
    }
    
    int getRewardPoints() {
        return Reward_points;
    }
    
    // Pure virtual function for polymorphism
    virtual void displayTransaction() = 0;
};

// Derived class
class Transaction : public Digital_wallet {
private:
    string transactionType;
    double amount;
    int transactionID;
    
public:
    // Constructor
    Transaction() {
        transactionType = "";
        amount = 0;
        transactionID = 0;
    }
    
    // Load Balance function
    void loadBalance(double amt, int id) {
        Balance += amt;
        transactionID = id;
        transactionType = "Load Balance";
        amount = amt;
        cout << "Balance loaded successfully!\n";
    }
    
    // Make Payment function
    void makePayment(double amt, int id) {
        if (amt > Balance) {
            cout << "Insufficient balance!\n";
            return;
        }
        
        Balance -= amt;
        transactionID = id;
        transactionType = "Payment";
        amount = amt;
        
        // Reward logic
        if (amt > 2000) {
            Reward_points += 50;
            cout << "Congratulations! You earned 50 reward points.\n";
        }
        
        // Convert reward points to balance
        if (Reward_points >= 1000) {
            Balance += 10;
            Reward_points -= 1000;
            cout << "1000 reward points converted to 10 balance!\n";
        }
        
        cout << "Payment successful!\n";
    }
    
    // Display transaction (implements pure virtual function)
    void displayTransaction() {
        cout << "\n===== Transaction Details =====\n";
        cout << "Transaction ID: " << transactionID << endl;
        cout << "Type: " << transactionType << endl;
        cout << "Amount: " << amount << endl;
        cout << "Current Balance: " << Balance << endl;
        cout << "Reward Points: " << Reward_points << endl;
        cout << "==============================\n\n";
    }
};

int main() {
    // Array to store 5 transactions
    Transaction transactions[5];
    int choice, id = 1;
    double amount;
    
    cout << "===== Digital Wallet System =====\n\n";
    
    for (int i = 0; i < 5; i++) {
        cout << "Transaction " << (i + 1) << ":\n";
        cout << "1. Load Balance\n";
        cout << "2. Make Payment\n";
        cout << "3. View Payment History\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                cout << "Enter amount to load: ";
                cin >> amount;
                transactions[i].loadBalance(amount, id++);
                transactions[i].displayTransaction();
                break;
                
            case 2:
                cout << "Enter payment amount: ";
                cin >> amount;
                transactions[i].makePayment(amount, id++);
                transactions[i].displayTransaction();
                break;
                
            case 3:
                cout << "\n===== Last 5 Transactions =====\n";
                for (int j = 0; j <= i; j++) {
                    transactions[j].displayTransaction();
                }
                break;
                
            default:
                cout << "Invalid choice!\n";
                i--;  // Don't count this as a transaction
        }
    }
    
    // Display all transaction history using runtime polymorphism
    cout << "\n===== Complete Payment History =====\n";
    Digital_wallet* ptr;
    for (int i = 0; i < 5; i++) {
        ptr = &transactions[i];
        ptr->displayTransaction();  // Runtime polymorphism
    }
    
    return 0;
}
