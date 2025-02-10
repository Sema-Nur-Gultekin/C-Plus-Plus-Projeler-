#include <string>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

struct CanavarListesi{
	string turler[8] = {"Dragon", "Goblin", "Ogre", "Orc", "Skeleton", "Troll", "Vampire", "Zombie"};
	int max_tur_sayisi = 8;
};

class Canavar{
	private:
		string ad;
		int canPuani;
	public:
		Canavar(string ad="", int canPuani=0) : ad(ad), canPuani(canPuani){}
		string getAd() const { return ad; }
		int getCanPuani() const { return canPuani; }
		void print() const {
			cout << "Canavar Adi: " << ad << ", Can Puani: " << canPuani << endl;
		}
};

int main(){

	srand(time(0));
	CanavarListesi canavarlar;
	Canavar canavar;
	
	for(int i=0; i<5; i++){
		int tur_index = rand() % canavarlar.max_tur_sayisi;
		string tur = canavarlar.turler[tur_index];
		int canPuani = rand() % 101;
		canavar = Canavar(tur, canPuani);
		canavar.print();
	}
	return 0;
}
