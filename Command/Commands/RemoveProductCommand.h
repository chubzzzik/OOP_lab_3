#pragma once

#include"Command.h"

#include<memory>

class RemoveProductCommand:public Command{
    private:
    int productId_;

    public:
    RemoveProductCommand(std::shared_ptr<ShopFacade> facade, int productId);
    void execute() override;
};
