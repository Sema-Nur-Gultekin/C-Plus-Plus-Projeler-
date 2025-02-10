#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#include "filmislemleri.h"

const int MAX_FILM_SAYISI = 100; 

void filmEkle(filminOzellikleri*, int&);
void filmCikar(filminOzellikleri*, int&);
void filmleriListele(filminOzellikleri*, int);

int main() {

    filminOzellikleri filmler[MAX_FILM_SAYISI];
    int sayac = 0;

    cout << "-------------------------------------------" << endl;
    cout << " Film Veritabani Uygulamasina Hos Geldiniz!" << endl;
    cout << "-------------------------------------------" << endl;

    while (true) {
        cout << "Ana Menu\n(1) Film Ekle\n(2) Film Cikar\n(3) Tum Filmleri Listele\n(0) Cikis" << endl;
        cout << "Seciminizi Giriniz...: ";
        int secim;
        cin >> secim;

        switch (secim) {
            case 0:
                return 0;
            case 1:
                filmEkle(filmler, sayac);
                sayac++;
                break;
            case 2:
                filmCikar(filmler, sayac);
                break;
            case 3:
                filmleriListele(filmler, sayac);
                break;
            default:
                cout << "Gecersiz secim!" << endl;
                break;
        }
    }
    return 0;
}

void filmEkle(filminOzellikleri *film, int &sayac) {
    if (sayac >= MAX_FILM_SAYISI) {
        cout << "Maksimum film sayisina ulasildi." << endl;
        return;
    }

    cout << "\nFilm Ekleme" << endl;
    cin.ignore();
    cout << "Filmin Adi: ";
    getline(cin, film[sayac].ad);
    cout << "Filmin Yonetmeni: ";
    getline(cin, film[sayac].yonetmen);
    cout << "Filmin Yapim Yili: ";
    cin >> film[sayac].yapimYili;
    cout << "Filmin Turu (0-Aksiyon, 1-Gerilim, 2-Komedi, 3-Dram): ";
    int tur;
    cin >> tur;
    film[sayac].tur = static_cast<filminTuru>(tur);
    cout << "\nFilm Bilgisi Eklendi\n" << endl;
}

void filmCikar(filminOzellikleri *film, int &sayac) {
    if (sayac == 0) {
        cout << "Listede silinecek film bulunmamaktadir." << endl;
        return;
    }

    filmleriListele(film, sayac);

    cout << "Yukaridaki Listeden Silmek Istediginiz filmin id'sini Giriniz: " ;
    int id;
    cin >> id;

    if (id >= 0 && id < sayac) {
        for (int i = id; i < sayac - 1; i++) {
            film[i] = film[i + 1];
        }
        sayac--;
        cout << "\nSectiginiz Film Silindi!\n" << endl;
    } else {
        cout << "\nGecersiz ID!" << endl;
    }
}

void filmleriListele(filminOzellikleri *film, int sayac) {
    if (sayac == 0) {
        cout << "Listede hic film bulunmamaktadir." << endl;
        return;
    }

    cout << "\nFilmlerin Listesi" << endl;
    for (int i = 0; i < sayac; i++) {
        cout << "Film ID: " << i << endl;
        cout << "Film Adi: " << film[i].ad << endl;
        cout << "Yonetmen: " << film[i].yonetmen << endl;
        cout << "Yapim Yili: " << film[i].yapimYili << endl;
        cout << "Film Turu: " << film[i].tur << endl << endl;
    }
}
