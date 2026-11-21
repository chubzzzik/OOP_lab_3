#pragma once

#include"Command.h"

#include<memory>

class Warehouse;

class MoveProductCommand:public Command{
    private:
    int productId_;
    std::shared_ptr<Warehouse> targetWarehouse_;

    public:
    MoveProductCommand(std::shared_ptr<ShopFacade> facade, int productId,
        std::shared_ptr<Warehouse> targetWarehouse);
    void execute() override;
};
