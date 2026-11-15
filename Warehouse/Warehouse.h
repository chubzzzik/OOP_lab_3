#pragma once

#include"Product.h"

#include<memory>
#include<unordered_map>

class Warehouse{
    private:
    std::unordered_map<int, std::shared_ptr<Product>> products_;

    public:
    void addProduct(std::shared_ptr<Product> product);
    void removeProduct(int id);
    std::shared_ptr<Product> findById(int id);
    void changePrice(int id, const Price& newPrice);
    void changeQuantity(int id, int delta);
    void moveProduct(int productId, Warehouse& targetWarehouse);

};