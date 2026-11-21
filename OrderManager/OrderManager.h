#pragma once

#include"Order.h"
#include"Observer.h"

#include<vector>
#include<memory>
#include<string>
#include<unordered_map>

class OrderManager:public Observer{
    private:
    std::unordered_map<int, std::shared_ptr<Order>> orders_;
    std::vector<std::string> customers_;
    int turnover_ = 0;
    int activeOrders_ = 0;

    public:
    int createOrder(const std::string& customer, const std::string& region);
    void cancelOrder(int orderId);
    void confirmPayment(int orderId);
    void shipOrder(int orderId);
    void deliverOrder(int orderId);
    void getStatistics() const;
    void onOrderEvent(const OrderEvent& event) override;
    std::shared_ptr<Order> findById(int orderId) const;
    bool isProductReserved(int productId) const;

    OrderManager() = default;
    OrderManager(const OrderManager&) = delete;
    OrderManager& operator=(const OrderManager&) = delete;
};