#include<iostream>
using namespace std;

void topla(int *sonuc, int sayi1, int sayi2){
	*sonuc=sayi1+sayi2;
}

void cikar(int *sonuc, int sayi1, int sayi2){
	*sonuc=sayi1-sayi2;
}

void carp(int *sonuc, int sayi1, int sayi2){
	*sonuc=sayi1*sayi2;
}

void bol(int *sonuc, int sayi1, int sayi2){
	if(sayi2==0){
		cout << "HATA! Bolen sifir '0' olamaz." << endl;
	}
	else 
	*sonuc=sayi1/sayi2;
}

void mod(int *sonuc, int sayi1, int sayi2){
	if(sayi2==0){
		cout << "HATA! Bolen sifir '0' olamaz." << endl;
	}
	else 
	*sonuc=sayi1%sayi2;	
}

int main(){

	cout << "Yapmak istediginiz islemin basindaki sayiyi giriniz:" << endl;
	cout << "1.Toplama\n2.Cikarma\n3.Carpma\n4.Bolme\n5.Mod Alma" << endl;
	int islem;
	cin >> islem;
	cout << "---------------------------------------------------------" << endl;
	cout << "Sirayla sayilari giriniz:" << endl;
	int sayi1,sayi2;
	cin >> sayi1 >> sayi2;
	cout << "---------------------------------------------------------" << endl;
	int sonuc;
	switch(islem){
		case 1:
			topla(&sonuc, sayi1, sayi2);
			cout << "Sonuc: " << sonuc;
			break;
		case 2:
		    cikar(&sonuc, sayi1, sayi2);
			cout << "Sonuc: " << sonuc;
			break; 
		case 3:
		    carp(&sonuc, sayi1, sayi2);
			cout << "Sonuc: " << sonuc;
			break; 
		case 4:
		    bol(&sonuc, sayi1, sayi2);
			cout << "Sonuc: " << sonuc;
			break; 
		case 5:
		    mod(&sonuc, sayi1, sayi2);
			cout << "Sonuc: " << sonuc;
			break; 
		default:
			cout << "HATA! Gecersiz islem..";
	}
	return 0;
}

