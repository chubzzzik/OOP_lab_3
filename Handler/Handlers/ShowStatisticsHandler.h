#pragma once

#include"Handler.h"

#include<string>
#include<memory>

class ShopFacade;

class ShowStatisticsHandler:public Handler {
    private:
    std::shared_ptr<ShopFacade> facade_;

    public:
    ShowStatisticsHandler(std::shared_ptr<ShopFacade> facade);
    bool handle(const std::string& input) override;
};
