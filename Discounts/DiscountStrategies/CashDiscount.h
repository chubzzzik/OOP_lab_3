#pragma once

#include"Discount.h"

class CashDiscount:public Discount{
    public:
    void apply(Order&) const override;
};