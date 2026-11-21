#include"ShopMediator.h"
#include"Warehouse.h"
#include"OrderManager.h"
#include"DeliveryService.h"
#include"PaymentSystem.h"
#include"OrderStatus.h"

#include<stdexcept>
#include<iostream>

ShopMediator::ShopMediator(std::shared_ptr<Warehouse> w, std::shared_ptr<OrderManager> o,
        std::shared_ptr<DeliveryService> d, std::shared_ptr<PaymentSystem> p):
        warehouse_(w), orderManager_(o), deliveryService_(d), paymentSystem_(p){
            if(w == nullptr){
                throw std::invalid_argument("This Warehouse does not exist");
            }
            if(o == nullptr){
                throw std::invalid_argument("This Order manager does not exist");
            }
            if(d == nullptr){
                throw std::invalid_argument("This Delivery service does not exist");
            }
            if(p == nullptr){
                throw std::invalid_argument("This Payment system does not exist");
            }
        }

int ShopMediator::createOrder(const std::string& customer,
        const std::vector<std::shared_ptr<Product>>& items,
        const std::shared_ptr<Delivery>& deliveryType, const std::string& region){
            std::vector<std::shared_ptr<Product>> orderList;
            for(auto t : items){
                if(t == nullptr){
                    throw std::invalid_argument("This product does not exist");
                }
                int currId = t->getId();
                orderList.push_back(warehouse_->findById(currId));
                warehouse_->changeQuantity(currId, -1);
            }

            int orderId = orderManager_->createOrder(customer, region);
            auto order = orderManager_->findById(orderId);
            for(auto t : orderList){
                order->addItem(t);
            }

            deliveryService_->scheduleDelivery(*order, deliveryType);

            return orderId;
        }

void ShopMediator::confirmPayment(int id){
    auto order = orderManager_->findById(id);
    paymentSystem_->processPayment(*order);
    orderManager_->confirmPayment(id);
}

void ShopMediator::shipOrder(int id){
    auto order = orderManager_->findById(id);
    if(deliveryService_->isAvailable(*order)){
        orderManager_->shipOrder(id);
        return;
    }
    throw std::logic_error("Delivery is not available");
}

void ShopMediator::cancelOrder(int id){
    auto order = orderManager_->findById(id);
    if(order->getStatus() == OrderStatus::Pending || order->getStatus() == OrderStatus::Paid){
        for(auto t : order->getItems()){
            warehouse_->changeQuantity(t->getId(), 1);
        }
        if(order->getStatus() == OrderStatus::Paid){
            paymentSystem_->refund(*order);
        }
        orderManager_->cancelOrder(id);
    }
    else{
        throw std::logic_error("This order cannot be cancelled");
    }
}

void ShopMediator::getStatistics() const{
    orderManager_->getStatistics();
}

void ShopMediator::onProductAdded(int id){
    warehouse_->findById(id);
    std::cout <<"Product added: <id: " << id << ">\n";
}

void ShopMediator::onProductChanged(int id){
    warehouse_->findById(id);
    std::cout <<"Product changed: <id: " << id << ">\n";
}

void ShopMediator::onProductRemoved(int id){
    warehouse_->findById(id);
    if(orderManager_->isProductReserved(id)){
        throw std::logic_error("Product is reserved");
    }
    std::cout <<"Product removed: <id: " << id << ">\n";
}