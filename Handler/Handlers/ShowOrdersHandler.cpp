#include"ShowOrdersHandler.h"

#include<memory>
#include<stdexcept>

ShowOrdersHandler::ShowOrdersHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}
