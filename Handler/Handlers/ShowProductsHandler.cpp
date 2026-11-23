#include"ShowProductsHandler.h"
#include"ShowProductsCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

ShowProductsHandler::ShowProductsHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool ShowProductsHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "show" || subject != "products"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    auto cmd = std::make_shared<ShowProductsCommand>(facade_);
    facade_->executeCommand(cmd);
    return true;
}