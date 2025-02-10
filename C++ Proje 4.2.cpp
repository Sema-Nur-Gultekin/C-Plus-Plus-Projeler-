#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

enum MonsterType{
	Dev,
	Ejderha,
	Ork,
	Dev_Orumcek,
	Balcik
};

struct Monster{
	MonsterType type;
	string name;
	int health;
	
	void printMonster()const{
	string typeName;
	switch(type){
		case Dev:
			typeName = "Dev";
			break;
		case Ejderha:
			typeName = "Ejderha";
			break;
		case Ork:
			typeName = "Ogre";
			break;
		case Dev_Orumcek:
			typeName = "Dev Orumcek";
			break;
		case Balcik:
			typeName = "Slime";
			break;
		default:
			typeName = "Bilinmiyor";
			break;
	}
	cout << "Bu " << typeName << ", " << name << " olarak adlandirilir ve " << health << " cana sahiptir.\n";
}
};

int main(){

	Monster ogre={Ork, "Torg", 145};
	Monster slime={Balcik, "Blurp", 23};
	
	ogre.printMonster();
    slime.printMonster();
	
	return 0;
}
