#pragma once
#include<iostream>
#include<string>

class Product{
public:
    int id;
    std::string name;
    std::string category;
    double price;
    int stock;
    int reorder_level;

    Product();
    Product(int id, const std::string& name, const std::string& catergory, double price, int stock, int reorder_levele);

    void validate() const;
    void adjustStock()(int delta);

};