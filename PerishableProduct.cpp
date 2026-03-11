#include "PerishableProduct.h"
#include <iostream>
using namespace std;

PerishableProduct::PerishableProduct(int id, string name, double price, int quantity, int days) : Product(id, name, price, quantity){
     daysBeforeExpire = days;
}

double PerishableProduct::calculateFinalPrice(){
    double totalPrice = price * quantity;
    if(daysBeforeExpire <= 5){
       totalPrice = totalPrice - (totalPrice * 0.2);
    }
    return totalPrice;
}

void PerishableProduct::display(){
    cout << "[Perishable Product]: ";
    Product::display();
    cout << "Days to Expire: " << daysBeforeExpire << endl;
    cout << "Final Price: " << calculateFinalPrice() << endl;
}
