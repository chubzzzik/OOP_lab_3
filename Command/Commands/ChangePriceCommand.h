#pragma once

#include"Command.h"

#include<memory>

class ChangePriceCommand:public Command{
    private:
    int productId_;
    int newPrice_;

    public:
    ChangePriceCommand(std::shared_ptr<ShopFacade> facade, int productId, int newPrice);
    void execute() override;
};
