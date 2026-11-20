#include"CashDiscount.h"
#include"Order.h"

void CashDiscount::apply(Order& order) const {;
    order.addDiscountAmount(500);
}