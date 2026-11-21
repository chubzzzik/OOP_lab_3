#include"ShowOrdersCommand.h"
#include"ShopFacade.h"

#include<memory>

ShowOrdersCommand::ShowOrdersCommand(std::shared_ptr<ShopFacade> facade):
        Command(facade){
}

void ShowOrdersCommand::execute(){
    facade_->listOrders();
}
