#include <iostream>
using namespace std;

// Abstract class for the Product that is to be created
class ProductBase {
public:
    virtual ~ProductBase() {}
    virtual void doOperation() = 0;
};

// Implementations for the different products: Product1 and Product2
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

// Abstract class for the Creator, that creates the Product objects
class CreatorBase {
public:
    virtual ProductBase* factoryMethod() = 0;
};

// Implementations for the different products: Creator1 and Creator2

// This creates Product1
class Creator1: public CreatorBase {
public:
    ProductBase* factoryMethod() override {
        cout << "Creator 1, created Product 1\n";
        return new Product1();
    }
};

// This creates Product2
class Creator2: public CreatorBase {
public:
    ProductBase* factoryMethod() override {
        cout << "Creator 2, created Product 2\n";
        return new Product2();
    }
};

int main() {
    // Create a product 1 using Factory from Creator1
    Creator1 creator1;
    auto product1 = creator1.factoryMethod(); 
    product1->doOperation();

    // Create a product 2 using Factory from Creator2
    Creator2 creator2;
    auto product2 = creator2.factoryMethod();
    product2->doOperation(); 
}
