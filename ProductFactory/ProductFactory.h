#pragma once

#include"Product.h"

#include<memory>
#include<string>

class ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(const std::string& category, const std::string& name,
    int price, double weight, int quantity);
};