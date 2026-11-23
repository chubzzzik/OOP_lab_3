#pragma once

#include<memory>
#include<string>

class Handler{
    protected:
    std::shared_ptr<Handler> next_;

    public:
    virtual ~Handler() = default;
    virtual bool handle(const std::string& input) = 0;
    std::shared_ptr<Handler> setNext(std::shared_ptr<Handler> next);

};