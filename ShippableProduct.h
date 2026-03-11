#ifndef SHIPPABLEPRODUCT_H
#define SHIPPABLEPRODUCT_H
#include "Product.h"

class ShippableProduct : public Product {
    private:
        double shippingFee;

    public:
        ShippableProduct(int id, string name, double price, int quantity, double shippingFee = 50.0);
        double calculateFinalPrice() override;
        void display() override;

};

#endif
