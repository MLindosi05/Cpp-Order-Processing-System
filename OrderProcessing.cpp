#include "OrderProcessing.h"
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void OrderProcessing::processOrder(InventoryManagement& inventory, int productId, int quantity){
    cout << " Thread " << this_thread::get_id() << " processing order for product " << productId << endl;
    this_thread::sleep_for(chrono::milliseconds(500));

    bool success = inventory.reduceStock(productId, quantity);

    if(success){
       cout << "Order successful\n";
    }
    else{
       cout << "Order failed\n";
    }
}
