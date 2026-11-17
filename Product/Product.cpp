#include"Product.h"
#include"Attributes.h"

#include<string>

int Product::nextId_ = 1;

Product::Product(const std::string& category, const std::string& name, const Price& price,
    const Weight& weight, const Quantity& quantity):category_(category), name_(name),
    price_(price), weight_(weight), quantity_(quantity){
        id_ = nextId_++;
    }

Product* Product::clone(){
    return new Product(*this);
}

void Product::changePrice(const Price& newPrice){
    price_ = newPrice;
}

void Product::changeQuantity(int delta){
    quantity_.change(delta);
}

int Product::getId() const{
    return id_;
}

const std::string& Product::getCategory() const{
    return category_;
}

const std::string& Product::getName() const{
    return name_;
}

const Price& Product::getPrice() const{
    return price_;
}

const Weight& Product::getWeight() const{
    return weight_;
}

const Quantity& Product::getQuantity() const{
    return quantity_;
}