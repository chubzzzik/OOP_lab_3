#include"OrderEvent.h"
#include"OrderStatus.h"

OrderEvent::OrderEvent(int id, OrderStatus oldSt, OrderStatus newSt):orderId_(id),
    oldStatus_(oldSt),newStatus_(newSt){}

int OrderEvent::getId()const{
    return orderId_;
}

OrderStatus OrderEvent::getOldStatus() const{
    return oldStatus_;
}

OrderStatus OrderEvent::getNewStatus() const{
    return newStatus_;
}