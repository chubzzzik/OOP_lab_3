#pragma once

#include<memory>
#include<string>
#include<vector>

class Warehouse;
class ShopMediator;
class CommandHistory;
class Handler;
class Delivery;
class Product;
class Command;

class ShopFacade{
    private:
    std::shared_ptr<Warehouse> warehouse_;
    std::shared_ptr<ShopMediator> mediator_;
    std::shared_ptr<CommandHistory> history_;
    std::shared_ptr<Handler> inputHandler_;

    public:
    ~ShopFacade() = default;
    ShopFacade(std::shared_ptr<Warehouse> warehouse, std::shared_ptr<ShopMediator> mediator,
        std::shared_ptr<CommandHistory> history, std::shared_ptr<Handler> inputHandler);
    void addProduct(const std::string& type, const std::string& name, int price, double weight, int quantity);
    void changePrice(int productId, int newPrice);
    void changeQuantity(int productId, int amount);
    void moveProduct(int productId, std::shared_ptr<Warehouse> targetWarehouse);
    void removeProduct(int productId);
    void listProducts();

    int createOrder(const std::string& customer, const std::vector<std::shared_ptr<Product>>& items,
        const std::shared_ptr<Delivery>& deliveryType, const std::string& region);
    void cancelOrder(int orderId);
    void confirmPayment(int orderId);
    void shipOrder(int orderId);
    void listOrders();
    void getStatistics();

    void executeCommand(std::shared_ptr<Command> command);
    void processInput(const std::string& input);
};