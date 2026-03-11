#ifndef INVENTORYMANAGEMENT_H
#define INVENTORYMANAGEMENT_H
#include <map>
#include <memory>
#include <mutex>
#include "Product.h"
using namespace std;

class InventoryManagement {
    private:
        map<int, shared_ptr<Product>> products;
        mutex inventoryMutex;

    public:
        void addProduct(shared_ptr<Product> product);
        void removeProduct(int id);
        shared_ptr<Product> searchProduct(int id);
        void displayAll();
        bool reduceStock(int id, int quantity);

};
#endif
