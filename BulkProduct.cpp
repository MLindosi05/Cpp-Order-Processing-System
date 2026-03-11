#include "BulkProduct.h"
#include <iostream>
using namespace std;

BulkProduct::BulkProduct(int id, string name, double price, int quantity, int orderQ) : Product(id, name, price, quantity){
     orderQuantity = orderQ;
}

double BulkProduct::calculateFinalPrice(){
    double totalPrice = price * orderQuantity;
    if(orderQuantity >= 10){
       totalPrice = totalPrice - (totalPrice * 0.2);
    }
    return totalPrice;
}

void BulkProduct::display(){
    cout << "[Bulk Product]: ";
    Product::display();
    cout << "Order Quantity: " << orderQuantity << endl;
    cout << "Final Price: " << calculateFinalPrice() << endl;
}
