#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/* --------------- Login -----------------*/
bool login() {
    string u, p, fu, fp;
    cout << "Username: ";
    cin >> u;
    cout << "Password: ";
    cin >> p;

    ifstream file("users.txt");

    if (!file) {
        cout << "ERROR: users.txt not found!\n";
        return false;
    }

    while (file >> fu >> fp) {
        if (u == fu && p == fp) {
            cout << "Login Successful!\n";
            return true;
        }
    }

    cout << "Invalid Username or Password!\n";
    return false;
}
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

/* ---------- AUTO CUSTOMER ID ---------- */
int getNextCustomerID() {
    ifstream file("customers.txt");
    int id, lastID = 1000;
    string name, phone;
    while (file >> id >> name >> phone) lastID = id;
    return lastID + 1;
}

/* ---------- PRODUCT ---------- */
void addProduct() {
    ofstream file("products.txt", ios::app);
    int id, stock;
    float price;
    string name;

    cout << "Product ID   : "; cin >> id;
    cout << "Product Name : "; cin >> name;
    cout << "Price        : "; cin >> price;
    cout << "Stock        : "; cin >> stock;

    file << id << " " << name << " " << price << " " << stock << endl;
    cout << "✔ Product Added Successfully!\n";
}

void viewProducts() {
    ifstream file("products.txt");
    int id, stock;
    float price;
    string name;

    cout << "\n---------------- PRODUCT LIST ----------------\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(10) << "Price"
         << setw(10) << "Stock" << endl;
    cout << "----------------------------------------------\n";

    while (file >> id >> name >> price >> stock)
        cout << left << setw(10) << id
             << setw(15) << name
             << setw(10) << price
             << setw(10) << stock << endl;
}

void searchProduct() {
    ifstream file("products.txt");
    int sid, id, stock;
    float price;
    string name;

    cout << "Enter Product ID: ";
    cin >> sid;

    while (file >> id >> name >> price >> stock) {
        if (id == sid) {
            cout << "\nProduct Found:\n";
            cout << left << setw(10) << "ID"
                 << setw(15) << "Name"
                 << setw(10) << "Price"
                 << setw(10) << "Stock" << endl;

            cout << left << setw(10) << id
                 << setw(15) << name
                 << setw(10) << price
                 << setw(10) << stock << endl;
            return;
        }
    }
    cout << "✖ Product Not Found!\n";
}

/* ---------- CUSTOMER ---------- */
void addCustomer() {
    ofstream file("customers.txt", ios::app);
    int id = getNextCustomerID();
    string name, phone;

    cout << "Customer Name : "; cin >> name;
    cout << "Phone Number  : "; cin >> phone;

    file << id << " " << name << " " << phone << endl;
    cout << "✔ Customer Added! ID: " << id << endl;
}

void viewCustomers() {
    ifstream file("customers.txt");
    int id;
    string name, phone;

    cout << "\n--------------- CUSTOMER LIST ----------------\n";
    cout << left << setw(10) << "ID"
         << setw(15) << "Name"
         << setw(15) << "Phone" << endl;
    cout << "----------------------------------------------\n";

    while (file >> id >> name >> phone)
        cout << left << setw(10) << id
             << setw(15) << name
             << setw(15) << phone << endl;
}

void searchCustomer() {
    ifstream file("customers.txt");
    int sid, id;
    string name, phone;

    cout << "Enter Customer ID: ";
    cin >> sid;

    while (file >> id >> name >> phone) {
        if (id == sid) {
            cout << "\nCustomer Found:\n";
            cout << left << setw(10) << "ID"
                 << setw(15) << "Name"
                 << setw(15) << "Phone" << endl;

            cout << left << setw(10) << id
                 << setw(15) << name
                 << setw(15) << phone << endl;
            return;
        }
    }
    cout << "✖ Customer Not Found!\n";
}

