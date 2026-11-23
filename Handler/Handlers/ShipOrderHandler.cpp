#include"ShipOrderHandler.h"

#include<memory>
#include<stdexcept>

ShipOrderHandler::ShipOrderHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}
