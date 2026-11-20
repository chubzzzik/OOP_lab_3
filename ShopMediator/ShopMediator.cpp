#include"ShopMediator.h"
#include"Warehouse.h"
#include"OrderManager.h"
#include"DeliveryService.h"
#include"PaymentSystem.h"

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

void ShopMediator::notifyProductAdded(int id){
    warehouse_->findById(id);
    std::cout << "Товар добавлен на склад\n";
}

void ShopMediator::notifyOrderCreated(int id){
    orderManager_->findById(id);
    std::cout << "Заказ создан\n";
}

void ShopMediator::notifyPaymentConfirmed(int id){
    auto order = orderManager_->findById(id);
    paymentSystem_->processPayment(*order);

    orderManager_->confirmPayment(id);
    std::cout << "Оплата подтверждена\n";
}

void ShopMediator::notifyOrderShipped(int id){
    auto order = orderManager_->findById(id);
    if(!(deliveryService_->isAvailable(*order))){
        throw std::logic_error("Delivery is not available");
    }
    orderManager_->shipOrder(id);
    std::cout << "Заказ отправлен\n";
}

void ShopMediator::notifyProductMoved(int id){
    warehouse_->findById(id);
    std::cout << "Продукт перемещен\n";
}
