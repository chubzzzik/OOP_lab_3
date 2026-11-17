#pragma once

#include"Attributes.h"

#include<string>

class Product{
    private:
    static int nextId_;
    int id_;
    std::string category_;
    std::string name_;
    Price price_;
    Weight weight_;
    Quantity quantity_;
    
    public:
    Product(const std::string& category, const std::string& name, const Price& price,
        const Weight& weight, const Quantity& quantity);
    ~Product() = default;
    Product* clone();
    void changePrice(const Price& newPrice);
    void changeQuantity(int delta);
    int getId() const;
    const std::string& getCategory() const;
    const std::string& getName() const;
    const Price& getPrice() const;
    const Weight& getWeight() const;
    const Quantity& getQuantity() const;
};