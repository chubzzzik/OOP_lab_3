#include"Attributes.h"
#include<stdexcept>




Price::Price(int val):value_(val){
    if(val < 0){
        throw std::invalid_argument("Price can't be negative"); 
    }
}
int Price::getValue() const{
     return value_; 
    }
void Price::setValue(int newVal){
    if(newVal < 0){
        throw std::invalid_argument("Price can't be negative");
    }
    value_ = newVal;
}


Quantity::Quantity(int val):value_(val){
    if(val < 0){
        throw std::invalid_argument("Quantity can't be negative");
    }
}
int Quantity::getValue() const{
    return value_;
}
void Quantity::change(int delta){
    if(value_ + delta < 0){
        throw std::invalid_argument("Quantity can't be negative");
    }
    value_ += delta;
}