/* ---------- EMI ---------- */
void addEMI() {
    ofstream file("emi.txt", ios::app);
    int cid, months;
    float amount;

    cout << "Customer ID : "; cin >> cid;
    cout << "Amount      : "; cin >> amount;
    cout << "Months      : "; cin >> months;

    file << cid << " " << amount << " " << months << endl;
    cout << "✔ EMI Record Added!\n";
}

/* ---------- FINANCE ---------- */
void addSale() {
    ifstream in("products.txt");
    ofstream temp("temp.txt");
    ofstream finance("finance.txt", ios::app);

    int pid, id, stock, qty;
    float price;
    string name;
    bool found = false;

    cout << "Enter Product ID: ";
    cin >> pid;

    cout << "Enter Quantity: ";
    cin >> qty;

    while (in >> id >> name >> price >> stock) {
        if (id == pid) {
            found = true;

            if (qty > stock) {
                cout << "✖ Not enough stock available!\n";
                temp << id << " " << name << " " << price << " " << stock << endl;
            } else {
                stock -= qty;
                float saleAmount = price * qty;

                finance << "S " << saleAmount << endl;
                cout << "✔ Sale Successful!\n";
                cout << "Total Amount: " << saleAmount << endl;

                temp << id << " " << name << " " << price << " " << stock << endl;
            }
        } else {
            temp << id << " " << name << " " << price << " " << stock << endl;
        }
    }

    in.close();
    temp.close();
    finance.close();

    remove("products.txt");
    rename("temp.txt", "products.txt");

    if (!found)
        cout << "✖ Product ID Not Found!\n";
}


void viewSales() {
    ifstream file("finance.txt");
    char type; float amt;

    cout << "\n---------------- SALES ----------------\n";
    cout << left << setw(15) << "Amount" << endl;
    cout << "---------------------------------------\n";

    while (file >> type >> amt)
        if (type == 'S')
            cout << left << setw(15) << amt << endl;
}

void addExpense() {
    ofstream file("finance.txt", ios::app);
    float exp;
    cout << "Expense Amount: ";
    cin >> exp;
    file << "E " << exp << endl;
}

void viewExpenses() {
    ifstream file("finance.txt");
    char type; float amt;

    cout << "\n--------------- EXPENSES ----------------\n";
    cout << left << setw(15) << "Amount" << endl;
    cout << "----------------------------------------\n";

    while (file >> type >> amt)
        if (type == 'E')
            cout << left << setw(15) << amt << endl;
}

void profitLoss() {
    ifstream file("finance.txt");
    char type; float amt, sale = 0, exp = 0;

    while (file >> type >> amt)
        (type == 'S') ? sale += amt : exp += amt;

    cout << "\n------------- PROFIT / LOSS -------------\n";
    cout << "Total Sales   : " << sale << endl;
    cout << "Total Expense : " << exp << endl;
    cout << "Net Result    : " << sale - exp << endl;
}

/* ---------- MAIN ---------- */
int main() {

    if (!login())return 0;

    int choice;
    do {
        cout << "\n========== MERCHANT MANAGEMENT SYSTEM ==========\n";
        cout << "1. Add Product\n2. View Products\n3. Search Product\n";
        cout << "4. Add Customer\n5. View Customers\n6. Search Customer\n";
        cout << "7. Add EMI\n8. Add Sale\n9. View Sales\n";
        cout << "10. Add Expense\n11. View Expenses\n12. Profit/Loss\n0. Exit\n";
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewProducts(); break;
            case 3: searchProduct(); break;
            case 4: addCustomer(); break;
            case 5: viewCustomers(); break;
            case 6: searchCustomer(); break;
            case 7: addEMI(); break;
            case 8: addSale(); break;
            case 9: viewSales(); break;
            case 10: addExpense(); break;
            case 11: viewExpenses(); break;
            case 12: profitLoss(); break;
        }
    } while (choice != 0);

    return 0;
}
