#pragma once

#include "Handler.h"

#include <string>

class ConfirmPaymentHandler : public Handler {
public:
    bool handle(const std::string& input) override;
};
