/**
* @file Dugum.hpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef Dugum_hpp
#define Dugum_hpp

#include "Sayi.hpp"

//dugum sınıfı tanımı
class Dugum {
public:
    Sayi* sayi;           // dugum içindeki Sayi nesnesinin işaretçisi
    Dugum* sonraki_dugum;  // sonraki dugumun işaretçisi

    //kurucu fonksiyon
    Dugum(Sayi* sayi);

    //yıkıcı fonksiyon
    ~Dugum();
};

#endif
