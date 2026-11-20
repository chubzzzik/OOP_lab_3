#pragma once

#include"Delivery.h"

#include<memory>

class DeliveryProxy:public Delivery{
    private:
    std::shared_ptr<Delivery> realDelivery_;
    std::string availableRegion_;
    
    public:
    DeliveryProxy(const std::shared_ptr<Delivery>& delivery, const std::string& reg);
    int getCost(const Order& order) const override;
    std::string getEstimatedTime() const override;
    bool isAvailable(const Order&) const override;
};