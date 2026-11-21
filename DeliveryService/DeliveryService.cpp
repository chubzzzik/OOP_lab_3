#include"DeliveryService.h"
#include"Order.h"
#include"Delivery.h"

#include<stdexcept>
#include<memory>


DeliveryService::DeliveryService(int couriers, int pickupPoints, int postOffices):
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

bool DeliveryService::isAvailable(const Order& order){
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

int DeliveryService::calculateCost(const Order& order){
    if(order.getDelivery() == nullptr){
        throw std::logic_error("Order has no delivery yet"); 
    }
    return order.getDelivery()->getCost(order);
}

void DeliveryService::scheduleDelivery(Order& order, const std::shared_ptr<Delivery>& delivery){
    if(delivery == nullptr){
        throw std::invalid_argument("This delivery does not exist");
    }
    if(!(delivery->isAvailable(order))){
        throw std::logic_error("This delivery is not availabl for this order");
    }

    if(delivery->getType() == "courier" && couriers_ > 0){
        order.setDelivery(delivery);
        couriers_--;
        return;
    }
    if(delivery->getType() == "pickup" && pickupPoints_ > 0){
        order.setDelivery(delivery);
        pickupPoints_--;
        return;
    }
    if(delivery->getType() == "post" && postOffices_ > 0){
        order.setDelivery(delivery);
        postOffices_--;
        return;
    }

    throw std::logic_error("There are no resources left for this delivery");
}