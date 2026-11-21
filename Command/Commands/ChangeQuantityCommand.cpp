#include"ChangeQuantityCommand.h"
#include"ShopFacade.h"

#include<memory>

ChangeQuantityCommand::ChangeQuantityCommand(std::shared_ptr<ShopFacade> facade, int productId, int amount):
        Command(facade), productId_(productId), amount_(amount){
}

void ChangeQuantityCommand::execute(){
    facade_->changeQuantity(productId_, amount_);
}
