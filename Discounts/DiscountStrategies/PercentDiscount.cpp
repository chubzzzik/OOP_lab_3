#include"PercentDiscount.h"
#include"Order.h"

void PercentDiscount::apply(Order& order) const {
    int value = (order.getTotalPrice())/10;
    order.addDiscountAmount(value);
}