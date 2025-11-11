#include "include/ProductManager.h"
#include <fstream>
#include <iostream>
#include <limits>

ProductManager::ProductManager(const std::string& filename) : filename(filename) {
    load();
}

// Load products from binary file
void ProductManager::load() {
    products.clear();
    std::ifstream file(filename, std::ios::binary);
    if (!file) return;

    Product p;
    while (file.read(reinterpret_cast<char*>(&p), sizeof(Product))) {
        products.push_back(p);
    }
    file.close();
}

// Save products to binary file
void ProductManager::save() {
    std::ofstream file(filename, std::ios::binary | std::ios::trunc);
    for (const auto& p : products) {
        file.write(reinterpret_cast<const char*>(&p), sizeof(Product));
    }
    file.close();
}

// Add product
void ProductManager::addProduct(const Product& product) {
    products.push_back(product);
    save();
}

// List all products
void ProductManager::listProducts() const {
    if (products.empty()) {
        std::cout << "No products available.\n";
        return;
    }

    for (const auto& p : products) {
        p.display();
        std::cout << "----------------------\n";
    }
}

// Search product by ID
Product* ProductManager::searchById(int id) {
    for (auto& p : products) {
        if (p.getId() == id)
            return &p;
    }
    return nullptr;
}

// Update product by ID
void ProductManager::updateProduct(int id) {
    Product* p = searchById(id);
    if (!p) {
        std::cout << "Product not found.\n";
        return;
    }

    std::cout << "Enter new name: ";
    std::string name; std::cin >> name;
    p->setName(name);

    std::cout << "Enter new category: ";
    std::string category; std::cin >> category;
    p->setCategory(category);

    std::cout << "Enter new price: ";
    double price; std::cin >> price;
    p->setPrice(price);

    std::cout << "Enter new stock: ";
    int stock; std::cin >> stock;
    p->setStock(stock);

    save();
    std::cout << "Product updated successfully.\n";
}

// Delete product by ID
void ProductManager::deleteProduct(int id) {
    for (auto it = products.begin(); it != products.end(); ++it) {
        if (it->getId() == id) {
            products.erase(it);
            save();
            std::cout << "Product deleted successfully.\n";
            return;
        }
    }
    std::cout << "Product not found.\n";
}

// Generate next product ID
int ProductManager::generateId() const {
    int maxId = 0;
    for (const auto& p : products)
        if (p.getId() > maxId) maxId = p.getId();
    return maxId + 1;
}
