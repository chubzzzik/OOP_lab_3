#pragma once

#include"Handler.h"

#include<string>
#include<memory>

class ShopFacade;

class ShowProductsHandler:public Handler {
    private:
    std::shared_ptr<ShopFacade> facade_;

    public:
    ShowProductsHandler(std::shared_ptr<ShopFacade> facade);
    bool handle(const std::string& input) override;
};
