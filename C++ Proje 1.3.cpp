#include<iostream>
using namespace std;

template <typename A>
A toplama(A x,A y){
	return x+y;
}
template <typename A>
A carpma(A x,int y){
	A sonuc=x*y;
	return sonuc;
}
template <typename A,typename B>
A cikarma(A x,B y){
	return x-y;
}

int main(){
	
	int int1,int2;
	cout << "Toplamak istediginiz sayilari giriniz: ";
	cin >> int1 >> int2;
	cout << "Toplam: " << toplama(int1,int2) << endl;
		cout << "------------------------------------------\n";
	double double1;
	cout << "Carpmak istediginiz sayilari giriniz: ";
	cin >> double1 >> int1;
	cout << "Carpim: " << carpma(double1,int1) << endl;
		cout << "------------------------------------------\n";
	float float1;
	cout << "Cikartmak istediginiz sayilari giriniz: ";
	cin >> float1 >> double1;
	cout << "Cikarma: " << cikarma(float1,double1) << endl;
}
