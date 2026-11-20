#include"CourierDelivery.h"
#include"Order.h"

int CourierDelivery::getCost(const Order&) const {
    return 500;
}

std::string CourierDelivery::getEstimatedTime() const {
    return "1-2 дня";
}

bool CourierDelivery::isAvailable(const Order& order) const {
    if(order.getTotalWeight() <= 20){
        return true;
    }
    return false;
}

std::string CourierDelivery::getType() const {
    return "courier";
}