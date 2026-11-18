#include"DeliveryProxy.h"
#include"Order.h"

#include<memory>
#include<stdexcept>
#include<iostream>

constexpr int kgMaxDeliveryWeight = 1500;

DeliveryProxy::DeliveryProxy(const std::shared_ptr<Delivery>& delivery, const std::string& reg):availableRegion_(reg){
    if(delivery == nullptr){
        throw std::invalid_argument("DeliveryProxy: real delivery must not be null");
    }
    realDelivery_ = delivery;
}

double DeliveryProxy::getCost(const Order& order) const{
    return realDelivery_->getCost(order);
}

std::string DeliveryProxy::getEstimatedTime() const{
    return realDelivery_->getEstimatedTime();
}

bool DeliveryProxy::isAvailable(const Order& order) const{
    int weight = order.getTotalWeight();
    if(weight >= kgMaxDeliveryWeight){
        return false;
    }
    if(order.getRegion() != availableRegion_){
        return false;
    }
    bool result = realDelivery_->isAvailable(order);
    return result;
}