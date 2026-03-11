#ifndef BULKPRODUCT_H_INCLUDED
#define BULKPRODUCT_H_INCLUDED
#include "Product.h"

class BulkProduct : public Product{
    private:
        int orderQuantity;

    public:
        BulkProduct(int id, string name, double price, int quantity, int orderQuantity);
        double calculateFinalPrice() override;
        void display() override;

};

#endif
