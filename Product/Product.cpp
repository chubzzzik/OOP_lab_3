#include"Product.h"

int Product::nextId_ = 1;

Product::Product(const std::string& name, const Price& price, const Quantity& quantity,
    const std::string& category):name_(name),price_(price),quantity_(quantity),category_(category){
    id_ = nextId_++;
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

const std::string& Product::getName() const{
    return name_;
}

const Price& Product::getPrice() const{
    return price_;
}

const Quantity& Product::getQuantity() const{
    return quantity_;
}

const std::string& Product::getCategory() const{
    return category_;
}