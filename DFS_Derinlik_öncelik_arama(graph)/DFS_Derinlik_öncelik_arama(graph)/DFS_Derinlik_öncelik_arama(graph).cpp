#include <iostream>
using namespace std;

#include <iostream>
#include <vector>

class Graf {
private:
    int dugumSayisi;
    vector<vector<int>> komsulukMatrisi;

public:
    Graf(int dugumSayisi) {
        this->dugumSayisi = dugumSayisi;
        komsulukMatrisi.resize(dugumSayisi, vector<int>(dugumSayisi, 0));
    }

    void kenarEkle(int kaynak, int hedef) {
        if (kaynak >= 0 && kaynak < dugumSayisi && hedef >= 0 && hedef < dugumSayisi) {
            komsulukMatrisi[kaynak][hedef] = 1;
        }
        else {
            cout << "Geçersiz kenar!\n";
        }
    }

    void grafYazdir() {
        cout << "Komsuluk Matrisi:\n";
        for (int i = 0; i < dugumSayisi; i++) {
            for (int j = 0; j < dugumSayisi; j++) {
                cout << komsulukMatrisi[i][j] << " ";
            }
            cout << "\n";
        }
    }

    void DFS(int baslangicDugumu, vector<bool>& ziyaretEdildi) {
        ziyaretEdildi[baslangicDugumu] = true;
        cout << baslangicDugumu << " ";

        for (int i = 0; i < dugumSayisi; i++) {
            if (komsulukMatrisi[baslangicDugumu][i] == 1 && !ziyaretEdildi[i]) {
                DFS(i, ziyaretEdildi);
            }
        }
    }
};

int main() {
    int dugumSayisi;
    cout << "Dugum sayisini giriniz: ";
    cin >> dugumSayisi;

    Graf graf(dugumSayisi);

    int kenarSayisi;
    cout << "Kenar sayisini giriniz: ";
    cin >> kenarSayisi;

    cout << "Kenarlarin bagladigi dugumleri giriniz:\n";
    for (int i = 0; i < kenarSayisi; i++) {
        int kaynak, hedef;
        cout << "Kenar " << i + 1 << ": ";
        cin >> kaynak >> hedef;
        graf.kenarEkle(kaynak, hedef);
    }

    graf.grafYazdir();

    int baslangicDugumu;
    cout << "DFS gezisi icin baslangic dugumu giriniz: ";
    cin >> baslangicDugumu;

    vector<bool> ziyaretEdildi(dugumSayisi, false);
    cout << "DFS gezisi: ";
    graf.DFS(baslangicDugumu, ziyaretEdildi);

    return 0;
}

