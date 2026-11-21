#pragma once

#include "Command.h"

#include <memory>

class ShipOrderCommand : public Command {
public:
    explicit ShipOrderCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
