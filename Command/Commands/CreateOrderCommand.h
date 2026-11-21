#pragma once

#include"Command.h"

#include<memory>
#include<string>
#include<vector>

class Product;
class Delivery;

class CreateOrderCommand:public Command{
    private:
    std::string customer_;
    std::vector<std::shared_ptr<Product>> items_;
    std::shared_ptr<Delivery> deliveryType_;
    std::string region_;

    public:
    CreateOrderCommand(std::shared_ptr<ShopFacade> facade, const std::string& customer,
        const std::vector<std::shared_ptr<Product>>& items,
        const std::shared_ptr<Delivery>& deliveryType, const std::string& region);
    void execute() override;
};
