/**
* @file Basamak.cpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "Basamak.hpp"

//basamak sınıfının kurucu fonksiyonu
Basamak::Basamak(int deger) : deger(deger), sonraki(nullptr) {}

//basamak sınıfının yıkıcı fonksiyonu
Basamak::~Basamak() {}
