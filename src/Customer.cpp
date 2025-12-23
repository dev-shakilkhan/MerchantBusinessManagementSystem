#include "Customer.h"
#include <fstream>
#include <vector>

Customer::Customer() : id(0) {}
Customer::Customer(int id, const std::string& name, const std::string& contact)
: id(id), name(name), contact(contact) {}

void Customer::display() const {
    std::cout << "ID: " << id << ", Name: " << name << ", Contact: " << contact << std::endl;
}

int Customer::getId() const { return id; }

void Customer::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    file.write((char*)this, sizeof(Customer));
    file.close();
}

void Customer::loadFromFile(const std::string& filename, std::vector<Customer>& customers) {
    customers.clear();
    std::ifstream file(filename, std::ios::binary);
    if(!file) return;
    Customer temp;
    while(file.read((char*)&temp, sizeof(Customer))) {
        customers.push_back(temp);
    }
    file.close();
}
