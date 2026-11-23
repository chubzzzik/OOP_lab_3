#include"ShowStatisticsHandler.h"
#include"ShowStatisticsCommand.h"
#include"ShopFacade.h"

#include<memory>
#include<stdexcept>
#include<string>
#include<sstream>

ShowStatisticsHandler::ShowStatisticsHandler(std::shared_ptr<ShopFacade> facade):facade_(facade){
    if(facade == nullptr){
        throw std::invalid_argument("This Facade does not exist");
    }
}

bool ShowStatisticsHandler::handle(const std::string& input){
    std::istringstream iss (input);
    std::string action;
    std::string subject;
    iss >> action >> subject;
    if(action != "show" || subject != "statistics"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }
    auto cmd = std::make_shared<ShowStatisticsCommand>(facade_);
    facade_->executeCommand(cmd);
    return true;
}