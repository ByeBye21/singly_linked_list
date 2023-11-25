/**
* @file Dugum.cpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "Dugum.hpp"

//dugum sınıfının kurucu fonksiyonu
Dugum::Dugum(Sayi* sayi) : sayi(sayi), sonraki_dugum(nullptr) {}

//dugum sınıfının yıkıcı fonksiyonu
Dugum::~Dugum() {}
