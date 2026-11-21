#pragma once

#include "Handler.h"

#include <string>

class ShipOrderHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
