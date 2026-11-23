#include"HelpHandler.h"

#include<iostream>
#include<sstream>
#include<string>

bool HelpHandler::handle(const std::string& input){
    std::istringstream iss(input);
    std::string command;
    iss >> command;

    if(command != "help"){
        if(next_ != nullptr){
            return next_->handle(input);
        }
        return false;
    }

    std::cout << "Доступные команды:\n"
        << "add product <type> \"<name>\" <price> <weight> <quantity>\n"
        << "change price <id> <newPrice>\n"
        << "change quantity <id> <amount>\n"
        << "remove product <id>\n"
        << "move product <id> to <warehouseId>\n"
        << "show products\n"
        << "create order \"<customer>\" <productIds> <deliveryType>\n"
        << "cancel order <id>\n"
        << "confirm payment <id>\n"
        << "ship order <id>\n"
        << "show orders\n"
        << "show statistics\n"
        << "help\n";
    return true;
}
