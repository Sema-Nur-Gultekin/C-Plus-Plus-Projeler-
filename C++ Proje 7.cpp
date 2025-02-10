#include <iostream>
#include <string>

using namespace std;

class Package {
protected:
    string gondericiIsim;
    string gondericiAdres;
    string gondericiSehir;
    string gondericiUlke;
    string gondericiPostaKodu;
    string aliciIsim;
    string aliciAdres;
    string aliciSehir;
    string aliciUlke;
    string aliciPostaKodu;
    double agirlik; 
    double kgBasiUcret; 

public:
    Package(const string &gondericiIsim, const string &gondericiAdres, const string &gondericiSehir,
            const string &gondericiUlke, const string &gondericiPostaKodu,
            const string &aliciIsim, const string &aliciAdres, const string &aliciSehir,
            const string &aliciUlke, const string &aliciPostaKodu,
            double agirlik, double kgBasiUcret)
        : gondericiIsim(gondericiIsim), gondericiAdres(gondericiAdres), gondericiSehir(gondericiSehir),
          gondericiUlke(gondericiUlke), gondericiPostaKodu(gondericiPostaKodu),
          aliciIsim(aliciIsim), aliciAdres(aliciAdres), aliciSehir(aliciSehir),
          aliciUlke(aliciUlke), aliciPostaKodu(aliciPostaKodu) {
        this->agirlik = agirlik > 0 ? agirlik : 1;
        this->kgBasiUcret = kgBasiUcret > 0 ? kgBasiUcret : 1;
    }

    virtual double calculateCost() const {
        return agirlik * kgBasiUcret;
    }
};

class TwoDayPackage : public Package {
private:
    double sabitUcret; 

public:
    TwoDayPackage(const string &gondericiIsim, const string &gondericiAdres, const string &gondericiSehir,
                  const string &gondericiUlke, const string &gondericiPostaKodu,
                  const string &aliciIsim, const string &aliciAdres, const string &aliciSehir,
                  const string &aliciUlke, const string &aliciPostaKodu,
                  double agirlik, double kgBasiUcret, double sabitUcret)
        : Package(gondericiIsim, gondericiAdres, gondericiSehir, gondericiUlke, gondericiPostaKodu,
                  aliciIsim, aliciAdres, aliciSehir, aliciUlke, aliciPostaKodu,
                  agirlik, kgBasiUcret), sabitUcret(sabitUcret) {
        this->sabitUcret = sabitUcret >= 0 ? sabitUcret : 0;
    }

    double calculateCost() const override {
        return Package::calculateCost() + sabitUcret;
    }
};

class OvernightPackage : public Package {
private:
    double ekstraKgUcreti; 

public:
    OvernightPackage(const string &gondericiIsim, const string &gondericiAdres, const string &gondericiSehir,
                     const string &gondericiUlke, const string &gondericiPostaKodu,
                     const string &aliciIsim, const string &aliciAdres, const string &aliciSehir,
                     const string &aliciUlke, const string &aliciPostaKodu,
                     double agirlik, double kgBasiUcret, double ekstraKgUcreti)
        : Package(gondericiIsim, gondericiAdres, gondericiSehir, gondericiUlke, gondericiPostaKodu,
                  aliciIsim, aliciAdres, aliciSehir, aliciUlke, aliciPostaKodu,
                  agirlik, kgBasiUcret), ekstraKgUcreti(ekstraKgUcreti) {
        this->ekstraKgUcreti = ekstraKgUcreti >= 0 ? ekstraKgUcreti : 0;
    }

    double calculateCost() const override {
        return Package::calculateCost() + (ekstraKgUcreti * agirlik);
    }
};

int main() {

    Package temelPaket("Gönderen Adý", "Gönderen Adres", "Gönderen Þehir", "Gönderen Ülke", "12345",
                       "Alýcý Adý", "Alýcý Adres", "Alýcý Þehir", "Alýcý Ülke", "67890", 5.0, 10.0);

    TwoDayPackage ikiGunlukPaket("Gönderen Adý", "Gönderen Adres", "Gönderen Þehir", "Gönderen Ülke", "12345",
                                 "Alýcý Adý", "Alýcý Adres", "Alýcý Þehir", "Alýcý Ülke", "67890", 5.0, 10.0, 15.0);

    OvernightPackage birGunlukPaket("Gönderen Adý", "Gönderen Adres", "Gönderen Þehir", "Gönderen Ülke", "12345",
                                    "Alýcý Adý", "Alýcý Adres", "Alýcý Þehir", "Alýcý Ülke", "67890", 5.0, 10.0, 5.0);

    cout << "Temel Paket Ücreti: " << temelPaket.calculateCost() << " TL" << endl;
    cout << "Ýki Günlük Paket Ücreti: " << ikiGunlukPaket.calculateCost() << " TL" << endl;
    cout << "Bir Günlük Paket Ücreti: " << birGunlukPaket.calculateCost() << " TL" << endl;

    return 0;
}

