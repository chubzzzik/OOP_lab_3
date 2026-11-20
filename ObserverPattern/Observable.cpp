#include"Observable.h"
#include"Observer.h"

#include<algorithm>
#include<stdexcept>

void Observable::subscribe(Observer* observer){
    if(observer == nullptr){
        throw std::invalid_argument("This observer does not exist");
    }
    auto it = std::find(subs_.begin(), subs_.end(), observer);
    if(it == subs_.end()){
        subs_.push_back(observer);
    }
}

void Observable::unsubscribe(Observer* observer){
    auto it = std::find(subs_.begin(), subs_.end(), observer);
    if(it == subs_.end()){
        throw std::invalid_argument("Observable::unsubscribe: observer not found");
    }
    subs_.erase(it);
}

void Observable::notify(const OrderEvent& event){
    for(auto* sub : subs_){
        sub->onOrderEvent(event);
    }
}