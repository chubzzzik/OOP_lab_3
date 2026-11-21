#pragma once

#include "Handler.h"

#include <string>

class HelpHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
