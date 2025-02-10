#include <iostream>
using namespace std;

class Fraction {
private:
    int pay;
    int payda;

public:
    Fraction(int pay, int payda) : pay(pay), payda(payda == 0 ? 1 : payda) {}

    void yazdir() const {
        cout << pay << "/" << payda << endl;
    }

    friend  Fraction operator*(const  Fraction& k1, const  Fraction& k2);
    friend ostream& operator<<(ostream& os, const  Fraction& k);
    friend bool operator==(const  Fraction& k1, const  Fraction& k2);
};

 Fraction operator*(const  Fraction& k1, const  Fraction& k2) {
    return  Fraction(k1.pay * k2.pay, k1.payda * k2.payda);
}

ostream& operator<<(ostream& os, const  Fraction& k) {
    os << k.pay << "/" << k.payda;
    return os;
}

bool operator==(const  Fraction& k1, const  Fraction& k2) {
    return (k1.pay * k2.payda == k2.pay * k1.payda);
}

int main() {

    Fraction k1(3, 4);
    Fraction k2(2, 5);
    Fraction k3 = k1 * k2;

    cout << k1 << " * " << k2 << " = " << k3 << endl;
    cout << (k1 == k2 ? "Esit" : "Esit Degil") << endl;

    Fraction k4(1, 0); 
    k4.yazdir();

    return 0;
}

