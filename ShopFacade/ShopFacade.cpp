#include<ShopFacade.h>
#include"ProductFactory.h"
#include"Warehouse.h"
#include"ShopMediator.h"
#include"Command.h"
#include"CommandHistory.h"
#include"Handler.h"

#include<memory>
#include<string>
#include<vector>
#include<stdexcept>

ShopFacade::ShopFacade(std::shared_ptr<Warehouse> warehouse, std::shared_ptr<ShopMediator> mediator,
        std::shared_ptr<CommandHistory> history, std::shared_ptr<Handler> inputHandler):
        warehouse_(warehouse), mediator_(mediator), history_(history), inputHandler_(inputHandler){
            if(warehouse == nullptr){
                throw std::invalid_argument("This Warehouse does not exist");
            }
            if(mediator == nullptr){
                throw std::invalid_argument("This Mediator does not exist");
            }
            if(history == nullptr){
                throw std::invalid_argument("This Command history does not exist");
            }
            if(inputHandler == nullptr){
                throw std::invalid_argument("This Handler does not exist");
            }
        }

void ShopFacade::addProduct(const std::string& type, const std::string& name, int price, double weight,
    int quantity){
        ProductFactory factory;
        std::shared_ptr<Product> product = factory.createProduct(type, name, price, weight, quantity);
        int id = product->getId();
        warehouse_->addProduct(product);
        mediator_->onProductAdded(id);
}

void ShopFacade::changePrice(int productId, int newPrice){
    warehouse_->changePrice(productId, newPrice);
    mediator_->onProductChanged(productId);
}

void ShopFacade::changeQuantity(int productId, int amount){
    warehouse_->changeQuantity(productId, amount);
    mediator_->onProductChanged(productId);
}

void ShopFacade::moveProduct(int productId, std::shared_ptr<Warehouse> targetWarehouse){
    if(targetWarehouse == nullptr){
        throw std::invalid_argument("This Warehouse does not exist");
    }
    warehouse_->moveProduct(productId, *targetWarehouse);
}

void ShopFacade::removeProduct(int productId){
    mediator_->onProductRemoved(productId);
    warehouse_->removeProduct(productId);
}

void ShopFacade::listProducts(){
    warehouse_->listProducts();
}

int ShopFacade::createOrder(const std::string& customer, const std::vector<std::shared_ptr<Product>>& items,
    const std::shared_ptr<Delivery>& deliveryType, const std::string& region){
        return mediator_->createOrder(customer, items, deliveryType, region);
}

void ShopFacade::cancelOrder(int orderId){
    mediator_->cancelOrder(orderId);
}

void ShopFacade::confirmPayment(int orderId){
    mediator_->confirmPayment(orderId);
}

void ShopFacade::shipOrder(int orderId){
    mediator_->shipOrder(orderId);
}

void ShopFacade::listOrders(){
    mediator_->listOrders();
}

void ShopFacade::getStatistics(){
    mediator_->getStatistics();
}

void ShopFacade::executeCommand(std::shared_ptr<Command> command){
    if(command == nullptr){
        throw std::invalid_argument("This Command does not exist");
    }
    command->execute();
    history_->push(command);
}

void ShopFacade::processInput(const std::string& input){
    inputHandler_->handle(input);
}
