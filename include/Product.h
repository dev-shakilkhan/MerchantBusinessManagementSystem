#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>
#include <iostream>
#include <vector>

class Product {
private:
    int id;
    std::string name;
    std::string category;
    double price;
    int stock;

public:
    Product();
    Product(int id, const std::string& name, const std::string& category, double price, int stock);

    void display() const;

    int getId() const;
    std::string getName() const;
    int getStock() const;
    void setStock(int newStock);

    // file I/O
    void saveToFile(const std::string& filename);
    static void loadFromFile(const std::string& filename, std::vector<Product>& products);
};

#endif
