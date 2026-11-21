#pragma once

#include"Command.h"

#include<memory>

class ShowOrdersCommand:public Command{
    public:
    explicit ShowOrdersCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
