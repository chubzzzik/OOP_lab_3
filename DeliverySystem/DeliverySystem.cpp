#include"DeliverySystem.h"
#include"Order.h"

#include<stdexcept>

DeliverySystem::DeliverySystem(int couriers, int pickupPoints, int postOffices):
    couriers_(couriers), pickupPoints_(pickupPoints), postOffices_(postOffices){
        if(couriers < 0){
            throw std::invalid_argument("Couriers count cannot be negative");
        }
        if(pickupPoints < 0){
            throw std::invalid_argument("Pickup points count cannot be negative");
        }
        if(postOffices < 0){
            throw std::invalid_argument("Post offices count cannot be negative");
        }
    }

bool DeliverySystem::isAvailable(const Order& order){
    if(order.getDelivery() == nullptr){
        throw std::logic_error("Order has no delivery yet"); 
    }
    if(order.getDelivery()->isAvailable(order)){
        if(order.getDelivery()->getType() == "courier" && couriers_ > 0){
            return true;
        }
        if(order.getDelivery()->getType() == "pickup" && pickupPoints_ > 0){
            return true;
        }
        if(order.getDelivery()->getType() == "post" && postOffices_ > 0){
            return true;
        }
        return false;
    }
    return false;
}

int DeliverySystem::calculateCost(const Order& order){
    if(order.getDelivery() == nullptr){
        throw std::logic_error("Order has no delivery yet"); 
    }
    return order.getDelivery()->getCost(order);
}

void DeliverySystem::scheduleDelivery(const Order& order){
    if(order.getDelivery() == nullptr){
        throw std::logic_error("Order has no delivery yet");
    }
    if(!isAvailable(order)){
        throw std::logic_error("Delivery is not available");
    }

    const std::string type = order.getDelivery()->getType();

    if(type == "courier"){
        couriers_--;
        return;
    }
    if(type == "pickup"){
        pickupPoints_--;
        return;
    }
    if(type == "post"){
        postOffices_--;
        return;
    }

    throw std::logic_error("Unknown delivery type");
}