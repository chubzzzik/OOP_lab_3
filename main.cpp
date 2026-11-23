#include"Warehouse.h"
#include"OrderManager.h"
#include"DeliveryService.h"
#include"PaymentSystem.h"
#include"ShopMediator.h"
#include"CommandHistory.h"
#include"ShopFacade.h"
#include"AddProductHandler.h"
#include"ChangePriceHandler.h"
#include"ChangeQuantityHandler.h"
#include"RemoveProductHandler.h"
#include"MoveProductHandler.h"
#include"CreateOrderHandler.h"
#include"ShowProductsHandler.h"
#include"CancelOrderHandler.h"
#include"ConfirmPaymentHandler.h"
#include"ShipOrderHandler.h"
#include"ShowOrdersHandler.h"
#include"ShowStatisticsHandler.h"
#include"HelpHandler.h"

#include<cstdlib>
#include<initializer_list>
#include<iostream>
#include<memory>
#include<stdexcept>
#include<string>

void runScenario(const std::shared_ptr<ShopFacade>& facade, const std::string& title,
        std::initializer_list<const char*> commands){
    std::cout << "\n=== " << title << " ===\n";
    for(const char* command : commands){
        std::cout << "> " << command << "\n";
        try{
            facade->processInput(command);
        }
        catch(const std::exception& exception){
            std::cout << "Ошибка: " << exception.what() << "\n";
        }
    }
}

int main(){
    auto warehouse = std::make_shared<Warehouse>();
    auto orderManager = std::make_shared<OrderManager>();
    auto deliveryService = std::make_shared<DeliveryService>(67, 67, 67);
    auto paymentSystem = std::make_shared<PaymentSystem>(1000000);
    auto shopMediator = std::make_shared<ShopMediator>
        (warehouse, orderManager, deliveryService, paymentSystem);

    auto commandHistory = std::make_shared<CommandHistory>();
    auto shopFacade = std::make_shared<ShopFacade>(warehouse, shopMediator, commandHistory);

    auto addProductHandler = std::make_shared<AddProductHandler>(shopFacade);
    auto changePriceHandler = std::make_shared<ChangePriceHandler>(shopFacade);
    auto changeQuantityHandler = std::make_shared<ChangeQuantityHandler>(shopFacade);
    auto removeProductHandler = std::make_shared<RemoveProductHandler>(shopFacade);
    auto moveProductHandler = std::make_shared<MoveProductHandler>(shopFacade);
    auto createOrderHandler = std::make_shared<CreateOrderHandler>(shopFacade);
    auto showProductsHandler = std::make_shared<ShowProductsHandler>(shopFacade);
    auto cancelOrderHandler = std::make_shared<CancelOrderHandler>(shopFacade);
    auto confirmPaymentHandler = std::make_shared<ConfirmPaymentHandler>(shopFacade);
    auto shipOrderHandler = std::make_shared<ShipOrderHandler>(shopFacade);
    auto showOrdersHandler = std::make_shared<ShowOrdersHandler>(shopFacade);
    auto showStatisticsHandler = std::make_shared<ShowStatisticsHandler>(shopFacade);
    auto helpHandler = std::make_shared<HelpHandler>();

    addProductHandler->setNext(changePriceHandler)
        ->setNext(changeQuantityHandler)
        ->setNext(removeProductHandler)
        ->setNext(moveProductHandler)
        ->setNext(createOrderHandler)
        ->setNext(showProductsHandler)
        ->setNext(cancelOrderHandler)
        ->setNext(confirmPaymentHandler)
        ->setNext(shipOrderHandler)
        ->setNext(showOrdersHandler)
        ->setNext(showStatisticsHandler)
        ->setNext(helpHandler);

    shopFacade->setInputHandler(addProductHandler);

    runScenario(shopFacade, "Сценарий 1: добавление товаров и просмотр склада", {
        "add product Smartphone \"iPhone 15\" 100000 0.2 5",
        "add product Laptop \"MacBook Pro\" 200000 2.0 3",
        "show products"
    });

    runScenario(shopFacade, "Сценарий 2: создание заказа с доставкой и оплатой", {
        "create order \"Иван\" 1,2 courier",
        "confirm payment 1",
        "show orders"
    });

    runScenario(shopFacade, "Сценарий 3: изменение цены и остатка товара", {
        "change price 1 90000",
        "change quantity 1 -2",
        "show products"
    });

    runScenario(shopFacade, "Сценарий 4: отмена и отправка заказа", {
        "create order \"Пётр\" 2 pickup",
        "cancel order 2",
        "ship order 1",
        "show statistics"
    });

    runScenario(shopFacade, "Сценарий 5: координация через посредника", {
        "add product Tablet \"iPad\" 80000 0.5 2",
        "create order \"Анна\" 3 post",
        "show products",
        "show statistics"
    });

    std::cout << std::flush;
    std::cout << "Нажмите Enter, чтобы продолжить...";
    std::cin.get();
    std::system("cls");
    std::cout << "Интерактивный режим. Введите help для справки или exit для выхода.\n";
    std::string input;
    while(true){
        std::cout << "> ";
        if(!std::getline(std::cin, input) || input == "exit"){
            break;
        }
        if(input.empty()){
            continue;
        }
        std::system("cls");
        try{
            shopFacade->processInput(input);
        }
        catch(const std::exception& exception){
            std::cout << "Ошибка: " << exception.what() << "\n";
        }
        std::cout << "\nВведите help для справки или exit для выхода.\n";
    }

    return 0;
}
