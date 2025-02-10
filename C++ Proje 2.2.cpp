#include<iostream>
using namespace std;

char *araFonk(char *x, int y){
	while(*x != '\0'){
		if(*x==y){
			return x;
		}
		x++;
		if(y=='0'){
			return x;
		}
	}
		return NULL;
}

int main(){

	char x[]="MERHABA";
	char *ptr;
	ptr=araFonk(x,'R');
	if(ptr){
		cout << "Adresi: " << &ptr;
	}
	else{
		cout << "Aranan Bulunamadi!";
	}
	ptr=NULL;
	return 0;
}
