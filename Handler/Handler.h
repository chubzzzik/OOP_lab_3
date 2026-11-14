#pragma once

#include<memory>
#include<string>

class Handler{
    protected:
    std::shared_ptr<Handler> next_;
    
    public:
    virtual ~Handler()= default;
    virtual bool handle(const std::string& cmd) = 0;
};