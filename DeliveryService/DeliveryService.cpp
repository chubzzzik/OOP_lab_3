#include"DeliveryService.h"

#include<stdexcept>
#include<string>
#include<iostream>

DeliveryService::DeliveryService(int couriers, int points, int offices):couriers_(couriers),
    pickupPoints_(points), postOffices_(offices){
        if(couriers < 0){ throw std::invalid_argument("Couriers count cannot be negative");}
        if(points < 0){ throw std::invalid_argument("pickup points count cannot be negative");}
        if(offices < 0){ throw std::invalid_argument("post offices count cannot be negative");}
    }

bool DeliveryService::isAvailable(const std::string& deliveryType){
    if(deliveryType == "courier" || deliveryType == "pickup" || deliveryType == "post"){
        if(deliveryType == "courier" && couriers_ > 0 ){ return true; }
        if(deliveryType == "pickup" && pickupPoints_ > 0 ){ return true; }
        if(deliveryType == "post" && postOffices_ > 0 ){ return true; }
        return false;
    }
    throw std::invalid_argument("This delivery type does not exist");
}

int DeliveryService::calculateCost(const std::string& deliveryType){
    if(deliveryType == "courier"){
        return 500;
    }
    if(deliveryType == "pickup"){
        return 0;
    }
    if(deliveryType == "post"){
        return 1000;
    }
    throw std::invalid_argument("This delivery type does not exist");
}

void DeliveryService::scheduleDelivery(int orderId, const std::string& deliveryType){
    if(isAvailable(deliveryType) == false){
        throw std::logic_error("This delivery type does not available");
    }
    if(deliveryType == "courier"){
        couriers_--;
        std::cout << "Заказ " << orderId << "Назначена доставка курьером\n";
    }
    else if(deliveryType == "pickup"){
        pickupPoints_--;
        std::cout << "Заказ " << orderId << "Назначен самовывоз\n";
    }
    else if(deliveryType == "post"){
        postOffices_--;
        std::cout << "Заказ " << orderId << "Назначена доставка почтой\n";
    }
}