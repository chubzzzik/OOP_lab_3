#include"OrderManager.h"
#include"OrderEvent.h"
#include"OrderStatus.h"
#include"Order.h"

#include<iostream>
#include<algorithm>
#include<stdexcept>
#include<memory>
#include<string>

int OrderManager::createOrder(const std::string& customer, const std::string& region){
    auto order = std::make_shared<Order>(customer, OrderStatus::Pending, region);
    order->subscribe(this);
    orders_.emplace(order->getId(),order);
    
    auto it = std::find(customers_.begin(),customers_.end(), customer);
    if(it == customers_.end()){
        customers_.push_back(customer);
    }
    activeOrders_++;
    return order->getId();
}

void OrderManager::cancelOrder(int orderId){
    auto it = orders_.find(orderId);
    if(it == orders_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(it->second->getStatus() == OrderStatus::Pending || it->second->getStatus() == OrderStatus::Paid){
        it->second->setStatus(OrderStatus::Cancelled);
        return;
    }
    throw std::logic_error("You cannot cancel this order");
}

void OrderManager::confirmPayment(int orderId){
    auto it = orders_.find(orderId);
    if(it == orders_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(it->second->getStatus() == OrderStatus::Pending){
        it->second->setStatus(OrderStatus::Paid);
        return;
    }
    throw std::logic_error("Order already paid or cancelled");
}

void OrderManager::shipOrder(int orderId){
    auto it = orders_.find(orderId);
    if(it == orders_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(it->second->getStatus() == OrderStatus::Paid){
        it->second->setStatus(OrderStatus::Shipped);
        return;
    }
    throw std::logic_error("Order already shipped or cancelled");
}

void OrderManager::deliverOrder(int orderId){
    auto it = orders_.find(orderId);
    if(it == orders_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(it->second->getStatus() == OrderStatus::Shipped){
        it->second->setStatus(OrderStatus::Delivered);
        return;
    }
    throw std::logic_error("Order already delivered or cancelled");
}

void OrderManager::getStatistics() const{
    std::cout << "Количество активных заказов: " << activeOrders_
    << "\nОборот: " << turnover_ << "\nКоличество клиентов: " << customers_.size()
    << "\n Общее кол-во заказов: " << orders_.size() << "\n";
}

void OrderManager::onOrderEvent(const OrderEvent& event){
    if(event.getNewStatus() == OrderStatus::Paid){
        for(const auto& t : orders_){
            if(t.second->getId() == event.getId()){
                turnover_ += t.second->getTotalPrice();
                std::cout << "[OrderManager] INFO: заказ №" << event.getId() << " оплачен, оборот = " << turnover_ << "\n"; 
                return; 
            }
        }
        std::cout << "[OrderManager] WARNING: событие Paid от неизвестного заказа №" << event.getId() << ", оборот не обновлён" << "\n";
    }

    else if(event.getNewStatus() == OrderStatus::Cancelled){
        if(activeOrders_ == 0){
            std::cout << "[OrderManager] WARNING: отмена при нулевом счётчике активных заказов — рассинхрон состояния" << "\n";
            return;
        }
        activeOrders_--;
        std::cout << "[OrderManager] INFO: заказ отменён, активных заказов: "<< activeOrders_ <<  "\n";
    }

    else if(event.getNewStatus() == OrderStatus::Delivered){
        if(activeOrders_ == 0){
            std::cout << "[OrderManager] WARNING: доставка при нулевом счётчике активных заказов — рассинхрон состояния" << "\n";
            return;
        }
        activeOrders_--;
        std::cout << "[OrderManager] INFO: заказ доставлен, активных заказов: "<< activeOrders_ <<  "\n";
    }
}