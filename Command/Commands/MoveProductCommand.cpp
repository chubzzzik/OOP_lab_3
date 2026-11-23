#include"MoveProductCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>

MoveProductCommand::MoveProductCommand(std::shared_ptr<ShopFacade> facade, int productId,
    int targetWarehouseId):Command(facade), productId_(productId), targetWarehouseId_(targetWarehouseId){}

void MoveProductCommand::execute(){
    facade_->moveProduct(productId_, targetWarehouseId_);
}
