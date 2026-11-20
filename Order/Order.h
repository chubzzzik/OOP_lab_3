#pragma once

#include"Discount.h"
#include"Delivery.h"
#include"Product.h"
#include"OrderStatus.h"
#include"Observable.h"

#include<string>
#include<vector>
#include<ostream>
#include<memory>

class Order:public Observable{
    private:
    static int nextId_;
    int id_;
    std::string customer_;
    std::vector<std::shared_ptr<Product>> items_;
    OrderStatus status_;
    std::shared_ptr<Delivery> delivery_;
    std::vector<std::shared_ptr<Discount>> discounts_;
    int totalDiscount_;
    bool isDeliveryFree_;
    std::string region_;

    public:
    Order(const std::string& customer, const OrderStatus& status, const std::string& reg);
    void addItem(const std::shared_ptr<Product>& item);
    void removeItem(const std::shared_ptr<Product>& item);
    double getTotalWeight() const;
    int getTotalPrice() const;
    void setStatus(const OrderStatus& newStatus);
    const std::vector<std::shared_ptr<Product>>& getItems()const;
    void applyDiscount(const std::shared_ptr<Discount>& discount);
    void setDelivery(const std::shared_ptr<Delivery>& newDelivery);
    void addDiscountAmount(int amount);
    void setFreeDelivery();
    const std::string& getRegion() const;
    void setRegion(const std::string& newRegion);
    int getId() const;
    const std::string& getCustomer() const;
    OrderStatus getStatus() const;
    const std::shared_ptr<Delivery>& getDelivery() const;

    Order(const Order&) = delete;
    Order& operator=(const Order&) = delete;
    Order(Order&&) = delete;
    Order& operator=(Order&&) = delete;
};

Order& operator+(Order& order, const Discount& discount);
Order& operator<<(Delivery& delivery, Order& order);
std::ostream& operator<<(std::ostream& os, const Order& order);