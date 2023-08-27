#include<iostream>
using namespace std;

/////////////////////////////// Violating Open-Close principle ///////////////////////////////
/*
    Problem with this implementation is that we I want to add a new mode of payment,
    then the existing code has to be modified. This might introduce regression etc,
    need to test the existing code etc.
*/
class Payment {
public:
    void pay(string mode) {
        if(mode == "credit card") {
            cout << "Paying with credit card" << endl;
        } else if(mode == "debit card") {
            cout << "Paying with debit card" << endl;
        } else if(mode == "net banking") {
            cout << "Paying with net banking" << endl;
        }
    }
};

////////////////////////////// Adhering Open-Close principle /////////////////////////////////
class PaymentBase {
public:
    virtual void pay() = 0;
};

class CreditCardPayment: public PaymentBase {
public:
    void pay() {
        cout << "Paying with credit card" << endl;
    }
};

class DebitCardPayment: public PaymentBase {
public:
    void pay() {
        cout << "Paying with debit card" << endl;
    }
};

class NetBankingPayment: public PaymentBase {
public:
    void pay() {
        cout << "Paying with net banking" << endl;
    }
};

int main() {
    cout << "Violating Open-Close principle" << endl;
    Payment payment;
    payment.pay("credit card");

    cout << "Adhering Open-Close principle" << endl;
    CreditCardPayment creditCardPayment;
    creditCardPayment.pay();

    return 0;
}