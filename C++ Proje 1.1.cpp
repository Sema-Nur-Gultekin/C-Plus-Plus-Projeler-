#include<iostream>
using namespace std;

double uzunluk(double a,double b,double c){
    return a*b*c;
}
double uzunluk(double r,double h){
	double pi=3.14;
	return pi*r*r*h;
}
double uzunluk(double r){
	double pi=3.14;
	return 4/3*pi*r*r*r;
}

int main(){

	double x,y,z;
	cout << "Dikdortgen tankin hacim bilgilerini giriniz: ";
	cin >> x >> y >> z;
	cout << "Dikdortgen tankin hacmi: " << uzunluk(x,y,z) << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Silindir tankin hacim bilgilerini sirayla giriniz (yaricap,yukseklik): ";
	cin >> x >> y;
	cout << "Silindir tankin hacmi: " << uzunluk(x,y) << endl;
	cout << "-----------------------------------------------------" << endl;
	cout << "Kuresel tankin hacim bilgilerini giriniz: ";
	cin >> x;
	cout << "Kuresel tankin hacmi: " << uzunluk(x) << endl;
}
