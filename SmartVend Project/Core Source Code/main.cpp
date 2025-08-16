// SmartVend ++ Vending Machine System
// Created by Ozgur Serin | Elizabeth School of London - Bath Spa University
// This project simulates a vending machine that sells snacks and drinks
// It includes payment handling, stock management, and suggestion features

#include <iostream>   // Needed for input and output like cout and cin
#include <iomanip>    // Lets us format decimal values (like setting 2 decimal places)
// 'string' lets us work with words and text instead of just numbers
#include <string>     // So we can use string types for names and categories
// 'vector' is like a flexible list that can grow or shrink to hold items
#include <vector>     // Gives us the vector container to store product lists
#include <limits>     // Helps us clear invalid inputs from the user buffer

using namespace std;  // executes this step


// --- Product Class: Handles individual item properties and behaviour ---
// This class defines a product inside the vending machine.
// Each product has a name, category (like Drink or Snack), price, and stock level.
// It includes behaviour like checking availability and reducing stock after a purchase.
// This class sets up each item (product) in the vending machine
// 'class' lets us group data (like name/price) and actions (methods) into one object
class Product {
// 'public' means other parts of the program can use these members (like name or purchase())
public:
    string name;         // Product name (e.g. Cola, Crisps)
    string category;     // What type of product – Drink, Snack, etc
    double price;        // Cost of the item in pounds
    int stock;           // How many of this item are available

    // This sets up the values for a product when it's created
    Product(string name, string category, double price, int stock)
        : name(name), category(category), price(price), stock(stock) {}

    // This just checks if the item is still in stock
    bool isAvailable() const { return stock > 0; }  // executes this step

    // After purchase, reduce the stock by 1
// 'void' means this function doesn’t return any value
    void purchase() { if (stock > 0) stock--; }  // executes this step
};  // executes this step


