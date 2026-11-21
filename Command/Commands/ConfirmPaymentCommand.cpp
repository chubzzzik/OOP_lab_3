#include"ConfirmPaymentCommand.h"
#include"ShopFacade.h"

#include<memory>

ConfirmPaymentCommand::ConfirmPaymentCommand(std::shared_ptr<ShopFacade> facade, int orderId):
        Command(facade), orderId_(orderId){
}

void ConfirmPaymentCommand::execute(){
    facade_->confirmPayment(orderId_);
}
