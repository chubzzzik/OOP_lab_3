#include"Command.h"

#include<memory>
#include<stdexcept>

Command::Command(std::shared_ptr<ShopMediator> med):mediator_(med){
    if(med == nullptr){
        throw std::invalid_argument("This mediator does not exist");
    }
}