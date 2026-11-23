#include"AddProductHandler.h"
#include"AddProductCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

AddProductHandler::AddProductHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool AddProductHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string command;
    iss >> command;
    if(command != "addproduct"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    std::string type;
    std::string name;
    int price;
    double weight;
    int quantity;

    if(!(iss >> type >> name >> price >> weight >> quantity)){
        throw std::invalid_argument("Wrong command arguments format"); 
    }
    auto cmd = std::make_shared<AddProductCommand>(facade_, type, name, price, weight, quantity);
    facade_->executeCommand(cmd);
    return true;
}