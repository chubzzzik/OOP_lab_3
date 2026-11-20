#pragma once 

#include"Delivery.h"

class PostDelivery:public Delivery{
    public:
    int getCost(const Order&) const override;
    std::string getEstimatedTime() const override;
    bool isAvailable(const Order& order) const override;
    std::string getType() const override;
};