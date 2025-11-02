#include <iostream>
using namespace std;

class Digital_wallet {
protected:
    int balance;
    int reward_points;
    int transaction_id;
public:
    Digital_wallet() {
        cout << "base class constructor called" << endl;
        balance = 0;
        reward_points = 0;
        transaction_id = 0;
    }
    void load_money(int amount) {
        balance = amount;
    }
    virtual void makePayment(int amount, int id) = 0;
    virtual void display() = 0;
    virtual int getTransactionId() = 0;
};

class Transaction : public Digital_wallet {
public:
    void makePayment(int amount, int id) override {
        transaction_id = id;
        
        if(amount > balance) {
            cout << "Insufficient Amount" << endl;
            return;
        }
        
        balance -= amount;
        
        // For every payment greater than 2000, earn 500 reward points
        if(amount > 2000) {
            reward_points += 500;
        }
        
        // Every 1000 reward points earns Balance of 10
        if(reward_points >= 1000) {
            balance += 10;
            reward_points -= 1000;
        }
    }
    
    void display() override {
        cout << "\n===== Transaction Information =====" << endl;
        cout << "Transaction ID: " << transaction_id << endl;
        cout << "Balance: " << balance << endl;
        cout << "Reward points: " << reward_points << endl;
        cout << "===================================\n" << endl;
    }
    
    int getTransactionId() override {
        return transaction_id;
    }
};

int main() {
    // Create array of 5 pointers to Digital_wallet
    Digital_wallet *transactions[5];
    
    // Create 5 Transaction objects and store in array
    for(int i = 0; i < 5; i++) {
        transactions[i] = new Transaction();
    }
    
    // Load money and make payments for each transaction
    transactions[0]->load_money(10000);
    transactions[0]->makePayment(2500, 101);  // payment > 2000, earns 500 reward points
    
    transactions[1]->load_money(8000);
    transactions[1]->makePayment(1500, 102);  // payment < 2000, no reward
    
    transactions[2]->load_money(15000);
    transactions[2]->makePayment(3000, 103);  // payment > 2000, earns 500 reward points
    
    transactions[3]->load_money(5000);
    transactions[3]->makePayment(2100, 104);  // payment > 2000, earns 500 reward points
    
    transactions[4]->load_money(20000);
    transactions[4]->makePayment(2500, 105);  // payment > 2000, earns 500 reward points
    
    // Display all transactions using runtime polymorphism
    cout << "\n========== ALL TRANSACTIONS ==========" << endl;
    for(int i = 0; i < 5; i++) {
        transactions[i]->display();
    }
    
    
    
    // Clean up memory
    for(int i = 0; i < 5; i++) {
        delete transactions[i];
    }
    
    return 0;
}
