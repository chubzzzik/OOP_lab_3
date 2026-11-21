#pragma once

#include"Product.h"
 
#include<memory>
#include<unordered_map>

class Warehouse{
    private:
    std::unordered_map<int, std::shared_ptr<Product>> products_;

    public:
    ~Warehouse() = default;
    void addProduct(std::shared_ptr<Product> product);
    void removeProduct(int id);
    std::shared_ptr<Product> findById(int id);
    void changePrice(int id, int newPrice);
    void changeQuantity(int id, int delta);
    void moveProduct(int id, Warehouse& other);
};