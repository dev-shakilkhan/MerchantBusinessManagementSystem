#include "include/Product.h"

Product::Product() : id(0), price(0.0), stock(0) {}

Product::Product(int id, const std::string& name, const std::string& category, double price, int stock)
    : id(id), name(name), category(category), price(price), stock(stock) {}

int Product::getId() const { return id; }
std::string Product::getName() const { return name; }
std::string Product::getCategory() const { return category; }
double Product::getPrice() const { return price; }
int Product::getStock() const { return stock; }

void Product::setName(const std::string& name) { this->name = name; }
void Product::setCategory(const std::string& category) { this->category = category; }
void Product::setPrice(double price) { this->price = price; }
void Product::setStock(int stock) { this->stock = stock; }

void Product::display() const {
    std::cout << "ID: " << id
              << "\nName: " << name
              << "\nCategory: " << category
              << "\nPrice: " << price
              << "\nStock: " << stock << "\n";
}
