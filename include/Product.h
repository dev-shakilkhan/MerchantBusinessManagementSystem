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
    Product() : id(0), price(0.0), stock(0) {}
    Product(int id, const std::string& name, const std::string& category, double price, int stock)
        : id(id), name(name), category(category), price(price), stock(stock) {}

    // Getters
    int getId() const { return id; }
    std::string getName() const { return name; }
    std::string getCategory() const { return category; }
    double getPrice() const { return price; }
    int getStock() const { return stock; }

    // Setters
    void setId(int val) { id = val; }
    void setName(const std::string& val) { name = val; }
    void setCategory(const std::string& val) { category = val; }
    void setPrice(double val) { price = val; }
    void setStock(int val) { stock = val; }

    // Print product info
    void print() const {
        std::cout << "ID: " << id
                  << ", Name: " << name
                  << ", Category: " << category
                  << ", Price: " << price
                  << ", Stock: " << stock << std::endl;
    }
};
