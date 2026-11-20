#pragma once

#include"Delivery.h"
#include"ShopMediator.h"

#include<memory>

class Order;

class DeliveryService{
    private:
    int couriers_;
    int pickupPoints_;
    int postOffices_;
    std::weak_ptr<ShopMediator> mediator_;
    
    public:
    ~DeliveryService() = default;
    DeliveryService(int couriers, int pickupPoints, int postOffices);
    bool isAvailable(const Order&);
    int calculateCost(const Order&);
    void scheduleDelivery(Order& order, const std::shared_ptr<Delivery>& delivery);
    void setMediator(std::weak_ptr<ShopMediator> med);
};