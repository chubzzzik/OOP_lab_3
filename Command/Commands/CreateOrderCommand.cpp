#include"CreateOrderCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<string>
#include<vector>

CreateOrderCommand::CreateOrderCommand(std::shared_ptr<ShopFacade> facade, const std::string& customer,
        const std::vector<std::shared_ptr<Product>>& items,
        const std::shared_ptr<Delivery>& deliveryType, const std::string& region):
        Command(facade), customer_(customer), items_(items), deliveryType_(deliveryType), region_(region){
}

void CreateOrderCommand::execute(){
    facade_->createOrder(customer_, items_, deliveryType_, region_);
}
