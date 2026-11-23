#include"CancelOrderHandler.h"

#include<memory>
#include<stdexcept>

CancelOrderHandler::CancelOrderHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}
