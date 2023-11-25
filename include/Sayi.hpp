/**
* @file Sayi.hpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef Sayi_hpp
#define Sayi_hpp

#include "Basamak.hpp"

//sayi sınıfı tanımı
class Sayi {
public:
    Basamak* birler;  //birler basamağının işaretçisi
    Basamak* son;     //son basamağın işaretçisi

    //kurucu fonksiyon
    Sayi();

    //yıkıcı fonksiyon
    ~Sayi();

    //basamak ekleme fonksiyonu
    void ekle_basamak(int deger);

    //tek basamakları taşıma fonksiyonu
    void tek_basamaklari_tasi();

    //yer değiştirme fonksiyonu
    void yer_degistirme();

    //sayı değerini hesaplama fonksiyonu
    int sayi_degeri_hesapla();
};

#endif
