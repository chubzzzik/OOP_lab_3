#pragma once

#include<memory>
#include<string>
#include<vector>

class Warehouse;
class OrderManager;
class DeliveryService;
class PaymentSystem;
class Product;
class Delivery;

class ShopMediator{
    private:
    std::shared_ptr<Warehouse> warehouse_;
    std::shared_ptr<OrderManager> orderManager_;
    std::shared_ptr<DeliveryService> deliveryService_;
    std::shared_ptr<PaymentSystem> paymentSystem_;

    public:
    ~ShopMediator() = default;
    ShopMediator(std::shared_ptr<Warehouse> w, std::shared_ptr<OrderManager> o,
        std::shared_ptr<DeliveryService> d, std::shared_ptr<PaymentSystem> p);

    int createOrder(const std::string& customer, const std::vector<std::shared_ptr<Product>>& items,
        const std::shared_ptr<Delivery>& deliveryType, const std::string& region);
    void confirmPayment(int id);
    void shipOrder(int id);
    void cancelOrder(int id);
    void getStatistics() const;

    void onProductAdded(int id);
    void onProductChanged(int id);
    void onProductRemoved(int id);
};