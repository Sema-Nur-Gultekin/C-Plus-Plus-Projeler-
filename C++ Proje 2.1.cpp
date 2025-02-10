#include<iostream>
using namespace std;

void myPrintf(const char *x,int a,double b,const char *y){
	while(*x != '\0'){
		if(*x == '%'){
			x++;
			if(*x == 'd'){
				cout << a << endl;
			}
			if(*x == 'f'){
				cout << b << endl;
			}
			if(*x == 's'){
				cout << y << endl;
			}
		}
		x++;
	}
}

int main(){

	myPrintf("%d, %f, %s", 125, 526.14, "C++ Ileri Konular");
	return 0;
}
