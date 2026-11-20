#include"PickupDelivery.h"

int PickupDelivery::getCost(const Order&) const {
    return 0;
}

std::string PickupDelivery::getEstimatedTime() const {
    return "1-3 дня";
}

bool PickupDelivery::isAvailable(const Order&) const {
    return true;
}