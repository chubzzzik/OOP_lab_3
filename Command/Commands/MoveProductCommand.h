#pragma once

#include "Command.h"

#include <memory>

class MoveProductCommand : public Command {
public:
    explicit MoveProductCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
