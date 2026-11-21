#pragma once

#include"Command.h"

#include<memory>

class ConfirmPaymentCommand:public Command{
    private:
    int orderId_;

    public:
    ConfirmPaymentCommand(std::shared_ptr<ShopFacade> facade, int orderId);
    void execute() override;
};
