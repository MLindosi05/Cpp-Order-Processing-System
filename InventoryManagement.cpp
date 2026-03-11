#include "InventoryManagement.h"
#include <iostream>
using namespace std;

void InventoryManagement::addProduct(shared_ptr<Product> product) {
   products[product->getId()] = product;
}

void InventoryManagement::removeProduct(int id) {
   products.erase(id);
}

shared_ptr<Product> InventoryManagement::searchProduct(int id) {
   if(products.find(id) != products.end()) {
      return products[id];
   }
   return nullptr;
}

void InventoryManagement::displayAll() {
   for(auto& product : products) {
       product.second->display();
       cout << "----------------------" << endl;
   }
}

bool InventoryManagement::reduceStock(int id, int quantity){
    lock_guard<mutex> lock(inventoryMutex);

    auto product = searchProduct(id);

    if(product == nullptr){
       return false;
    }

    if(product->getQuantity() >= quantity){
       product->reduceQuantity(quantity);
       return true;
    }

    return false;
}
