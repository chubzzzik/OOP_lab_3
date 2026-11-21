#pragma once

#include "Command.h"

#include <memory>

class RemoveProductCommand : public Command {
public:
    explicit RemoveProductCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
