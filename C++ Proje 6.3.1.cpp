#include <iostream>
using namespace std;

class Fraction {
public:

    Fraction(int pay, int payda) {
        if (payda == 0) {
            cout << "Hata: Payda 0 olamaz. Gecersiz kesir olusturuluyor." << endl;
            this->pay = 0;
            this->payda = 1;
        } else {
            this->pay = pay;
            this->payda = payda;
            sadelestir();
        }
    }

    void print() const {
        cout << pay << "/" << payda << endl;
    }

private:
    int pay;
    int payda;

    int gcd(int a, int b) const {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    void sadelestir() {
        int ortak_bolen = gcd(pay, payda);
        pay /= ortak_bolen;
        payda /= ortak_bolen;
    }
};

int main() {

    Fraction f(8, 12);
    f.print(); 

    Fraction g(1, 0); 
    g.print(); 

    return 0;
}
