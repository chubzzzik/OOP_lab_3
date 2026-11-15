#pragma once

#include"Order.h"
#include"Product.h"

#include<unordered_map>
#include<memory>
#include<string>
#include<vector>

class OrderManager{
    private:
    std::unordered_map<int, std::shared_ptr<Order>> orders_;

    public:
    int createOrder(const std::string& customer, const std::vector<std::shared_ptr<Product>>& items,
        const std::string& deliveryType);
    void cancelOrder(int id);
    void confirmPayment(int id);
    void shipOrder(int id);
    void getStatistics() const;
};