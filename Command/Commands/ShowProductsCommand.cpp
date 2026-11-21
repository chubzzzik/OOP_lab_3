#include"ShowProductsCommand.h"
#include"ShopFacade.h"

#include<memory>

ShowProductsCommand::ShowProductsCommand(std::shared_ptr<ShopFacade> facade):
        Command(facade){
}

void ShowProductsCommand::execute(){
    facade_->listProducts();
}
