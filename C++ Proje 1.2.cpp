#include<iostream>
using namespace std;

double indisdegerleri(double tek[], int a) {
	cout << "Tek indis degerleriniz:\n";
	for(int i=0;i<a;i++){
	     cout << "[" << i << "] : " << tek[i] << endl;
	}
	cout << "-------------------------------------------------------\n";
}
double indisdegerleri(double cift[][100], int b, int c) {
	cout << "Cift indis degerleriniz:\n";
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
		    cout << "[" << i << "]" << "[" << j << "] : " << cift[i][j] << endl;
		}
	}
	cout << "-------------------------------------------------------\n";
}

int main(){

	int a,b,c;
	cout << "Tek boyutlu dizinizin buyuklugunu giriniz []: ";
	cin >> a;
	double tek[a];
	cout << "Dizi degerlerini giriniz:\n";
	for(int i=0;i<a;i++){
		cout << "[" << i << "] : ";
		cin >> tek[i];
	}
	 cout << "-------------------------------------------------------\n";
     indisdegerleri(tek, a);

	cout << "Cift boyutlu dizinizin buyuklugunu giriniz [][]: ";
	cin >> b >> c;
	double cift[b][100];
	cout << "Dizi degerlerini giriniz:\n";
	for(int i=0;i<b;i++){
		for(int j=0;j<c;j++){
			cout << "[" << i << "]" << "[" << j << "] : ";
			cin >> cift[i][j];
		}
	}
     cout << "-------------------------------------------------------\n";
	 indisdegerleri(cift, b, c);
}
