#pragma once

#include"Command.h"

class AddProductCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    AddProductCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class ChangePriceCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    ChangePriceCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class ChangeQuantityCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    ChangeQuantityCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class MoveProductCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    MoveProductCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class RemoveProductCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    RemoveProductCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class CreateOrderCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    CreateOrderCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class CancelOrderCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    CancelOrderCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class ConfirmPaymentCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    ConfirmPaymentCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class ShipOrderCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    ShipOrderCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class ShowStatisticsCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    ShowStatisticsCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class ShowProductsCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    ShowProductsCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};

class ShowOrdersCommand:public Command{
    private:
    // TODO: написать поля потом
    public:
    ShowOrdersCommand(std::shared_ptr<ShopMediator>);
    void execute() override;
};