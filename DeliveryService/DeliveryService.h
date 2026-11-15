#pragma once

#include<string>

class DeliveryService{
    private:
    int couriers_;
    int pickupPoints_;
    int postOffices_;

    public:
    DeliveryService(int couriers, int points, int offices);
    bool isAvailable(const std::string& deliveryType);
    int calculateCost(const std::string& deliveryType);
    void scheduleDelivery(int orderId, const std::string& deliveryType);
};