#pragma once

#include"Handler.h"

#include<string>

class AddProductHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class ChangePriceHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class ChangeQuantityHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class MoveProductHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class RemoveProductHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class CreateOrderHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class CancelOrderHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class ConfirmPaymentHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class ShipOrderHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class ShowStatisticsHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class ShowProductsHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class ShowOrdersHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};

class HelpHandler:public Handler{
    public:
    bool handle(const std::string& cmd) override;
};