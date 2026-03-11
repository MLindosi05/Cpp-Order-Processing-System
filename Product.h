#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED
#include <string>
using namespace std;

class Product {
   protected:
           int id;
           string name;
           double price;
           int quantity;

   public:
        Product(int id, string name, double price, int quantity);
        virtual ~Product();

        int getId();
        int getQuantity();
        void reduceQuantity(int q);
        void increaseQuantity(int q);
        virtual double calculateFinalPrice();
        virtual void display();

};

#endif
