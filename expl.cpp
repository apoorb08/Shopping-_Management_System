//Online Shopping Management System
//TODO:
//1. Menu System
//2. Product(class), Func to create and modify products.
//3. Bill System
//4. File Handling(Done)
//5. Allow admin to modify Products.csv

#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

//Product class
class Product {
private:
    string name;
    double price;

public:
    Product(string n, double p): name(n), price(p) {}
    string getName() const {return name;}
    double getPrice() const {return price;}

};

class Bill {
private:
    vector<Product> cart;

public:
    void addProduct(const Product& product) {
        cart.push_back(product);
    }

    void displayBill() {
        if (cart.empty()) {
            cout << "Bill Empty. Please add items to the bill." << endl;
            return;
        }

        double amt = 0;
        cout << "Items:" << endl;
        for (const Product& product: cart) {
            cout << "Name: " << product.getName() << ", Price: Rs." << product.getPrice() << endl;
            amt += product.getPrice();
        }
        cout << "Total Amount: Rs." << amt << endl << endl;
    }

    void removeProduct(string product) {
        if (cart.empty()) {
            cout << "Bill Empty. No products can be removed from it." << endl;
            return;
        }
        vector <Product>::iterator delIndex;
        for (delIndex = cart.begin(); delIndex != cart.end(); ++delIndex) {
            if (delIndex->getName() == product) {
                cart.erase(delIndex);
                cout << "Product removed from bill." << endl;
                return;
            }
        }
        cout << "Product does not exist in the bill." << endl;
    }
};

bool isProductExists(const string& productName, const vector<Product>& productList) {
    for (const Product& product: productList) {
        if(product.getName() == productName) {
            return true;
        }
    }
    return false;
}

vector<Product> readCSV(const string& filename) {
    vector<Product> productList;
    ifstream file(filename);

    if (file.is_open()) {
        string line;
        while(getline(file, line)) {
            stringstream ss(line);
            string name;
            double price;
            if(getline(ss, name, ',') && ss >> price) {
                Product product(name, price);
                productList.push_back(product);
            }
        }
        file.close();
    } else {
        cerr << "Error Opening File: " << filename << endl;
    }
    return productList;
}

void displayMenu() {
    cout << "Main Menu:" << endl;
    cout << "1. Add Product to Cart" << endl;
    cout << "2. Show Bill" << endl;
    cout << "3. Remove Product from Cart" << endl;
    cout << "0. Exit" << endl;
}

void menuProduct(Bill& bill, vector<Product>& productList) {
    string name;
    double price;
    cout << "Enter the Product name: ";
    cin >> name;
    if (isProductExists(name, productList)) {
        for (const Product& product: productList) {
            if(product.getName() == name) {
                bill.addProduct(product);
                cout << name << " added successfully to the bill!" << endl;
                return;
            }
        }
    } else {
        cout << "Product not found. Please try again." << endl;
    }
}

void removeProduct(Bill& bill) {
    string delProduct;
    cout << "Enter Product to remove: ";
    cin >> delProduct;
    bill.removeProduct(delProduct);
}

int main() {
    string productFile = "Products.csv";
    vector<Product> productList = readCSV(productFile);

    int choice;
    static Bill bill;

    while(true) {
        menu:
        displayMenu();
        cout<< "Enter your Choice: ";
        if (cin >> choice) {
            switch (choice) {
                case 1:
                    menuProduct(bill, productList);
                    break;
                case 2:
                    bill.displayBill();
                    break;
                case 3:
                    removeProduct(bill);
                    break;
                case 0:
                    cout << "Exiting....." << endl;
                    cout << "Thank you for using our services!"<< endl;
                    exit(0);
                default:
                    cout << "Invalid Input! Please Try Again." << endl;
            }
        } else { //Error Handling of input choice
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid Datatype Error!!!!" << endl;
            goto menu;
        }
    }
}