#include"ConfirmPaymentHandler.h"
#include"ConfirmPaymentCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

ConfirmPaymentHandler::ConfirmPaymentHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool ConfirmPaymentHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "confirm" || subject != "payment"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    int id;
    if(!(iss >> id)){
        throw std::invalid_argument("Wrong command arguments format"); 
    }
    auto cmd = std::make_shared<ConfirmPaymentCommand>(facade_, id);
    facade_->executeCommand(cmd);
    return true;
}