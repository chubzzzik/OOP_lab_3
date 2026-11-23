#include"Handler.h"

#include<memory>
#include<stdexcept>

std::shared_ptr<Handler> Handler::setNext(std::shared_ptr<Handler> next){
    if(next == nullptr){
        throw std::invalid_argument("This Handler does not exist");
    }
    next_ = next;
    return next_;
}