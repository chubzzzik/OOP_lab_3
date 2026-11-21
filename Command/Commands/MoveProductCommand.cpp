#include"MoveProductCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>

MoveProductCommand::MoveProductCommand(std::shared_ptr<ShopFacade> facade, int productId,
        std::shared_ptr<Warehouse> targetWarehouse):
        Command(facade), productId_(productId), targetWarehouse_(targetWarehouse){
            if(targetWarehouse == nullptr){
                throw std::invalid_argument("This warehouse does not exist");
            }
        }

void MoveProductCommand::execute(){
    facade_->moveProduct(productId_, targetWarehouse_);
}
