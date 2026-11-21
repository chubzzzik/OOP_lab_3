#include"RemoveProductCommand.h"
#include"ShopFacade.h"

#include<memory>

RemoveProductCommand::RemoveProductCommand(std::shared_ptr<ShopFacade> facade, int productId):
        Command(facade), productId_(productId){
}

void RemoveProductCommand::execute(){
    facade_->removeProduct(productId_);
}
