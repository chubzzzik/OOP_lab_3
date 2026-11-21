#pragma once

#include"Command.h"

#include<memory>

class ShowStatisticsCommand:public Command{
    public:
    explicit ShowStatisticsCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
