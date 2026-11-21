#include"ShipOrderCommand.h"
#include"ShopFacade.h"

#include<memory>

ShipOrderCommand::ShipOrderCommand(std::shared_ptr<ShopFacade> facade, int orderId):
        Command(facade), orderId_(orderId){
}

void ShipOrderCommand::execute(){
    facade_->shipOrder(orderId_);
}
