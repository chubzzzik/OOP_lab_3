#pragma once

#include<memory>

class Warehouse;
class OrderManager;
class DeliveryService;
class PaymentSystem;

class ShopMediator{
    private:
    std::shared_ptr<Warehouse> warehouse_;
    std::shared_ptr<OrderManager> orderManager_;
    std::shared_ptr<DeliveryService> deliveryService_;
    std::shared_ptr<PaymentSystem> paymentSystem_;

    public:
    ShopMediator(std::shared_ptr<Warehouse> w, std::shared_ptr<OrderManager> o,
        std::shared_ptr<DeliveryService> d, std::shared_ptr<PaymentSystem> p);
};