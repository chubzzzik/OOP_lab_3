#pragma once

#include"ShopMediator.h"

#include<memory>

class Order;

class PaymentSystem{
    private:
    int balance_;
    std::weak_ptr<ShopMediator> mediator_;

    public:
    ~PaymentSystem() = default;
    PaymentSystem(int balance);
    void processPayment(const Order& order);
    void refund(const Order& order);
    int checkBalance() const;
    void setMediator(std::weak_ptr<ShopMediator> med);

};
