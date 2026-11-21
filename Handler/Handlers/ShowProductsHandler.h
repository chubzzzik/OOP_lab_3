#pragma once

#include "Handler.h"

#include <string>

class ShowProductsHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
