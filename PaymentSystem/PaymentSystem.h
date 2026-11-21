#pragma once

class Order;

class PaymentSystem{
    private:
    int balance_;

    public:
    ~PaymentSystem() = default;
    PaymentSystem(int balance);
    void processPayment(const Order& order);
    void refund(const Order& order);
    int checkBalance() const;
};
