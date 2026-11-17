#include"ProductFactory.h"
#include"Attributes.h"
#include"Product.h"

#include<memory>
#include<string>

std::unique_ptr<Product> ProductFactory::createProduct(const std::string& category, const std::string& name,
    int price, double weight, int quantity){
        return std::make_unique<Product>(category, name, Price(price), Weight(weight), Quantity(quantity));
    }