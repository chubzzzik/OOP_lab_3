#pragma once

#include "Command.h"

#include <memory>

class ShowProductsCommand : public Command {
public:
    explicit ShowProductsCommand(std::shared_ptr<ShopFacade> facade);
    void execute() override;
};
