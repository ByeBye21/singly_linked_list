/**
* @file Sayilar_Listesi.cpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "Sayilar_Listesi.hpp"

using namespace std;

//sayilarListesi sınıfının kurucu fonksiyonu
Sayilar_Listesi::Sayilar_Listesi() : baslangic_dugumu(nullptr), son(nullptr) {}

//sayilarListesi sınıfının yıkıcı fonksiyonu
Sayilar_Listesi::~Sayilar_Listesi() {}

//yeni bir sayı ekleme fonksiyonu
void Sayilar_Listesi::ekle_sayi(Sayi* sayi) {
    Dugum* yeni_dugum = new Dugum(sayi);
    if (baslangic_dugumu == nullptr) {
        baslangic_dugumu = yeni_dugum;
        son = yeni_dugum;
    }
    else {
        son->sonraki_dugum = yeni_dugum;
        son = yeni_dugum;
    }
}

//en büyük sayıyı bulma fonksiyonu
Sayi* Sayilar_Listesi::en_buyuk_sayiyi_bul() {
    if (baslangic_dugumu == nullptr)
        return nullptr;

    Sayi* en_buyuk_sayi = baslangic_dugumu->sayi;
    int en_buyuk_deger = en_buyuk_sayi->sayi_degeri_hesapla();

    Dugum* dugum = baslangic_dugumu->sonraki_dugum;

    while (dugum != nullptr) {
        int dugum_degeri = dugum->sayi->sayi_degeri_hesapla();
        if (dugum_degeri > en_buyuk_deger) {
            en_buyuk_deger = dugum_degeri;
            en_buyuk_sayi = dugum->sayi;
        }
        dugum = dugum->sonraki_dugum;
    }
    return en_buyuk_sayi;
}

//en büyük sayıyı listeden çıkarma fonksiyonu
void Sayilar_Listesi::en_buyuk_sayiyi_listeden_cikar(Sayi* en_buyuk_sayi) {
    Dugum* current = baslangic_dugumu;
    Dugum* prev = nullptr;
    while (current != nullptr) {
        if (current->sayi == en_buyuk_sayi) {
            if (prev != nullptr) {
                prev->sonraki_dugum = current->sonraki_dugum;
            }
            else {
                baslangic_dugumu = current->sonraki_dugum;
            }

            Basamak* basamak_current = current->sayi->birler;
            while (basamak_current != nullptr) {
                Basamak* next_basamak = basamak_current->sonraki;
                delete basamak_current;
                basamak_current = next_basamak;
            }

            delete current->sayi;

            break;
        }
        prev = current;
        current = current->sonraki_dugum;
    }
    if (current == son) {
        son = prev;
    }
    if (current != nullptr)
        delete current;
}

//belleği temizleme fonksiyonu
void Sayilar_Listesi::bellek_temizle() {
    Dugum* current = baslangic_dugumu;
    while (current != nullptr) {
        Dugum* silinecek_dugum = current;
        current = current->sonraki_dugum;

        Basamak* basamak_current = silinecek_dugum->sayi->birler;
        while (basamak_current != nullptr) {
            Basamak* silinecek_basamak = basamak_current;
            basamak_current = basamak_current->sonraki;
            delete silinecek_basamak;
        }
        delete silinecek_dugum->sayi;
        delete silinecek_dugum;
    }
    delete this;
}

//dosyadan sayıları okuma fonksiyonu
void Sayilar_Listesi::dosyadan_sayilari_oku() {
    ifstream dosya("Sayilar.txt");
    if (dosya.is_open()) {
        string satir;
        while (getline(dosya, satir)) {
            istringstream ss(satir);
            string temp;
            while (ss >> temp) {
                Sayi* sayi = new Sayi();
                for (char c : temp) {
                    if (isdigit(c)) {
                        int rakam = c - '0';
                        sayi->ekle_basamak(rakam);
                    }
                }
                ekle_sayi(sayi);
            }
        }
        dosya.close();
    }
}

//sayıları listeleme fonksiyonu
void Sayilar_Listesi::yazdir_sayilar_listesi() {
    Dugum* current = baslangic_dugumu;

    while (current != nullptr) {
        cout.width(16);
        cout << left << current->sayi;

        cout.width(4);
        cout << right << '|';

        Basamak* basamak_current = current->sayi->birler;
        while (basamak_current != nullptr) {
            cout.width(6);
            stringstream ss;
	    	ss << hex << reinterpret_cast<uintptr_t>(basamak_current);
            string ptr_string(ss.str());
 	        string son_uc = ptr_string.substr(ptr_string.size() - 3);
  	      	cout << son_uc;
            cout.width(4);
            cout << right << '|';
            basamak_current = basamak_current->sonraki;
        }

        cout << "\n--------------------------------------------------------------------------------------------------------------------------\n";

        int i{ 16 };
        basamak_current = current->sayi->birler;
        while (basamak_current != nullptr) {
            cout << basamak_current->deger;
            basamak_current = basamak_current->sonraki;
            i--;
        }

        cout.width(i);
        cout << " ";

        cout.width(4);
        cout << right << '|';

        basamak_current = current->sayi->birler;
        while (basamak_current != nullptr) {
            cout.width(6);
            cout << right << basamak_current->deger;
            cout.width(4);
            cout << right << '|';
            basamak_current = basamak_current->sonraki;
        }

        cout << "\n\n##########################################################################################################################\n\n";

        current = current->sonraki_dugum;
    }
}
