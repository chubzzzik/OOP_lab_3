#include"ChangeQuantityHandler.h"
#include"ChangeQuantityCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

ChangeQuantityHandler::ChangeQuantityHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool ChangeQuantityHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "change" || subject != "quantity"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    int id;
    int delta;
    if(!(iss >> id >> delta)){
        throw std::invalid_argument("Wrong command arguments format"); 
    }
    auto cmd = std::make_shared<ChangeQuantityCommand>(facade_, id, delta);
    facade_->executeCommand(cmd);
    return true;
}