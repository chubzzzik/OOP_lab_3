#pragma once

class ShopFacade{
    public:
    int addProduct(type, name, price, quantity, weight, warehouseId);
    void changePrice(productId, newPrice);
    void changeQuantity(productId, int delta);
    void moveProduct(productId, newWarehouseId);
    void removeProduct(productId);
    int createOrder(customer, items, deliveryType);
    void cancelOrder(orderId);
    void confirmPayment(orderId);
    void shipOrder(orderId);
    void getStatistics() const;
    void listProducts() const;
    void listOrders() const;
};