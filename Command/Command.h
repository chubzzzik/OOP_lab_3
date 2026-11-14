#pragma once

#include<memory>
class ShopMediator;

class Command{
    protected:
    std::shared_ptr<ShopMediator> mediator_;

    public:
    virtual ~Command() = default;
    Command(std::shared_ptr<ShopMediator> med);
    virtual void execute() = 0;
};