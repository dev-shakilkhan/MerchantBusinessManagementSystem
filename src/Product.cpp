#include "Product.h"
#include <fstream>
#include <vector>

Product::Product() : id(0), price(0), stock(0) {}

Product::Product(int id, const std::string& name, const std::string& category, double price, int stock)
: id(id), name(name), category(category), price(price), stock(stock) {}

void Product::display() const {
    std::cout << "ID: " << id 
              << ", Name: " << name 
              << ", Category: " << category
              << ", Price: " << price
              << ", Stock: " << stock << std::endl;
}

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
int Product::getStock() const { return stock; }
void Product::setStock(int newStock) { stock = newStock; }

void Product::saveToFile(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary | std::ios::app);
    file.write((char*)this, sizeof(Product));
    file.close();
}

void Product::loadFromFile(const std::string& filename, std::vector<Product>& products) {
    products.clear();
    std::ifstream file(filename, std::ios::binary);
    if(!file) return;
    Product temp;
    while(file.read((char*)&temp, sizeof(Product))) {
        products.push_back(temp);
    }
    file.close();
}
