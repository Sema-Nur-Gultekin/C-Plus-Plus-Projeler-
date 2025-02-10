#include <iostream>
using namespace std;

class TicTacToe {
private:
    int tahta[3][3];
    int simdikiOyuncu;

public:
    TicTacToe() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                tahta[i][j] = 0;
            }
        }
        simdikiOyuncu = 1;
    }

    void tahtayiYazdir() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                cout << tahta[i][j] << " ";
            }
            cout << endl;
        }
    }

    int gecerliHamleMi(int satir, int sutun) {
        return satir >= 0 && satir < 3 && sutun >= 0 && sutun < 3 && tahta[satir][sutun] == 0;
    }

    void hamleYap(int satir, int sutun) {
        if (gecerliHamleMi(satir, sutun)) {
            tahta[satir][sutun] = simdikiOyuncu;
            simdikiOyuncu = simdikiOyuncu == 1 ? 2 : 1;
        } else {
            cout << "Gecersiz hamle! Lutfen baska bir hucre secin." << endl;
        }
    }

    int kazananKontrolu() {
        for (int i = 0; i < 3; i++) {
            if (tahta[i][0] == tahta[i][1] && tahta[i][1] == tahta[i][2] && tahta[i][0] != 0) {
                return tahta[i][0];
            }
            if (tahta[0][i] == tahta[1][i] && tahta[1][i] == tahta[2][i] && tahta[0][i] != 0) {
                return tahta[0][i];
            }
        }
        if (tahta[0][0] == tahta[1][1] && tahta[1][1] == tahta[2][2] && tahta[0][0] != 0) {
            return tahta[0][0];
        }
        if (tahta[0][2] == tahta[1][1] && tahta[1][1] == tahta[2][0] && tahta[0][2] != 0) {
            return tahta[0][2];
        }
        return 0;
    }

    void oyunuBaslat() {
        cout << "Tic Tac Toe oyununa hos geldiniz!" << endl;
        cout << "Satir ve sutun numaralari 0'dan 2'ye kadar." << endl;
        tahtayiYazdir();

        int ilkOyuncu;
        cout << "ilk oyuncu olarak (1) veya ikinci oyuncu olarak (2) baslamak istersiniz? ";
        cin >> ilkOyuncu;
        simdikiOyuncu = ilkOyuncu;

        while (true) {
            int satir, sutun;
            cout << "Satir numarasini girin: ";
            cin >> satir;
            cout << "Sutun numarasini girin: ";
            cin >> sutun;

            hamleYap(satir, sutun);
            tahtayiYazdir();
            
            int kazanan = kazananKontrolu();
            if (kazanan != 0) {
                cout << "Tebrikler! Oyunu kazanan oyuncu " << kazanan << "." << endl;
                break;
            }
        }

        cout << "Oyun bitti!" << endl;
    }
};

int main() {

    TicTacToe TicTacToe;
    TicTacToe.oyunuBaslat();
    return 0;
}
