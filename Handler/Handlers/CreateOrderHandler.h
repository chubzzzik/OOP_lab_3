#pragma once

#include "Handler.h"

#include <string>

class CreateOrderHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
