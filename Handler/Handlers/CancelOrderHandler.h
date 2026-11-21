#pragma once

#include "Handler.h"

#include <string>

class CancelOrderHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
