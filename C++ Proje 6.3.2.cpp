#include <iostream>
using namespace std;

class Fraction {
public:
    Fraction(int pay = 0, int payda = 1) : pay(pay), payda(payda) {
        if (payda == 0) {
            cout << "Hata: Payda 0 olamaz. Gecersiz kesir olusturuluyor." << endl;
            this->pay = 0;
            this->payda = 1;
        } else {
            sadelestir();
        }
    }

    friend ostream& operator<<(ostream& os, const Fraction& kesir) {
        os << kesir.pay << "/" << kesir.payda;
        return os;
    }

    friend istream& operator>>(istream& is, Fraction& kesir) {
        is >> kesir.pay >> kesir.payda;
        kesir.sadelestir();
        return is;
    }

    friend Fraction operator*(const Fraction& lhs, const Fraction& rhs) {
        return Fraction(lhs.pay * rhs.pay, lhs.payda * rhs.payda);
    }

    friend bool operator==(const Fraction& lhs, const Fraction& rhs) {
        return (lhs.pay * rhs.payda) == (rhs.pay * lhs.payda);
    }

    friend bool operator!=(const Fraction& lhs, const Fraction& rhs) {
        return !(lhs == rhs);
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

    Fraction f1(3, 4);
    Fraction f2(2, 3);

    Fraction carpim = f1 * f2;
    cout << "Carpim: " << carpim << endl;

    Fraction karsilastirma(3, 4);
    cout << "Kesirler esit mi? " << (f1 == karsilastirma) << endl;

    cout << "Bir kesri girin (pay payda): ";
    Fraction girdi;
    cin >> girdi;
    cout << "Girdiginiz kesir: " << girdi << endl;

    return 0;
}
