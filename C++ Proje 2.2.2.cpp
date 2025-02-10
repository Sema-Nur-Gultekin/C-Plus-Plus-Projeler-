#include<iostream>
#include<stdarg.h>
using namespace std;

void myPrintf(const char* ptr, ...){
	va_list args;
	va_start(args, ptr);
	
	while(*ptr!='\0'){
		if(*ptr=='%' && *(ptr+1)=='d'){
			int num = va_arg(args, int);
			cout << num;
			ptr+=2;
		}
		else if(*ptr=='%' && *(ptr+1)=='f'){
			double num = va_arg(args, double);
			cout << num;
			ptr+=2;
		}
		else if(*ptr=='%' && *(ptr+1)=='s'){
			const char* str = va_arg(args, const char*);
			cout << str;
			ptr+=2;
	    }
	    else
	    cout << *ptr;
	    ++ptr;
    }
    va_end(args);
}

int main(){

	myPrintf("%d, %f  ve %s", 125, 526.14, "C++ ileri konular");
	return 0;
}
