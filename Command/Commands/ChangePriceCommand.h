#pragma once

#include "Command.h"

#include <memory>

class ChangePriceCommand : public Command {
public:
    explicit ChangePriceCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
