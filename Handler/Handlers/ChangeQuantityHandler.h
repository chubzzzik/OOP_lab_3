#pragma once

#include "Handler.h"

#include <string>

class ChangeQuantityHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
