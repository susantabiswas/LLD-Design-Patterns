#include <iostream>
using namespace std;

class ProductBase {
public:
    virtual ~ProductBase() {}
    virtual void doOperation() = 0;
};

class Product1: public ProductBase {
public:
    void doOperation() override {
        cout << "Inside Product 1\n";
    }
};

class Product2: public ProductBase {
public:
    void doOperation() override {
        cout << "Inside Product 2\n";
    }
};

class CreatorBase {
public:
    virtual ProductBase* factoryMethod() = 0;
};

class Creator1: public CreatorBase {
public:
    ProductBase* factoryMethod() override {
        cout << "Creator 1, created Product 1\n";
        return new Product1();
    }
};

class Creator2: public CreatorBase {
public:
    ProductBase* factoryMethod() override {
        cout << "Creator 2, created Product 2\n";
        return new Product2();
    }
};

int main() {
    // Create a product 1 
    Creator1 creator1;
    auto product1 = creator1.factoryMethod(); 
    product1->doOperation();

    // Create a product 2
    Creator2 creator2;
    auto product2 = creator2.factoryMethod();
    product2->doOperation(); 
}
