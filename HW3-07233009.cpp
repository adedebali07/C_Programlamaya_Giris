//07233009 Adem Dedebali
#include <stdio.h>
#include <conio.h>
void main ()
{
	char cevap[11] = {"abcdeabcde"}; //Program�n i�inde g�m�l� olan cevaplar tan�mlanm��t�r
	char cevap2[11]; //Kar��la�t�rma i�in kullan�lm��t�r
	char dogrusayisi[10]; //E�er 127 den b�y�k bir de�er olacaksa int olarak tan�mlanmal�d�r
							   //ancak bellekte bo�una yer kaplamamas� i�in char olarak tan�mlad�m
							   //Hangi soruya ka� ki�inin do�ru cevap verdi�ini sayan de�i�ken
	int ogrenci = 0;  //Ka� ��renciye bak�ld���n� g�steren de�i�ken
	int dogru; //Her bir ��rencinin do�ru ve yanl��lar�n� sayan de�i�ken
	int i = 0; //D�ng� de�i�keni
	char dongucevap = 'e'; //En d�� d�ng�n�n de�i�keni. h olmad��� s�rece d�ng�ye girecek
	for (i=0; i<10; i++) 
		dogrusayisi[i] = 0; //Dizinin her eleman� 0'a e�itlenmi�tir
	for (;;) //Sonsuz d�ng�
	{
		ogrenci++; // ��renci say�s� bir art�r�l�r
		dogru = 0; // ��rencinin do�ru ve yanl�� adetleri 0'a e�itlenir
		for (i=0; i<10; i++) //��rencinin her bir soruya verdi�i cevab� almak i�in kurulan d�ng�
		{
			printf ("%2d. soru:", i+1); // Ka��nc� soruda oldu�umuzu g�sterir
			cevap2[i] = getche (); // ��lemin h�zl� olmas� a��s�ndan cevab� entere basmadan getche() fonksiyonu al�r
			printf ("\n");
			if (cevap[i] == cevap2[i]) // G�m�l� olan cevapla ��rencinin cevab� kar��la�t�r�l�r. E�itse:
			{
				dogru++; // ��rencinin do�ru say�s� 1 art�r�l�r
				dogrusayisi[i]++; // Genel olarak bu soruya verilen do�ru cevaba 1 eklenir
			}
		}
		printf ("\n");
		printf ("Dogru : %d\n", dogru); // Do�ru sayisi yazd�r�l�r
		printf ("Yanlis: %d\n", 10 - dogru); //Yanl�� say�s� yazd�r�l�r. Soru say�s� de�i�irse 10 de�eri de�i�tirmelidir
		printf ("Baska ogrenci girecek misiniz(e/h):");
		dongucevap = getche (); // Cevap getche () fonksiyonuna aktar�l�r
		printf ("\n");
		if (dongucevap == 'h' || dongucevap == 'H') 
			break; // D�ng� sonsuz kuruldu�u i�in cevab�n H olmas� durumunda d�ng�den atar
	}
	printf ("_______________________________\n");
	printf ("%d ogrencinin sonucuna baktiniz...\n", ogrenci); 
	printf ("Sorularin istatislik sonuclari:\n");
	for (i=0; i<10; i++) // D�ng�yle sorular�n istatislik sonu�lar�na bak�l�r
		printf ("%2d. soruya %d ogrenci dogru, %d ogrenci yanlis cevap vermistir...\n", i+1, dogrusayisi[i], ogrenci - dogrusayisi[i]);
}
