#pragma once
#include <string>
#include <iostream>

class Product {
private:
    int id;
    std::string name;
    std::string category;
    double price;
    int stock;

public:
    // Constructors
    Product();
    Product(int id, const std::string& name, const std::string& category, double price, int stock);

    // Getters
    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getStock() const;

    // Setters
    void setName(const std::string& name);
    void setCategory(const std::string& category);
    void setPrice(double price);
    void setStock(int stock);

    // Display method
    void display() const;
};
