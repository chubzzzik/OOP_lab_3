#include"CancelOrderCommand.h"
#include"ShopFacade.h"

#include<memory>

CancelOrderCommand::CancelOrderCommand(std::shared_ptr<ShopFacade> facade, int orderId):
        Command(facade), orderId_(orderId){
}

void CancelOrderCommand::execute(){
    facade_->cancelOrder(orderId_);
}
