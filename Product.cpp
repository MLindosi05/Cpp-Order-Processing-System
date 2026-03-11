#include "Product.h"
#include <iostream>

Product::Product(int new_id,string new_name,double new_price,int new_quantity){
    id = new_id;
    name = new_name;
    price = new_price;
    quantity = new_quantity;

}

Product::~Product(){}

int Product::getId(){
    return id;
}

int Product::getQuantity(){
    return quantity;
}

void Product::reduceQuantity(int q){
     quantity -= q;
}

void Product::increaseQuantity(int q){
     quantity += q;
}

double Product::calculateFinalPrice(){
     return price;
}

void Product::display(){
     cout<< "ID: " << id << " Name: "<< name << " Price: "<< price << " Qty: " << quantity << endl;
}
