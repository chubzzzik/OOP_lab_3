#pragma once

class Order;

class DeliverySystem{
    private:
    int couriers_;
    int pickupPoints_;
    int postOffices_;
    
    public:
    ~DeliverySystem() = default;
    DeliverySystem(int couriers, int pickupPoints, int postOffices);
    bool isAvailable(const Order&);
    int calculateCost(const Order&);
    void scheduleDelivery(const Order&);

};