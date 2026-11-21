#include"Command.h"

#include<memory>
#include<stdexcept>

Command::Command(std::shared_ptr<ShopFacade> facade){
    if(facade == nullptr){
        throw std::invalid_argument("This facade does not exist");
    }
    facade_ = facade;
}