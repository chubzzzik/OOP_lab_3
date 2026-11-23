#include"AddProductCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<string>

AddProductCommand::AddProductCommand(std::shared_ptr<ShopFacade> facade, const std::string& type,
        const std::string& name, int price, double weight, int quantity):
        Command(facade), type_(type), name_(name), price_(price), weight_(weight), quantity_(quantity){}

void AddProductCommand::execute(){
    facade_->addProduct(type_, name_, price_, weight_, quantity_);
}
