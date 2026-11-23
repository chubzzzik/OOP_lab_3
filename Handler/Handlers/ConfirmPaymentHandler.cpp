#include"ConfirmPaymentHandler.h"

#include<memory>
#include<stdexcept>

ConfirmPaymentHandler::ConfirmPaymentHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}
