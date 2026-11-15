#include"OrderManager.h"
#include"Order.h"

#include<unordered_map>
#include<unordered_set>
#include<memory>
#include<stdexcept>
#include<iostream>

int OrderManager::createOrder(const std::string& customer,
    const std::vector<std::shared_ptr<Product>>& items, const std::string& deliveryType){
        auto order = std::make_shared<Order>(customer, OrderStatus::Pending, deliveryType);
        for (const auto& item : items) {
            order->addItem(item);
        }
        orders_.emplace(order->getId(),order);
        return order->getId();
    }

void OrderManager::cancelOrder(int id){
    auto it = orders_.find(id);
    if(it == orders_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(it->second->getStatus() == OrderStatus::Delivered ||
        it->second->getStatus() == OrderStatus::Shipped){
        throw std::logic_error("This order is already delivered");
    }
    it->second->setStatus(OrderStatus::Cancelled);
}

void OrderManager::confirmPayment(int id){
    auto it = orders_.find(id);
    if(it == orders_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(it->second->getStatus() == OrderStatus::Pending){
        it->second->setStatus(OrderStatus::Paid);
    }
    else{
        throw std::logic_error("This order is already paid or cancelled");
    }
    
}

void OrderManager::shipOrder(int id){
    auto it = orders_.find(id);
    if(it == orders_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(it->second->getStatus() == OrderStatus::Paid){
        it->second->setStatus(OrderStatus::Shipped);
    }
    else{
        throw std::logic_error("This order is not paid or already cancelled");
    }
}

void OrderManager::getStatistics() const{
    size_t ordersCount = orders_.size();
    int turnover = 0;
    for(auto& it : orders_){
        if(it.second->getStatus() == OrderStatus::Paid ||
        it.second->getStatus() == OrderStatus::Shipped ||
        it.second->getStatus() == OrderStatus::Delivered ){
            turnover += it.second->getTotalPrice();
        }
    }
    std::unordered_set<std::string> unique_customers;
    for(auto& it : orders_){
        unique_customers.insert(it.second->getCustomer());
    }
    size_t customersCount = unique_customers.size();
    
    std::cout << "Кол-во заказов: " << ordersCount << "\nОборот: " << turnover
    << "\nКол-во клиентов: " << customersCount << "\n";
}