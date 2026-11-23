#include"MoveProductHandler.h"
#include"MoveProductCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

MoveProductHandler::MoveProductHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool MoveProductHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "move" || subject != "product"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    int productId;
    std::string to;
    int warehouseId;
    if(!(iss >> productId >> to >>  warehouseId) || to != "to"){
        throw std::invalid_argument("Wrong command arguments format"); 
    }
    auto cmd = std::make_shared<MoveProductCommand>(facade_, productId, warehouseId);
    facade_->executeCommand(cmd);
    return true;
}