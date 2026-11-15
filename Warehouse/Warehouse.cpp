#include"Warehouse.h"

#include<unordered_map>
#include<memory>
#include<stdexcept>

void Warehouse::addProduct(std::shared_ptr<Product> product){
    if(product == nullptr){
        throw std::invalid_argument("This product does not exist");
    }
    auto it = products_.find(product->getId());
    if(it == products_.end()){
        products_.emplace(product->getId(),product);
        return;
    }
    throw std::invalid_argument("Product with this id already exist");
}

void Warehouse::removeProduct(int id){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    products_.erase(it);
}

std::shared_ptr<Product> Warehouse::findById(int id){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    return it->second;
}

void Warehouse::changePrice(int id, const Price& newPrice){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    it->second->changePrice(newPrice);
}

void Warehouse::changeQuantity(int id, int delta){
    auto it = products_.find(id);
    if(it == products_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    it->second->changeQuantity(delta);
}

void Warehouse::moveProduct(int productId, Warehouse& targetWarehouse){
    auto it = products_.find(productId);
    if(it == products_.end()){
        throw std::invalid_argument("This id does not exist");
    }
    if(this == &targetWarehouse){
        throw std::invalid_argument("You cannot move product to the same warehouse");
    }
    targetWarehouse.addProduct(this->findById(productId));
    this->removeProduct(productId);
}