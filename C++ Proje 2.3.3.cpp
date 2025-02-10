#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int **sifirmatrisi(int, int);

int main(){

	int satir, sutun;
	cout << "Sirayla satir ve sutun sayisini giriniz: ";
	cin >> satir >> sutun;
	int **ptr=sifirmatrisi(satir, sutun);
	
	for(int i=0;i<satir;i++){
		for(int j=0;j<sutun;j++){
			cout << ptr[i][j] << " ";
		}
		cout << "\n";
	}
	
	for(int i=0;i<=satir;i++){
		free(ptr[i]);
	}
	free(ptr);
	ptr=NULL;
	return 0;
}

int **sifirmatrisi(int satir, int sutun){
	
	int **ptr=(int**)calloc(satir, sizeof(int*));
	if(ptr==NULL){
		cout << "Bellek ayrilamadi!";
		return NULL;
	}
	
	for(int i=0;i<satir;i++){
		ptr[i]=(int*)calloc(sutun, sizeof(int));
		if(ptr[i]==NULL){
			cout << "Bellek ayrilamadi!";
			return NULL;
		}
	}
	
	return ptr;
}
