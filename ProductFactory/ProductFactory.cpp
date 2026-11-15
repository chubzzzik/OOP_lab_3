#include"ProductFactory.h"

#include<memory>

std::unique_ptr<Product> ProductFactory::createProduct(const std::string& type, const std::string& name,
    int price, int quantity){
        return std::make_unique<Product>(name, Price(price), Quantity(quantity), type);
    }