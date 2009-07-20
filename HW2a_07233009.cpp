// 07233009 Adem Dedebali
#include <stdio.h> //kullan�lan printf() ve scanf() fonksiyonlar�n�n kay�tl� oldu�u header dosyas�n� aktif hale getirir.
#include <conio.h> //kullan�lan getche () fonksiyonunu bar�nd�ran conio.h programa dahil edilmi�tir.

void main ()
{ 
	char c; //program�n devam sorgusu i�in c karakteri kullan�lm��t�r
	c = 'e'; //bu sat�r� kullanmazsak program while d�ng�s�ne girmez ve hemen sonlan�r.
	while (c == 'e') //while d�ng�s� ile program�n istenildi�i taktirde s�rekli �al��mas� sa�lan�r.
	{ 
		int top, x, f; // toplama i�lemi i�in top, kullan�c�n�n girece�i x ve fakt�riyelde kullan�lacak f programa dahil edilmi�tir.
		top=0, f=1; // top de�i�kenine 0, f de�i�kenine 1 de�eri aktar�lm��t�r.
		printf ("Lutfen bir sayi giriniz:"); //Ekranda L�tfen bir sayi giriniz yazmas� sa�lanm��t�r.
		scanf ("%d", &x); // Kullan�c�n�n girdi�i de�er x de�i�kenine aktar�lm��t�r
		if (x >= 10) // Par�al� fonksiyona g�re x'in 10'dan b�y�k olmas� durumunda yap�lacak i�lemler belirtilmistir
		{
			for (; x>0; x--) // for d�ng�s� ile x de�eri 0 a e�it olana kadar her ad�mda 1 azalt�l�r
				top+=x; // top=top+x anlam�na gelir ve her seferinde toplama 1 azalt�lm�� olan x de�erini ekler
			printf ("Sayilarin Toplami: %d\n", top); //Bulunan toplam sonucu ekrana yaz�l�r 
		}
		else if (x >= 0 && x <= 9) // Fonksiyona g�re x'in 10dan k���k ve 0a b�y�k e�it oldu�u durumda yap�lacak i�lemleri g�sterir
		{
			for (; x>0; x--) // x 0dan b�y�k oldu�u s�rece x i her bir d�n��te 1 azalt�r. x o iken d�ng� d�nmez fakat f 1 olarak tan�mland��� i�in sonu� 1 olur
				f=f*x; // Her seferinde 1 azalt�lm�� olan x f ile �arp�l�r
			printf ("Faktoriyel: %d\n", f); // bulunan sonu� ekrana yazd�r�l�r.
		}
		else if (x < 0) // x 0 dan k���k oldu�u zaman yap�lacak i�lemler s�ralan�r
			printf ("Lutfen negatif sayi girmeyiniz...\n"); // Ekrana uyar� yazd�r�l�r
		printf ("Devam etmek istiyor musunuz e/h:"); // Devam ko�ulu kullan�c�ya sorulur. h g�rsel olmas� i�in yaz�lm��t�r. e d���ndaki her cevap program� sonland�r�r.
		scanf ("%c", &c); // Kullan�c�n�n cevab� c de�i�kenine aktar�l�r
		c = getche (); // c de�i�keni de getche() fonksiyonuna aktar�l�r
		printf ("\n"); //program�n g�rsel olmas� a��s�ndan 1 sat�r a�a�� inilmesi belirtilir
	}
}