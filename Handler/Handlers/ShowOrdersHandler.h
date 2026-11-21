#pragma once

#include "Handler.h"

#include <string>

class ShowOrdersHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
