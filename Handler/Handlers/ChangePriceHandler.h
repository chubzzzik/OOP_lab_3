#pragma once

#include "Handler.h"

#include <string>

class ChangePriceHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
