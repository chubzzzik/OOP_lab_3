#pragma once

#include "Handler.h"

#include <string>

class MoveProductHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
