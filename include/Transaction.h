#pragma once
#include <string>
#include <iostream>

class Transaction {
private:
    int id;
    std::string type; // "sale" or "expense"
    double amount;
    std::string date; // format: YYYY-MM-DD

public:
    Transaction() : id(0), amount(0.0) {}
    Transaction(int id, const std::string& type, double amount, const std::string& date)
        : id(id), type(type), amount(amount), date(date) {}

    int getId() const { return id; }
    std::string getType() const { return type; }
    double getAmount() const { return amount; }
    std::string getDate() const { return date; }

    void setId(int val) { id = val; }
    void setType(const std::string& val) { type = val; }
    void setAmount(double val) { amount = val; }
    void setDate(const std::string& val) { date = val; }

    void print() const {
        std::cout << "Transaction ID: " << id
                  << ", Type: " << type
                  << ", Amount: " << amount
                  << ", Date: " << date << std::endl;
    }
};