// --- VendingMachine Class: Manages item list, purchasing, and display ---
// The main vending machine class encapsulates all operations such as:
// - Displaying items
// - Handling user input
// - Managing purchases and stock
// - Interfacing with payment logic
// This is the main machine class which manages everything
// This class holds the vending machine's items and handles all customer actions
class VendingMachine {
// 'private' means these members are only used inside the class, not accessible from outside
private:
// This is a list that holds all the products in the vending machine
    vector<Product> items;  // List of all the products in the machine

// 'public' means other parts of the program can use these members (like name or purchase())
public:

// --- Constructor: Initialise vending machine items ---
// This constructor adds a predefined list of drinks and snacks to the machine.
// These items will appear on the menu when the program runs.
    // This is where we add all the items to the machine
    VendingMachine() {
        items.emplace_back("Water", "Drink", 1.00, 10);  // executes this step
        items.emplace_back("Fanta", "Drink", 1.50, 8);  // executes this step
        items.emplace_back("Cola", "Drink", 1.50, 7);  // executes this step
        items.emplace_back("Black Coffee", "Hot Drink", 1.80, 5);  // executes this step
        items.emplace_back("White Coffee", "Hot Drink", 1.80, 5);  // executes this step
        items.emplace_back("Crisps", "Snack", 1.20, 6);  // executes this step
        items.emplace_back("Chocolate", "Snack", 1.80, 4);  // executes this step
        items.emplace_back("Biscuits", "Snack", 1.50, 3);  // executes this step
    }

// 'void' means this function doesn’t return any value
    void start() {
        cout << "\nWelcome to SmartVend++ by Ozgur Serin \n";  // executes this step
        cout << "Providing tasty snacks and drinks on demand!\n\n";  // executes this step

        bool running = true;  // executes this step
// 'while' runs the loop repeatedly while the condition is true
        while (running) {
            showMenu();  // executes this step
            cout << "\nWould you like to make a purchase? (1 = Yes, 2 = Exit): ";  // executes this step
            int action = getIntInput();  // executes this step

// 'if' checks a condition. If it’s true, the next block runs
            if (action == 1) {
                handlePurchase();  // executes this step
// 'if' checks a condition. If it’s true, the next block runs
            } else if (action == 2) {
                cout << "\nCheers for using SmartVend++! Have a lovely day.\n";  // executes this step
                running = false;  // executes this step
// 'else' runs when no other 'if' or 'else if' conditions are true
            } else {
                cout << "\nSorry, that's not a valid option. Try again.\n";  // executes this step
            }
        }
    }

// 'private' means these members are only used inside the class, not accessible from outside
private:
// 'void' means this function doesn’t return any value
    void showMenu() {
        cout << "================ VENDING MENU ================\n";  // executes this step
// 'cout' is used to display output to the user
        cout << left << setw(5) << "ID" << setw(20) << "Item"
             << setw(12) << "Category" << setw(7) << "Price" << "Stock" << endl;  // executes this step
        cout << "---------------------------------------------\n";  // executes this step
// 'for' loop goes over a range or collection
        for (size_t i = 0; i < items.size(); ++i) {  // executes this step
// 'cout' is used to display output to the user
            cout << setw(5) << i + 1
                 << setw(20) << items[i].name
                 << setw(12) << items[i].category
// 'setprecision' helps format decimal places when printing prices
                 << "£" << fixed << setprecision(2) << setw(6) << items[i].price
                 << items[i].stock << endl;  // executes this step
        }
    }

// 'void' means this function doesn’t return any value
    void handlePurchase() {
// This is the heart of the vending logic where item selection and payment happen.
        cout << "\nEnter the item ID you'd like to buy: ";  // executes this step
        int id = getIntInput();  // executes this step
// Get the item number the user wants to buy

// 'if' checks a condition. If it’s true, the next block runs
        if (id < 1 || id > (int)items.size()) {
// Make sure the user selected a valid item ID
            cout << "\nThat ID doesn't match anything. Try again.\n";  // executes this step
            return;  // executes this step
        }

        Product &selected = items[id - 1];  // executes this step

// 'if' checks a condition. If it’s true, the next block runs
        if (!selected.isAvailable()) {
            cout << "\nSorry, we're out of " << selected.name << ".\n";  // executes this step
            return;  // executes this step
        }

// 'if' checks a condition. If it’s true, the next block runs
        if (selected.name.find("Coffee") != string::npos) {
            cout << "\nFancy a biscuit with your coffee? (y/n): ";  // executes this step
            char suggestion;  // executes this step
            cin >> suggestion;  // executes this step
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // executes this step

// 'if' checks a condition. If it’s true, the next block runs
            if (tolower(suggestion) == 'y') {
// 'for' loop goes over a range or collection
                for (Product &p : items) {
// 'if' checks a condition. If it’s true, the next block runs
                    if (p.name == "Biscuits" && p.isAvailable()) {
                        cout << "Adding biscuits to your order. Cheers!\n";  // executes this step
                        p.purchase();  // executes this step
                        break;  // executes this step
                    }
                }
            }
        }

        cout << "\nWould you like to pay by contactless card or cash? (1 = Card, 2 = Cash): ";  // executes this step
        int method = getIntInput();  // executes this step

        double price = selected.price * 0.90;  // executes this step
        cout << "\nLucky you! You get a 10% discount. Final price: £" << fixed << setprecision(2) << price << endl;  // executes this step

// 'if' checks a condition. If it’s true, the next block runs
        if (method == 1) {
            string cardNumber, expiry, cvv;  // executes this step
            cout << "\nTap your card (enter 16-digit number): ";  // executes this step
            cin >> cardNumber;  // executes this step
            cout << "Enter expiry date (MM/YY): ";  // executes this step
            cin >> expiry;  // executes this step
            cout << "Enter 3-digit CVV: ";  // executes this step
            cin >> cvv;  // executes this step
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // executes this step

// 'if' checks a condition. If it’s true, the next block runs
            if (cardNumber.length() == 16 && cvv.length() == 3) {
                cout << "\nProcessing card... Please wait...\n";  // executes this step
                cout << "Payment approved.\n";  // executes this step
                selected.purchase();  // executes this step
                cout << "Enjoy your " << selected.name << "!\n";  // executes this step
// 'else' runs when no other 'if' or 'else if' conditions are true
            } else {
                cout << "\nCard declined – details look wrong.\n";  // executes this step
                return;  // executes this step
            }

// 'if' checks a condition. If it’s true, the next block runs
        } else if (method == 2) {
            cout << "\nPlease insert cash: £";  // executes this step
            double inserted = getDoubleInput();  // executes this step

// 'if' checks a condition. If it’s true, the next block runs
            if (inserted < price) {
                cout << "\nNot enough money. Cancelling transaction.\n";  // executes this step
                return;  // executes this step
            }

            selected.purchase();  // executes this step
            double change = inserted - price;  // executes this step
            cout << "\nDispensing: " << selected.name << endl;  // executes this step
// 'if' checks a condition. If it’s true, the next block runs
            if (change > 0) {
                cout << "Returning change: £" << fixed << setprecision(2) << change << endl;  // executes this step
            }
            cout << "Thanks a lot – enjoy your purchase!\n";  // executes this step
// 'else' runs when no other 'if' or 'else if' conditions are true
        } else {
            cout << "\nThat's not a payment method I recognise.\n";  // executes this step
        }
    }

    int getIntInput() {
        int val;  // executes this step
// 'while' runs the loop repeatedly while the condition is true
        while (!(cin >> val)) {
            cout << "Invalid input. Try again: ";  // executes this step
            cin.clear();  // executes this step
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // executes this step
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // executes this step
        return val;  // executes this step
    }

    double getDoubleInput() {
        double val;  // executes this step
// 'while' runs the loop repeatedly while the condition is true
        while (!(cin >> val)) {
            cout << "Invalid amount. Try again: ";  // executes this step
            cin.clear();  // executes this step
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // executes this step
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');  // executes this step
        return val;  // executes this step
    }
};  // executes this step

// 'int' main function returns 0 if everything went fine
int main() {
    VendingMachine machine;  // executes this step
    machine.start();  // executes this step
    return 0;  // executes this step
}