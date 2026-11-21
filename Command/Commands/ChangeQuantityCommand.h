#pragma once

#include "Command.h"

#include <memory>

class ChangeQuantityCommand : public Command {
public:
    explicit ChangeQuantityCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
