/**
* @file Basamak.hpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#ifndef Basamak_hpp
#define Basamak_hpp

//basamak sınıfı tanımı
class Basamak {
public:
    int deger;        //basamak değeri
    Basamak* sonraki;  //sonraki basamakın işaretçisi

    //kurucu fonksiyon
    Basamak(int deger);

    //yıkıcı fonksiyon
    ~Basamak();
};

#endif
