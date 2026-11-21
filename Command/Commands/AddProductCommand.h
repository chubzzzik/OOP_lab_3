#pragma once

#include "Command.h"

#include <memory>

class AddProductCommand : public Command {
public:
    explicit AddProductCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
