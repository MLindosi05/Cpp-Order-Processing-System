#include <iostream>
#include <thread>
#include <vector>
#include "InventoryManagement.h"
#include "OrderProcessing.h"
#include "PerishableProduct.h"
#include "BulkProduct.h"
#include "ShippableProduct.h"
using namespace std;

int main(){

    InventoryManagement inventory;
    OrderProcessing orderSystem;

    int choice;

    while(true){

        cout << "\n===== Inventory System =====\n";
        cout << "1. Add Product\n";
        cout << "2. Display Products\n";
        cout << "3. Search Product\n";
        cout << "4. Remove Product\n";
        cout << "5. Place Order\n";
        cout << "6. Simulate Multiple Orders\n";
        cout << "7. Exit\n";
        cout << "Choose option: ";

        cin >> choice;

        if(choice == 1){
            int type, id, quantity;
            string name;
            double price;

            cout << "\nSelect Product Type:\n";
            cout << "1. Perishable\n";
            cout << "2. Bulk\n";
            cout << "3. Shippable\n";
            cin >> type;

            cout << "Enter ID: ";
            cin >> id;

            cout << "Enter Name: ";
            cin >> name;

            cout << "Enter Price: ";
            cin >> price;

            cout << "Enter Quantity: ";
            cin >> quantity;

            if(type == 1){
                int days;
                cout << "Days before expiry: ";
                cin >> days;

                shared_ptr<Product> p(new PerishableProduct(id,name,price,quantity,days));
                inventory.addProduct(p);
            }
            else if(type == 2){
                int orderQ;
                cout << "Bulk order quantity: ";
                cin >> orderQ;

                shared_ptr<Product> p(new BulkProduct(id,name,price,quantity,orderQ));
                inventory.addProduct(p);
            }
            else if(type == 3){
                double shipFee;
                cout << "Shipping fee: ";
                cin >> shipFee;

                shared_ptr<Product> p(new ShippableProduct(id,name,price,quantity,shipFee));
                inventory.addProduct(p);
            }

            cout << "Product added successfully.\n";
        }

        else if(choice == 2){
            inventory.displayAll();
        }

        else if(choice == 3){
            int id;

            cout << "Enter Product ID to search: ";
            cin >> id;

            shared_ptr<Product> product = inventory.searchProduct(id);

            if(product != nullptr){
               product->display();
            }
            else{
               cout << "Product not found.\n";
            }
        }

        else if(choice == 4){
            int id;

            cout << "Enter Product ID to remove: ";
            cin >> id;

            inventory.removeProduct(id);

            cout << "Product removed if it existed.\n";
        }

        else if(choice == 5){
            int id,qty;

            cout << "Enter Product ID: ";
            cin >> id;

            cout << "Enter Quantity: ";
            cin >> qty;

            thread t(&OrderProcessing::processOrder, &orderSystem, ref(inventory), id, qty);

            t.join();
        }

        else if(choice == 6){
            int numOrders;

            cout << "How many orders to simulate? ";
            cin >> numOrders;

            vector<thread> threads;

            for(int i=0;i<numOrders;i++){
                int id,qty;

                cout << "\nOrder " << i+1 << endl;

                cout << "Product ID: ";
                cin >> id;

                cout << "Quantity: ";
                cin >> qty;

                threads.push_back(thread(&OrderProcessing::processOrder, &orderSystem, ref(inventory), id, qty));
            }

            for(thread &t : threads){
                t.join();
            }
        }

        else if(choice == 7){
            cout << "Exiting system...\n";
            break;
        }

        else{
            cout << "Invalid option.\n";
        }
    }

    return 0;
}
