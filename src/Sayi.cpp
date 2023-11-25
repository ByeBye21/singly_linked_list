/**
* @file Sayi.cpp
* @description Tek Yönlü Bağlı Listeler Kullanarak Tam Sayılar Üzerinde Çeşitli İşlemler Yapılıyor
* @course 1.Öğretim B Grubu
* @assignment 1.Ödev
* @date 2023/11/25
* @author Younes Rahebi | younes0079@gmail.com
*/

#include "Sayi.hpp"

//sayi sınıfının kurucu fonksiyonu
Sayi::Sayi() : birler(nullptr), son(nullptr) {}

//sayi sınıfının yıkıcı fonksiyonu
Sayi::~Sayi() {}

//yeni bir basamak ekleme fonksiyonu
void Sayi::ekle_basamak(int deger) {
    if (birler == nullptr) {
        birler = new Basamak(deger);
        son = birler;
    }
    else {
        son->sonraki = new Basamak(deger);
        son = son->sonraki;
    }
}

//tek basamakları taşıma fonksiyonu
void Sayi::tek_basamaklari_tasi() {
    if (birler == nullptr) {
        return;
    }

    Basamak* head = nullptr;
    Basamak* tail = nullptr;
    Basamak* current = birler;
    Basamak* prev = nullptr;

    while (current != nullptr) {
        if (current->deger % 2 != 0) {
            if (prev != nullptr) {
                prev->sonraki = current->sonraki;
            }
            else {
                birler = current->sonraki;
            }

            if (head == nullptr) {
                head = current;
                tail = current;
            }
            else {
                tail->sonraki = current;
                tail = current;
            }

            current = current->sonraki;
            tail->sonraki = nullptr;
        }
        else {
            prev = current;
            current = current->sonraki;
        }
    }

    if (tail != nullptr) {
        tail->sonraki = birler;
        birler = head;
    }
}

//basamakları yer değiştirme fonksiyonu
void Sayi::yer_degistirme() {
    if (birler == nullptr) {
        return;
    }

    Basamak* prev = nullptr;
    Basamak* current = birler;
    Basamak* next;

    while (current != nullptr) {
        next = current->sonraki;

        current->sonraki = prev;

        prev = current;
        current = next;
    }
    birler = prev;
}

//sayı değerini hesaplama fonksiyonu
int Sayi::sayi_degeri_hesapla() {
    int toplam = 0;
    Basamak* basamak_current = birler;
    while (basamak_current != nullptr) {
        toplam = toplam * 10 + basamak_current->deger;
        basamak_current = basamak_current->sonraki;
    }
    return toplam;
}
