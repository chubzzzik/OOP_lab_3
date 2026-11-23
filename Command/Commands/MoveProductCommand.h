#pragma once

#include"Command.h"

#include<memory>

class Warehouse;

class MoveProductCommand:public Command{
    private:
    int productId_;
    int targetWarehouseId_;

    public:
    MoveProductCommand(std::shared_ptr<ShopFacade> facade, int productId, int targetWarehouseId);
    void execute() override;
};
