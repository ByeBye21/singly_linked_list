hepsi: derle calistir

derle:
	g++ -I ./include/ -o ./lib/Basamak.o -c ./src/Basamak.cpp
	g++ -I ./include/ -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include/ -o ./lib/Sayi.o -c ./src/Sayi.cpp
	g++ -I ./include/ -o ./lib/Sayilar_Listesi.o -c ./src/Sayilar_Listesi.cpp
	g++ -I ./include/ -o ./bin/Test ./lib/Basamak.o ./lib/Dugum.o ./lib/Sayi.o ./lib/Sayilar_Listesi.o ./src/main.cpp

calistir:
	./bin/Test