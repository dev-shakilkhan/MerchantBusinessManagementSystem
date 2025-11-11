#pragma once
#include "Product.h"
#include <vector>
#include <string>

class ProductManager {
private:
    std::vector<Product> products;
    std::string filename;

public:
    ProductManager(const std::string& filename);

    // File operations
    void load();
    void save();

    // Product operations
    void addProduct(const Product& product);
    void listProducts() const;
    Product* searchById(int id);
    void updateProduct(int id);
    void deleteProduct(int id);

    // Utility
    int generateId() const;
};
