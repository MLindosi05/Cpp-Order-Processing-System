#ifndef ORDERPROCESSING_H
#define ORDERPROCESSING_H
#include "InventoryManagement.h"

class OrderProcessing{
    public:
         void processOrder(InventoryManagement& inventory, int productId, int quantity);

};
#endif
