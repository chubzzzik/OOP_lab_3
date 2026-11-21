#pragma once

#include "Command.h"

#include <memory>

class ConfirmPaymentCommand : public Command {
public:
    explicit ConfirmPaymentCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
