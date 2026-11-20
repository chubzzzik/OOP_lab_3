#pragma once

class OrderEvent;

class Observer{
    public:
    virtual ~Observer() = default;
    virtual void onOrderEvent(const OrderEvent&) = 0;
};