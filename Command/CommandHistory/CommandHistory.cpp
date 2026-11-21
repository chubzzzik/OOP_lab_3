#include"CommandHistory.h"

#include<memory>
#include<vector>
#include<stdexcept>

void CommandHistory::push(std::shared_ptr<Command> command){
    if(command == nullptr){
        throw std::invalid_argument("This command does not exist");
    }
    history_.push_back(command);
}

void CommandHistory::undo(){
    if(history_.size() == 0){
        throw std::logic_error("Command history is empty");
    }
    history_.pop_back();
}

std::shared_ptr<Command> CommandHistory::getLastCommand() const{
    if(history_.size() == 0){
        throw std::logic_error("Command history is empty");
    }
    return history_.back();
}