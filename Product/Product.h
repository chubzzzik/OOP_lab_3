#pragma once

#include"Attributes.h"

#include<string>

class Product{
    private:
    static int nextId_;
    int id_;
    std::string name_;
    Price price_;
    Quantity quantity_;
    std::string category_;

    public:
    Product(const std::string& name, const Price& price,
        const Quantity& quantity, const std::string& category);
    virtual ~Product() = default;
    void changePrice(const Price& newPrice);
    void changeQuantity(int delta);
    int getId() const;
    const std::string& getName() const;
    const Price& getPrice() const;
    const Quantity& getQuantity() const;
    const std::string& getCategory() const;
};