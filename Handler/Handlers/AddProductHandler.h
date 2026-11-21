#pragma once

#include "Handler.h"

#include <string>

class AddProductHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
