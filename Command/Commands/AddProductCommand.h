#pragma once

#include"Command.h"

#include<memory>
#include<string>

class AddProductCommand:public Command{
    private:
    std::string type_;
    std::string name_;
    int price_;
    int quantity_;

    public:
    AddProductCommand(std::shared_ptr<ShopFacade> facade, const std::string& type,
        const std::string& name, int price, int quantity);
    void execute() override;
};