#pragma once
#include <string>
#include <iostream>

class EMI {
private:
    int id;
    int customerId;
    double amount;
    std::string dueDate; // format: YYYY-MM-DD

public:
    EMI() : id(0), customerId(0), amount(0.0) {}
    EMI(int id, int customerId, double amount, const std::string& dueDate)
        : id(id), customerId(customerId), amount(amount), dueDate(dueDate) {}

    int getId() const { return id; }
    int getCustomerId() const { return customerId; }
    double getAmount() const { return amount; }
    std::string getDueDate() const { return dueDate; }

    void setId(int val) { id = val; }
    void setCustomerId(int val) { customerId = val; }
    void setAmount(double val) { amount = val; }
    void setDueDate(const std::string& val) { dueDate = val; }

    void print() const {
        std::cout << "EMI ID: " << id
                  << ", Customer ID: " << customerId
                  << ", Amount: " << amount
                  << ", Due Date: " << dueDate << std::endl;
    }
};
