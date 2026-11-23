#include"CancelOrderHandler.h"
#include"CancelOrderCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

CancelOrderHandler::CancelOrderHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool CancelOrderHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "cancel" || subject != "order"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    int id;
    if(!(iss >> id)){
        throw std::invalid_argument("Wrong command arguments format"); 
    }
    auto cmd = std::make_shared<CancelOrderCommand>(facade_, id);
    facade_->executeCommand(cmd);
    return true;
}