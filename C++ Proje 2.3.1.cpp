#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int main(){

	int *ptr=(int*)malloc(2*sizeof(int));
	if(ptr==NULL){
		cout << "Bellek ayrilamadi!";
		return 1;
	}
	
	cout << "1.Elemani giriniz: ";
	cin >> ptr[0];
	cout << "2.Elemani giriniz: ";
	cin >> ptr[1];

	ptr=(int*)realloc(ptr, 3*sizeof(int));
	if(ptr==NULL){
		cout << "Bellek geniþletilemedi!";
		return 1;
	}

	ptr[2]=ptr[0]+ptr[1];
	cout << "3.Eleman: " << ptr[2];

	free(ptr);
	ptr=NULL;
	return 0;
}
