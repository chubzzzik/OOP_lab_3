#pragma once

#include"Product.h"

#include<memory>

class ProductFactory{
    public:
    std::unique_ptr<Product> createProduct(const std::string& type, const std::string& name,
    int price, int quantity);
};