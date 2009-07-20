//07233009 Adem Dedebali
#include <stdio.h>
#include <conio.h>
void main ()
{
	char cevap[11] = {"abcdeabcde"}; //Programýn içinde gömülü olan cevaplar tanýmlanmýþtýr
	char cevap2[11]; //Karþýlaþtýrma için kullanýlmýþtýr
	char dogrusayisi[10]; //Eðer 127 den büyük bir deðer olacaksa int olarak tanýmlanmalýdýr
							   //ancak bellekte boþuna yer kaplamamasý için char olarak tanýmladým
							   //Hangi soruya kaç kiþinin doðru cevap verdiðini sayan deðiþken
	int ogrenci = 0;  //Kaç öðrenciye bakýldýðýný gösteren deðiþken
	int dogru; //Her bir öðrencinin doðru ve yanlýþlarýný sayan deðiþken
	int i = 0; //Döngü deðiþkeni
	char dongucevap = 'e'; //En dýþ döngünün deðiþkeni. h olmadýðý sürece döngüye girecek
	for (i=0; i<10; i++) 
		dogrusayisi[i] = 0; //Dizinin her elemaný 0'a eþitlenmiþtir
	for (;;) //Sonsuz döngü
	{
		ogrenci++; // Öðrenci sayýsý bir artýrýlýr
		dogru = 0; // Öðrencinin doðru ve yanlýþ adetleri 0'a eþitlenir
		for (i=0; i<10; i++) //Öðrencinin her bir soruya verdiði cevabý almak için kurulan döngü
		{
			printf ("%2d. soru:", i+1); // Kaçýncý soruda olduðumuzu gösterir
			cevap2[i] = getche (); // Ýþlemin hýzlý olmasý açýsýndan cevabý entere basmadan getche() fonksiyonu alýr
			printf ("\n");
			if (cevap[i] == cevap2[i]) // Gömülü olan cevapla öðrencinin cevabý karþýlaþtýrýlýr. Eþitse:
			{
				dogru++; // Öðrencinin doðru sayýsý 1 artýrýlýr
				dogrusayisi[i]++; // Genel olarak bu soruya verilen doðru cevaba 1 eklenir
			}
		}
		printf ("\n");
		printf ("Dogru : %d\n", dogru); // Doðru sayisi yazdýrýlýr
		printf ("Yanlis: %d\n", 10 - dogru); //Yanlýþ sayýsý yazdýrýlýr. Soru sayýsý deðiþirse 10 deðeri deðiþtirmelidir
		printf ("Baska ogrenci girecek misiniz(e/h):");
		dongucevap = getche (); // Cevap getche () fonksiyonuna aktarýlýr
		printf ("\n");
		if (dongucevap == 'h' || dongucevap == 'H') 
			break; // Döngü sonsuz kurulduðu için cevabýn H olmasý durumunda döngüden atar
	}
	printf ("_______________________________\n");
	printf ("%d ogrencinin sonucuna baktiniz...\n", ogrenci); 
	printf ("Sorularin istatislik sonuclari:\n");
	for (i=0; i<10; i++) // Döngüyle sorularýn istatislik sonuçlarýna bakýlýr
		printf ("%2d. soruya %d ogrenci dogru, %d ogrenci yanlis cevap vermistir...\n", i+1, dogrusayisi[i], ogrenci - dogrusayisi[i]);
}
