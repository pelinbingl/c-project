
#include <iostream>
#include <string>
using namespace std;
class Hasta {
public:
    string ad_soyad;
    int yas;
    Hasta* next; // Bir sonraki düðüme iþaret eden pointer
};

class Doktor {
public:
    std::string ad;
    std::string uzmanlik;
    Doktor* next; // Bir sonraki düðüme iþaret eden pointer
};
class HastaneOtomasyonu {
public:
    Hasta* hastaBas = nullptr;   // Hasta linked list baþlangýcý
    Doktor* doktorBas = nullptr; // Doktor linked list baþlangýcý

    // Hasta ekleme fonksiyonu
    void hastaEkle(std::string ad, int yas) {
        Hasta* yeniHasta = new Hasta;
        yeniHasta->ad_soyad = ad;
        yeniHasta->yas = yas;
        yeniHasta->next = hastaBas;
        hastaBas = yeniHasta;
    }

    // Doktor ekleme fonksiyonu
    void doktorEkle(std::string ad, std::string uzmanlik) {
        Doktor* yeniDoktor = new Doktor;
        yeniDoktor->ad = ad;
        yeniDoktor->uzmanlik = uzmanlik;
        yeniDoktor->next = doktorBas;
        doktorBas = yeniDoktor;
    }

    // Hasta listesini yazdýrma fonksiyonu
    void hastaListesiYazdir() {
        Hasta* temp = hastaBas;
        while (temp != nullptr) {
            cout << "Hasta Adi: " << temp->ad_soyad << ", Yasi: " << temp->yas << endl;
            temp = temp->next;
        }
    }

    // Doktor listesini yazdýrma fonksiyonu
    void doktorListesiYazdir() {
        Doktor* temp = doktorBas;
        while (temp != nullptr) {
            cout << "Doktor Adi: " << temp->ad << ", Uzmanlik Alani: " << temp->uzmanlik << endl;
            temp = temp->next;
        }
    }
    Hasta* hastaAra(string ad) {
        Hasta* temp = hastaBas;
        while (temp != nullptr) {
            if (temp->ad_soyad == ad) {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr; // Hasta bulunamazsa nullptr döndürülür.
    }

    // Hasta düzenleme fonksiyonu
    bool hastaDuzenle(string eskiAd, string yeniAd, int yeniYas) {
        Hasta* hasta = hastaAra(eskiAd);
        if (hasta) {
            hasta->ad_soyad = yeniAd;
            hasta->yas = yeniYas;
            return true; // Düzenleme baþarýlý ise true döndürülür.
        }
        return false; // Hasta bulunamazsa false döndürülür.
    }

    // Hasta silme fonksiyonu
    bool hastaSil(string ad) {
        if (hastaBas == nullptr) {
            return false; // Liste boþsa silme iþlemi yapýlamaz.
        }

        // Ýlk düðümü silme durumu
        if (hastaBas->ad_soyad == ad) {
            Hasta* temp = hastaBas;
            hastaBas = hastaBas->next;
            delete temp;
            return true; // Silme baþarýlý ise true döndürülür.
        }

        // Diðer düðümleri silme durumu
        Hasta* prev = hastaBas;
        Hasta* current = hastaBas->next;
        while (current != nullptr) {
            if (current->ad_soyad == ad) {
                prev->next = current->next;
                delete current;
                return true; // Silme baþarýlý ise true döndürülür.
            }
            prev = current;
            current = current->next;
        }
        return false; // Hasta bulunamazsa false döndürülür.
    }
    // Yýkýcý fonksiyon
    ~HastaneOtomasyonu() {
        // Hasta linked list'i temizleme
        Hasta* currentHasta = hastaBas;
        while (currentHasta != nullptr) 
        {
            Hasta* nextHasta = currentHasta->next;
            delete currentHasta;
            currentHasta = nextHasta;
        }

        // Doktor linked list'i temizleme
        Doktor* currentDoktor = doktorBas;
        while (currentDoktor != nullptr) 
        {
            Doktor* nextDoktor = currentDoktor->next;
            delete currentDoktor;
            currentDoktor = nextDoktor;
        }
    }
};
int main() 
{
    HastaneOtomasyonu hastane;
    int secim;

    while (true)
    {
        cout << "\n-- Hastane Otomasyonu Menu --\n";
        cout << "1. Hasta Ekle\n";
        cout << "2. Doktor Ekle\n";
        cout << "3. Hasta Listesini Goster\n";
        cout << "4. Doktor Listesini Goster\n";
        cout << "5. Hasta Ara ve Duzenle\n";
        cout << "6. Hasta Sil\n";
        cout << "0. Cikis\n";
        cout << "Seciminiz: ";
        cin >> secim;

        if (secim == 1)
        {
            string ad;
            int yas;
            cout << "Hasta Adi: ";
            cin.ignore();
            getline(cin, ad);
            cout << "Hasta Yas: ";
            cin >> yas;
            hastane.hastaEkle(ad, yas);
        }
        else if (secim == 2)
        {
            string ad, uzmanlik;
            cout << "Doktor Adi: ";
            cin.ignore();
            getline(cin, ad);
            cout << "Doktor Uzmanlik: ";
            cin.ignore();
            getline(cin, uzmanlik);
            hastane.doktorEkle(ad, uzmanlik);
        }
        else if (secim == 3) { hastane.hastaListesiYazdir(); }
        else if (secim == 4) { hastane.doktorListesiYazdir(); }
        else if (secim == 5)
        {
            string aranacakHastaAdi;
            cout << "Aranacak Hasta Adi: ";
            cin.ignore();
            getline(cin, aranacakHastaAdi);
            Hasta* hasta = hastane.hastaAra(aranacakHastaAdi);
            if (hasta)
            {
                cout << "Hasta Adi: " << hasta->ad_soyad << ", Yas: " << hasta->yas << endl;

                string yeniAd;
                int yeniYas;
                cout << "Yeni Adi: ";
                getline(cin, yeniAd);
                cout << "Yeni Yas: ";
                cin >> yeniYas;
                hastane.hastaDuzenle(aranacakHastaAdi, yeniAd, yeniYas);
                cout << "Hasta bilgileri duzenlendi." << endl;
            }
            else { cout << "Hasta bulunamadi." << endl; }
        }
    }
}
