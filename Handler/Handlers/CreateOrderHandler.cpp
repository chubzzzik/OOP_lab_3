#include"CreateOrderHandler.h"
#include"CreateOrderCommand.h"
#include"ShopFacade.h"
#include"CourierDelivery.h"
#include"PostDelivery.h"
#include"PickupDelivery.h"
#include<DeliveryProxy.h>

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>
#include<vector>

CreateOrderHandler::CreateOrderHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool CreateOrderHandler::handle(const std::string& input){
    std::vector<std::shared_ptr<Product>> items;
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "create" || subject != "order"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    std::string customer;
    std::string deliveryType;
    std::string region;
    if(!(iss >> customer >> deliveryType >> region)){
        throw std::invalid_argument("Wrong command arguments format"); 
    }

    std::vector<int> productIds;
    int id;
    while(iss >> id){
        productIds.push_back(id);
    }

    if(productIds.size() == 0){
        throw std::logic_error("There are no any id");
    }
    for(auto& t : productIds){
        items.push_back(facade_->getProductById(t));
    }
    
    std::shared_ptr<Delivery> delivery;
    
    if(deliveryType == "courier"){
        delivery = std::make_shared<CourierDelivery>();
    }
    else if(deliveryType == "post"){
        delivery = std::make_shared<PostDelivery>();
    }
    else if(deliveryType == "pickup"){
        delivery = std::make_shared<PickupDelivery>();
    }
    else{
        throw std::invalid_argument("Unknown delivery type");
    }

    auto deliveryProxy = std::make_shared<DeliveryProxy>(delivery,region);

    auto cmd = std::make_shared<CreateOrderCommand>(facade_, customer, items, deliveryProxy, region);
    facade_->executeCommand(cmd);
    return true;
}