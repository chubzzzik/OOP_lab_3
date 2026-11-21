#pragma once

#include"Command.h"

#include<memory>

class CancelOrderCommand:public Command{
    private:
    int orderId_;

    public:
    CancelOrderCommand(std::shared_ptr<ShopFacade> facade, int orderId);
    void execute() override;
};
