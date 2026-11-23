#pragma once

#include"Handler.h"

#include<string>
#include<memory>

class ShopFacade;

class MoveProductHandler:public Handler {
    private:
    std::shared_ptr<ShopFacade> facade_;

    public:
    MoveProductHandler(std::shared_ptr<ShopFacade> facade);
    bool handle(const std::string& input) override;
};
