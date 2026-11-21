#include"AddProductCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<string>

AddProductCommand::AddProductCommand(std::shared_ptr<ShopFacade> facade, const std::string& type,
        const std::string& name, int price, int quantity):
        Command(facade), type_(type), name_(name), price_(price), quantity_(quantity){
}

void AddProductCommand::execute(){
    facade_->addProduct(type_, name_, price_, quantity_);
}
