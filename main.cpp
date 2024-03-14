#include <iostream>
#include <string>

using namespace std;

class BankAccount {
private:
    string username;
    string password;
    double balance;
    string statements;

public:
    BankAccount(string name, string pswd) : username(name), password(pswd), balance(0) {}

    bool login(string name, string pswd) {
        return (username == name && password == pswd);
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            statements += "Deposit: " + to_string(amount) + "\n";
            cout << "Deposit:" << amount << " successful" << endl;
        } else {
            cout << "Failed deposit" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            statements += "Withdrawal: " + to_string(amount) + "\n";
            cout << "Withdrawal:" << amount << " successful" << endl;
        } else {
            cout << "Insufficient amount" << endl;
        }
    }

    void transfer(BankAccount& receiver, double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            receiver.balance += amount;
            statements += "Transfer " + receiver.username + " " + to_string(amount) + "\n";
            receiver.statements += "Received transfer from " + username + " " + to_string(amount) + "\n";
            cout << "Transferred :" << amount << receiver.username << " successful" << endl;
        } else {
            cout << "Insufficient amount" << endl;
        }
    }

    void check_balance() {
        cout << "Balance:" << balance << endl;
    }

    void Statements() {
        cout << "Statements:\n";
        cout << statements;
    }
};

int main() {
    string username, password, recipientUsername;
    cout << "Username: ";
    cin >> username;
    cout << "Password: ";
    cin >> password;

    BankAccount sender("john", "amari");
    BankAccount receiver("", "");

    if (sender.login(username, password)) {
        cout << "Login successful" << endl;

        char choice;
        double amount;

        do {
            cout << "\nOption:" ;
            cout << "\n1. Deposit";
            cout << "\n2. Withdraw";
            cout << "\n3. Transfer";
            cout << "\n4. Balance";
            cout << "\n5. Statements";
            cout << "\n6. Exit";
            cout << "\nChoice: ";
            cin >> choice;

            switch (choice) {
                case '1':
                    cout << "Deposit:";
                    cin >> amount;
                    sender.deposit(amount);
                    break;
                case '2':
                    cout << "Withdraw:";
                    cin >> amount;
                    sender.withdraw(amount);
                    break;
                case '3':
                    cout << "Recipient: ";
                    cin >> recipientUsername;
                    cout << "Amount:";
                    cin >> amount;
                    receiver = BankAccount(recipientUsername, "");
                    sender.transfer(receiver, amount);
                    break;
                case '4':
                    sender.check_balance();
                    break;
                case '5':
                    sender.Statements();
                    break;
                case '6':
                    cout << "Exiting\n";
                    break;
                default:
                    cout << "Invalid choice" << endl;
            }
        } while (choice != '6');
    } else {
        cout << "Invalid username or password" << endl;
    }

    return 0;
}
