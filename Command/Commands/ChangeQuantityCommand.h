#pragma once

#include"Command.h"

#include<memory>

class ChangeQuantityCommand:public Command{
    private:
    int productId_;
    int amount_;

    public:
    ChangeQuantityCommand(std::shared_ptr<ShopFacade> facade, int productId, int amount);
    void execute() override;
};
