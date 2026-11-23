#include"ShowOrdersHandler.h"
#include"ShowOrdersCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

ShowOrdersHandler::ShowOrdersHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool ShowOrdersHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "show" || subject != "orders"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    auto cmd = std::make_shared<ShowOrdersCommand>(facade_);
    facade_->executeCommand(cmd);
    return true;
}