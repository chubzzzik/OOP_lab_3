#include"ShopMediator.h"

#include<memory>
#include<stdexcept>

ShopMediator::ShopMediator(std::shared_ptr<Warehouse> w, std::shared_ptr<OrderManager> o,
    std::shared_ptr<DeliveryService> d,std::shared_ptr<PaymentSystem> p):warehouse_(w),
    orderManager_(o), deliveryService_(d), paymentSystem_(p){
        if(w == nullptr){
            throw std::invalid_argument("This warehouse does not exist");
        }
        else if(o == nullptr){
            throw std::invalid_argument("This order manager does not exist");
        }
        else if(d == nullptr){
            throw std::invalid_argument("This delivery service does not exist");
        }
        else if(p == nullptr){
            throw std::invalid_argument("This payment system does not exist");
        }
    }