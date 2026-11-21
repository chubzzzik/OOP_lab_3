#pragma once

#include<memory>
#include<vector>

class Command;

class CommandHistory{
    private:
    std::vector<std::shared_ptr<Command>> history_;

    public:
    void push(std::shared_ptr<Command> command);
    void undo();
    std::shared_ptr<Command> getLastCommand() const;
};