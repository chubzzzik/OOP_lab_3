#pragma once

#include"Observer.h"

#include<vector>

class OrderEvent;

class Observable{
    private:
    std::vector<Observer*> subs_;

    public:
    virtual ~Observable() = default;
    void subscribe(Observer*);
    void unsubscribe(Observer*);
    void notify(const OrderEvent&);
};