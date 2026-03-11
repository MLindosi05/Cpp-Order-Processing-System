#ifndef PERISHABLEPRODUCT_H_INCLUDED
#define PERISHABLEPRODUCT_H_INCLUDED
#include "Product.h"

class PerishableProduct : public Product{
    private:
        int daysBeforeExpire;

    public:
        PerishableProduct(int id, string name, double price, int quantity, int daysBeforeExpire);
        double calculateFinalPrice() override;
        void display() override;

};

#endif
