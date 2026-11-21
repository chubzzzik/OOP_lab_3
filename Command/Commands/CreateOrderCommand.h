#pragma once

#include "Command.h"

#include <memory>

class CreateOrderCommand : public Command {
public:
    explicit CreateOrderCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
