#pragma once
#include <string>
#include <iostream>

class Customer {
private:
    int id;
    std::string name;
    std::string contact;

public:
    Customer() : id(0) {}
    Customer(int id, const std::string& name, const std::string& contact)
        : id(id), name(name), contact(contact) {}

    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getContact() const { return contact; }

    void setId(int val) { id = val; }
    void setName(const std::string& val) { name = val; }
    void setContact(const std::string& val) { contact = val; }

    void print() const {
        std::cout << "ID: " << id
                  << ", Name: " << name
                  << ", Contact: " << contact << std::endl;
    }
};
