#include"ChangePriceHandler.h"
#include"ChangePriceCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

ChangePriceHandler::ChangePriceHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool ChangePriceHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "change" || subject != "price"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    int id;
    int price;
    if(!(iss >> id >> price)){
        throw std::invalid_argument("Wrong command arguments format"); 
    }
    auto cmd = std::make_shared<ChangePriceCommand>(facade_, id, price);
    facade_->executeCommand(cmd);
    return true;
}