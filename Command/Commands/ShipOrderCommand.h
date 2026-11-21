#pragma once

#include"Command.h"

#include<memory>

class ShipOrderCommand:public Command{
    private:
    int orderId_;

    public:
    ShipOrderCommand(std::shared_ptr<ShopFacade> facade, int orderId);
    void execute() override;
};
