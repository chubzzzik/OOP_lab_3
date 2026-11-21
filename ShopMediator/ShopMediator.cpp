#include"ShopMediator.h"
#include"Warehouse.h"
#include"OrderManager.h"
#include"DeliveryService.h"
#include"PaymentSystem.h"

#include<stdexcept>

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