#include"CreateOrderHandler.h"
#include"CreateOrderCommand.h"
#include"ShopFacade.h"
#include"CourierDelivery.h"
#include"PostDelivery.h"
#include"PickupDelivery.h"
#include"DeliveryProxy.h"

#include<iomanip>
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
    std::istringstream iss(input);
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
    std::string productIdsInput;
    std::string deliveryType;
    if(!(iss >> std::quoted(customer) >> productIdsInput >> deliveryType)){
        throw std::invalid_argument("Wrong command arguments format");
    }

    std::vector<int> productIds;
    std::istringstream idsStream(productIdsInput);
    std::string idToken;
    while(std::getline(idsStream, idToken, ',')){
        if(idToken.empty()){
            throw std::invalid_argument("Wrong product ids format");
        }
        try{
            std::size_t parsedCharacters = 0;
            int id = std::stoi(idToken, &parsedCharacters);
            if(parsedCharacters != idToken.size()){
                throw std::invalid_argument("Wrong product ids format");
            }
            productIds.push_back(id);
        }
        catch(const std::exception&){
            throw std::invalid_argument("Wrong product ids format");
        }
    }
    if(productIds.empty()){
        throw std::invalid_argument("There are no product ids");
    }

    std::vector<std::shared_ptr<Product>> items;
    for(int id : productIds){
        items.push_back(facade_->getProductById(id));
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

    const std::string region = "RU";
    auto deliveryProxy = std::make_shared<DeliveryProxy>(delivery, region);
    auto cmd = std::make_shared<CreateOrderCommand>(
        facade_, customer, items, deliveryProxy, region
    );
    facade_->executeCommand(cmd);
    return true;
}
