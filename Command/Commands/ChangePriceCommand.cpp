#include"ChangePriceCommand.h"
#include"ShopFacade.h"

#include<memory>

ChangePriceCommand::ChangePriceCommand(std::shared_ptr<ShopFacade> facade, int productId, int newPrice):
        Command(facade), productId_(productId), newPrice_(newPrice){
}

void ChangePriceCommand::execute(){
    facade_->changePrice(productId_, newPrice_);
}
