//07233009 Adem Dedebali
#include <stdio.h>
#include <math.h>   //sqrt() fonksiyonu i�in
void giris (int no[], int not[]); // fonksiyon prototipleri
float ortalama (int not[]);  //d�nd�rd��� de�ere g�re tan�mlan�r bu float d�nd�r�r
void goruntule (int no[], int not[]); //voidler de�er d�nd�rmez
void kucukaltmis (int no[], int not[]);
int adetkucukaltmis (int not[]);
int enbuyuk (int not[]);
int enkucuk (int not[]);
void sonuca_gore_sira (int no[], int not[]);
void noya_gore_sira (int no[], int not[]);
float standart_sapma (int not[]);

int N;
void main ()
{
	printf ("Ogrenci sayisini giriniz:");
	scanf ("%d", &N);
	int OgrNo[BUFSIZ], BNotu[BUFSIZ];
	giris (OgrNo, BNotu);
	goruntule (OgrNo, BNotu);
	printf ("Not ortalamasi: %5.2f\n", ortalama (BNotu));
	kucukaltmis (OgrNo, BNotu);
	printf ("\n60dan dusuk notlu ogrenci sayisi: %d\n", adetkucukaltmis (BNotu));
	printf ("\nEn yuksek not: %d\n", enbuyuk (BNotu));
	printf ("\nEn dusuk not: %d\n\n", enkucuk (BNotu));
	sonuca_gore_sira (OgrNo, BNotu);
	noya_gore_sira (OgrNo, BNotu);
	printf ("\nStandart Sapma : %6.2f\n", standart_sapma (BNotu));
}

void giris (int no[], int not[])
{
	int i;
	for (i=0; i<N; i++)
	{
		printf ("Ogrenci no gir:");
		scanf ("%d", &no[i]);
		printf ("%d numarali ogrencinin notunu gir:", no[i]);
		scanf ("%d", &not[i]);
	}
}

void goruntule (int no[], int not[])
{
	printf ("\nOgrenci#\tNotu\n");
	int i;
	for (i=0; i<N; i++)
		printf ("%8d\t%3d\n", no[i], not[i]);
	printf ("\n");
}

float ortalama (int not[])  //B�t�n notlar� al�p toplay�p ��renci say�s�na b�len ve 
{							//buldu�u de�eri d�nd�ren fonksiyon
	float t;
	int i;
	t = 0;
	for (i=0; i<N; i++)
		t = t + not[i];
	return t / N;
}

void kucukaltmis (int no[], int not[])  //Numaralar� ve notlar� al�p 60dan dusuk notu olan
{										//ogrencileri numara + not yazd�ran fonksiyon
	int i;
	printf ("\nNotu 60dan kucuk olan ogrenciler:\n");
	printf ("No\tNot\n");
	for (i=0; i<N; i++)
		if (not[i] < 60)
			printf ("%d\t%d\n", no[i], not[i]);
}

int adetkucukaltmis (int not[])  //60dan dusuk not alan ogrenci say�s�n� bulan ve
{								//buldu�u de�eri d�nd�ren fonksiyon
	int i,s=0;
	for (i=0; i<N; i++)
		if (not[i] < 60)
			s++;
	return s;
}

int enbuyuk (int not[])		//Notlar� al�p en yuksek notu belirleyen ve buldu�u de�eri
{							//donduren fonksiyon
	int i, eb;
	eb = not[0];
	for (i=1; i<N; i++)
		if (not[i] > eb)
			eb = not[i];
	return eb;
}

int enkucuk (int not[])	   //Notlar� al�p en dusuk notu belirler ve buldu�u de�eri
{							//dondurur
	int i, ek;
	ek = not[0];
	for (i=1; i<N; i++)
		if (not[i] < ek)
			ek = not[i];
	return ek;
}

void sonuca_gore_sira (int no[], int not[])  //Numaralar� ve notlar� al�p notlara gore kucukten buyuge
{											 //s�ralayan ve ogrenci numaralar�yla g�steren fonksiyon
											 //Notlarla beraber ogrenci numaralar�n�n da yerleri de�i�ir
											 //ve tam kar��l�klar�na oturtulur. Bubble sort s�ralama y�ntemi
											 //ile yap�lm��t�r
	printf ("\nNotlara gore kucukten buyuge siralama:\n");
	int i,j, gecis;
	for (i=0; i<N-1; i++)
		for (j=i+1; j<N; j++)
			if (not[j] < not[i])
			{
				gecis = not[i];
				not[i] = not[j];
				not[j] = gecis;

				gecis = no[i];
				no[i] = no[j];
				no[j] = gecis;
			}
	for (i=0; i<N; i++)
		printf ("Not: %3d,  No:%d\n", not[i], no[i]);
}

void noya_gore_sira (int no[], int not[])  //Yukar�daki fonksiyonla ayn� mant�ktad�r ve bu sefer ogrenci
{										   //numaralar�na g�re s�ralar.
	printf ("\nNumaraya gore kucukten buyuge siralama:\n");
	int i,j, gecis;
	for (i=0; i<N-1; i++)
		for (j=i+1; j<N; j++)
			if (no[j] < no[i])
			{
				gecis = no[i];
				no[i] = no[j];
				no[j] = gecis;

				gecis = not[i];
				not[i] = not[j];
				not[j] = gecis;
			}
	for (i=0; i<N; i++)
		printf ("Ogr No: %d,  Not:%d\n", no[i], not[i]);
}

float standart_sapma (int not[])   //Standart sapmay� bulan ve buldu�u de�eri d�nd�ren fonksiyon
{								   //bu fonksiyonun i�inde ortalama fonksiyonuna gidilir ve ortalama
								   //al�n�r. Sonra ortalamadan herhangi bir not ��kar�larak karesi al�n�r
								   // ve b�t�n notlar i�in bu i�lem yap�larak hepsi birbirine eklenir.
								   //daha sonra ogrenci say�s�na b�l�n�r ve karek�k� al�n�r. Bulunan float
								   //de�er d�nd�r�l�r
	int i;
	float ort;
	float ss=0;
	ort = ortalama (not);
	for (i=0; i<N; i++)
		ss = (float) ss + (ort - not[i]) * (ort - not[i]);
	ss = ss / N;
	ss = (float)pow (ss, 0.5);
	return ss;
}
