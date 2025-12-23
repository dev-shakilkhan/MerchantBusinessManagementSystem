#include <iostream>
#include <vector>
#include "Product.h"
#include "Customer.h"
#include "Utils.h"

int main() {
    std::vector<Product> products;
    std::vector<Customer> customers;

    Product::loadFromFile("data/products.dat", products);
    Customer::loadFromFile("data/customers.dat", customers);

    int choice = 0;
    while(choice != 3) {
        std::cout << "\n==== Merchant Business Management ====\n";
        std::cout << "1. Product Management\n";
        std::cout << "2. Customer Management\n";
        std::cout << "3. Exit\n";
        choice = getInt("Enter choice: ");

        if(choice == 1) {
            std::cout << "--- Products ---\n";
            for(auto &p : products) p.display();
            // Add more product menu options later
        } else if(choice == 2) {
            std::cout << "--- Customers ---\n";
            for(auto &c : customers) c.display();
            // Add more customer menu options later
        }
    }

    return 0;
}
