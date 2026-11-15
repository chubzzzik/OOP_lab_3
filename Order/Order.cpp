#include"Order.h"

#include<string>
#include<vector>
#include<memory>
#include<stdexcept>

int Order::nextId_ = 1;

Order::Order(const std::string& customer, OrderStatus status, const std::string& delivery):
    id_(nextId_),customer_(customer), status_(status), deliveryType_(delivery), totalPrice_(0){
        nextId_++;

    }

int Order::getId() const{
    return id_;
}

const std::string& Order::getCustomer() const{
    return customer_;
}

const std::vector<std::shared_ptr<Product>>& Order::getItems() const{
    return items_;
}

OrderStatus Order::getStatus() const{
    return status_;
}

const std::string& Order::getDeliveryType() const{
    return deliveryType_;
}

int Order::getTotalPrice() const{
    return totalPrice_;
}

void Order::addItem(const std::shared_ptr<Product>& item){
    if(item == nullptr){
        throw std::invalid_argument("This item does not exist");
    }
    items_.push_back(item);
    totalPrice_ += item->getPrice().getValue();
}

void Order::setStatus(const OrderStatus& newStatus){
    if(newStatus == status_){ return; }
    status_ = newStatus;
}
