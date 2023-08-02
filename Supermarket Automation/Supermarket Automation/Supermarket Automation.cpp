#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;
class Urun {
public:
    string ad;
    double fiyat;
    int stokMiktari;

    Urun(string ad, double fiyat, int stokMiktari) : ad(ad), fiyat(fiyat), stokMiktari(stokMiktari) {}
};

class Supermarket {
private:
    vector<Urun> urunler;

public:
    void urunEkle(string ad, double fiyat, int stokMiktari) { urunler.push_back(Urun(ad, fiyat, stokMiktari));}

    void urunSil(string ad) {
        for (auto it = urunler.begin(); it != urunler.end(); ++it) {
            if (it->ad == ad) {
                urunler.erase(it);
                cout << ad << " urunu silindi." << endl;
                return;
            }
        }
        cout << ad << " urunu bulunamadi." << endl;
    }

    void urunListesiYazdir() {
        cout << "\n-- Urun Listesi --\n";
        for (const auto& urun : urunler) {
            cout << "Urun Adi: " << urun.ad << ", Fiyat: " << urun.fiyat << ", Stok Miktarý: " << urun.stokMiktari << endl;
        }
    }

    void urunlariDosyayaKaydet() {
        std::ofstream dosya("urunler.txt");
        if (dosya.is_open()) {
            for (const auto& urun : urunler) {
                dosya << urun.ad << "," << urun.fiyat << "," << urun.stokMiktari << "\n";
            }
            dosya.close();
            cout << "Urunler dosyaya kaydedildi." << endl;
        }
        else {
            cout << "Dosya acilamadi." << endl;
        }
    }

    void urunleriDosyadanOku() {
        ifstream dosya("urunler.txt");
        if (dosya.is_open()) {
            urunler.clear(); 
            string satir;
            while (getline(dosya, satir)) {
                size_t pos = satir.find(",");
                string ad = satir.substr(0, pos);
                satir.erase(0, pos + 1);

                pos = satir.find(",");
                double fiyat = stod(satir.substr(0, pos));
                satir.erase(0, pos + 1);

                int stokMiktari = stoi(satir);

                urunler.push_back(Urun(ad, fiyat, stokMiktari));
            }
            dosya.close();
            cout << "Urunler dosyadan okundu." << endl;
        }
        else {
            cout << "Dosya acilamadi." << endl;
        }
    }
};

int main() {
    Supermarket market;
    market.urunleriDosyadanOku(); // Daha önceden kaydedilmiþ ürünleri oku

    int secim;

    while (true) {
        cout << "\n-- Supermarket Menu --\n";
        cout << "1. Urun Ekle\n";
        cout << "2. Urun Sil\n";
        cout << "3. Urun Listesini Goster\n";
        cout << "4. Urunleri Dosyaya Kaydet\n";
        cout << "0. Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 1) {
            string ad;
            double fiyat;
            int stokMiktari;
            cout << "Urun Adi: ";
            cin.ignore();
            getline(cin, ad);
            cout << "Fiyat: ";
            cin >> fiyat;
            cout << "Stok Miktarý: ";
            cin >> stokMiktari;
            market.urunEkle(ad, fiyat, stokMiktari);
        }
        else if (secim == 2) {
            string ad;
            cout << "Silinecek Urun Adi: ";
            cin.ignore();
            getline(cin, ad);
            market.urunSil(ad);
        }
        else if (secim == 3) {
            market.urunListesiYazdir();
        }
        else if (secim == 4) {
            market.urunlariDosyayaKaydet();
        }
        else if (secim == 0) {
            cout << "Supermarket otomasyonu kapatiliyor." << endl;
            break;
        }
        else {
            cout << "Gecersiz secim. Lutfen tekrar deneyin." << endl;
        }
    }

    return 0;
}

