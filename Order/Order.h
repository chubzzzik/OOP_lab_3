#pragma once

#include"Product.h"

#include<string>
#include<vector>
#include<memory>

enum class OrderStatus{ Pending, Paid, Shipped, Delivered, Cancelled };

class Order{
    private:
    static int nextId_;
    int id_;
    std::string customer_;
    std::vector<std::shared_ptr<Product>> items_;
    OrderStatus status_;
    std::string deliveryType_;
    int totalPrice_;

    public:
    Order(const std::string& customer, OrderStatus status, const std::string& delivery);
    int getId() const;
    const std::string& getCustomer() const;
    const std::vector<std::shared_ptr<Product>>& getItems() const;
    OrderStatus getStatus() const;
    const std::string& getDeliveryType() const;
    int getTotalPrice() const;
    void addItem(const std::shared_ptr<Product>& item);
    void setStatus(const OrderStatus& newStatus);
};