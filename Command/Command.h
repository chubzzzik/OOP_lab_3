#pragma once

#include<memory>

class ShopFacade;

class Command{
    protected:
    std::shared_ptr<ShopFacade> facade_;

    public:
    Command(std::shared_ptr<ShopFacade> facade);
    virtual ~Command() = default;
    virtual void execute() = 0;
};