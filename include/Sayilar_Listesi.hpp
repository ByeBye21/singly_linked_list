/**
* @file Sayilar_Listesi.hpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef Sayilar_Listesi_hpp
#define Sayilar_Listesi_hpp

#include "Dugum.hpp"
#include "Sayi.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

//Sayilar_Listesi sınıfı tanımı
class Sayilar_Listesi {
public:
    Dugum* baslangic_dugumu;  //başlangıç düğümünün işaretçisi
    Dugum* son;              //son düğümün işaretçisi

    //kurucu fonksiyon
    Sayilar_Listesi();

    //yıkıcı fonksiyon
    ~Sayilar_Listesi();

    //sayı ekleme fonksiyonu
    void ekle_sayi(Sayi* sayi);

    //en büyük sayıyı bulma fonksiyonu
    Sayi* en_buyuk_sayiyi_bul();

    //en büyük sayıyı listeden çıkarma fonksiyonu
    void en_buyuk_sayiyi_listeden_cikar(Sayi* en_buyuk_sayi);

    //belleği temizleme fonksiyonu
    void bellek_temizle();

    //dosyadan sayıları okuma fonksiyonu
    void dosyadan_sayilari_oku();

    //sayıları listeleme fonksiyonu
    void yazdir_sayilar_listesi();
};

#endif
