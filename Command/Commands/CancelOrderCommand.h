#pragma once

#include "Command.h"

#include <memory>

class CancelOrderCommand : public Command {
public:
    explicit CancelOrderCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
