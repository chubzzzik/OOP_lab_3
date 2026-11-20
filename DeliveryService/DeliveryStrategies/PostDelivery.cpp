#include"PostDelivery.h"
#include"Order.h"

int PostDelivery::getCost(const Order&) const {
    return 200;
}

std::string PostDelivery::getEstimatedTime() const {
    return "5-10 дней";
}

bool PostDelivery::isAvailable(const Order& order) const {
    if(order.getTotalWeight() <= 10){
        return true;
    }
    return false;
}

std::string PostDelivery::getType() const {
    return "post";
}