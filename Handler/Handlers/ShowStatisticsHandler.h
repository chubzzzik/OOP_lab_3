#pragma once

#include "Handler.h"

#include <string>

class ShowStatisticsHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
