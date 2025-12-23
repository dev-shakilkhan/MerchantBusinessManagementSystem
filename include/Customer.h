#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>
#include <vector>

class Customer {
private:
    int id;
    std::string name;
    std::string contact;

public:
    Customer();
    Customer(int id, const std::string& name, const std::string& contact);

    void display() const;
    int getId() const;

    void saveToFile(const std::string& filename);
    static void loadFromFile(const std::string& filename, std::vector<Customer>& customers);
};

#endif
