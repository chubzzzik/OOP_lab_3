#pragma once

#include "Handler.h"

#include <string>

class RemoveProductHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
