#pragma once

class ShopFacade{
    public:
    void addProduct();
    void changePrice();
    void changeQuantity();
    void moveProduct();
    void removeProduct();
    void listProducts();

    void createOrder();
    void cancelOrder();
    void confirmPayment();
    void shipOrder();
    void listOrders();
    void getStatistics();

    void executeCommand();
    void processInput();
};