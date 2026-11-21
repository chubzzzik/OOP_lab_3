#include"Warehouse.h"
#include"Product.h"
#include"Attributes.h"

#include<memory>
#include<unordered_map>
#include<stdexcept>

void Warehouse::addProduct(std::shared_ptr<Product> product){
    if(product == nullptr){
        throw std::invalid_argument("This product does not exist");
    }
    auto t = product->getId();
    for(auto& it : products_){
        if(it.first == t){ throw std::invalid_argument("This product is already in Warehouse");}
    }
    products_.emplace(product->getId(), product);
}

void Warehouse::removeProduct(int id){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("Product with this id does not exist");
    }
    products_.erase(it);
}

std::shared_ptr<Product> Warehouse::findById(int id){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("Product with this id does not exist");
    }
    return it->second;
}

void Warehouse::changePrice(int id, int newPrice){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("Product with this id does not exist");
    }
    it->second->changePrice(newPrice);
}

void Warehouse::changeQuantity(int id, int delta){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("Product with this id does not exist");
    }
    it->second->changeQuantity(delta);
}

void Warehouse::moveProduct(int id, Warehouse& other){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("Product with this id does not exist");
    }
    if(this == &other){
        throw std::invalid_argument("You cannot move product to the same Warehouse");
    }
    other.addProduct(it->second);
    products_.erase(it);
}