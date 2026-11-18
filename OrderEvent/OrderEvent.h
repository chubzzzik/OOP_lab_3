#pragma once

#include"OrderStatus.h"

class OrderEvent{
    private:
    int orderId_;
    OrderStatus oldStatus_;
    OrderStatus newStatus_;
    
    public:
    OrderEvent(int id, OrderStatus oldSt, OrderStatus newSt);
    int getId() const;
    OrderStatus getOldStatus() const;
    OrderStatus getNewStatus() const;
};