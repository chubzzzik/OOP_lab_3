#include"PaymentSystem.h"
#include"Order.h"
#include"OrderStatus.h"

#include<stdexcept>

PaymentSystem::PaymentSystem(int balance):balance_(balance){
    if(balance < 0){
        throw std::invalid_argument("Balance cannot be negative");
    }
}

void PaymentSystem::processPayment(const Order& order){
    if(order.getStatus() == OrderStatus::Pending){
        balance_ += order.getTotalPrice();
        return;
    }
    throw std::logic_error("Order already paid or cancelled");
}

void PaymentSystem::refund(const Order& order){
    if(order.getStatus() == OrderStatus::Paid){
        if(balance_ < order.getTotalPrice()){
            throw std::logic_error("PaymetSystem balance does not enough money");
        }
        balance_ -= order.getTotalPrice();
        return;
    }
    throw std::logic_error("Order cannot be refund");
}

int PaymentSystem::checkBalance() const{
    return balance_;
}

void PaymentSystem::setMediator(std::weak_ptr<ShopMediator> med){
    mediator_ = med;
}  