/**
* @file main.cpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "Sayilar_Listesi.hpp"
#include "Sayi.hpp"
#include <iostream>

using namespace std;

int main() {
    Sayilar_Listesi* sayilar_listesi = new Sayilar_Listesi();

    //dosyadan sayıları oku
    sayilar_listesi->dosyadan_sayilari_oku();

    //sayıları listele
    sayilar_listesi->yazdir_sayilar_listesi();

    bool devam = true;
    while (devam) {
        char secim;
        cout << "1. Tek Basamaklari Basa Al\n2. Basamaklari Tersle\n3. En Buyuk Cikar\n4. Cikis" << endl;
        cout << "Seciminiz: ";
        cin >> secim;

        switch (secim) {
        case '1':
            //her bir düğümdeki sayının tek basamakları taşı
            for (Dugum* d = sayilar_listesi->baslangic_dugumu; d != nullptr; d = d->sonraki_dugum)
                d->sayi->tek_basamaklari_tasi();
            sayilar_listesi->yazdir_sayilar_listesi();
            cout << endl;
            break;
        case '2':
            //her bir düğümdeki sayının basamaklarını tersle
            for (Dugum* d = sayilar_listesi->baslangic_dugumu; d != nullptr; d = d->sonraki_dugum)
                d->sayi->yer_degistirme();
            sayilar_listesi->yazdir_sayilar_listesi();
            cout << endl;
            break;
        case '3': {
            //en büyük sayıyı bul ve listeden çıkar
            Sayi* en_buyuk_sayi = sayilar_listesi->en_buyuk_sayiyi_bul();
            sayilar_listesi->en_buyuk_sayiyi_listeden_cikar(en_buyuk_sayi);
            sayilar_listesi->yazdir_sayilar_listesi();
            cout << endl;
            break;
        }
        case '4':
            //belleği temizle ve programı sonlandır
            sayilar_listesi->bellek_temizle();
            devam = false;
            break;
        default:
            cout << "\nGecersiz Secenek\n" << endl;
            break;
        }
    }

    return 0;
}
