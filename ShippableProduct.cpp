#include "ShippableProduct.h"
#include <iostream>
using namespace std;

ShippableProduct::ShippableProduct(int id, string name, double price, int quantity, double shipping) : Product(id, name, price, quantity){
      shippingFee = shipping;
}

double ShippableProduct::calculateFinalPrice(){
    double totalPrice = price * quantity;
    if(totalPrice < 600){
       totalPrice += shippingFee;
    }
    return totalPrice;
}

void ShippableProduct::display() {
    cout << "[Shippable Product]: ";
    Product::display();
    cout << "Quantity: " << quantity << endl;
    cout << "Final Price (with shipping if needed): " << calculateFinalPrice() << endl;
}
