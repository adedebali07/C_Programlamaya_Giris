// 07233009 Adem Dedebali
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main ()
{
	char i, s, eb, j;	//bellekte çok yer kaplamamasý için char olarak  tanýmladým.
	char hazne[11];		//128den büyük deðeri olabilecek deðiþken olmadýðý için
	srand (time (NULL));//rand fonksiyonunun esas alacaðý deðer sistem saati

	for(i=0; i<10; i++) //bütün haznelerin deðerini 0'a eþitledim
		hazne[i] = 0;

	for(i=0; i<50; i++)	//50 jetonu atan döngü. Deðeri ne çýkarsa o kutunun deðeri 1 artar
	{
		s = (rand() % 10) + 1;
		hazne[s-1]++;
	}

	for(i=0; i<10; i++) //Haznelerin deðerini yazdýran döngü
		printf ("%2d. hazne: %d\n", i+1, hazne[i]);
	
	eb = hazne[0]; //grafikte gerekli olduðu için en çok jetonun düþtüðü hazneyi buluruz
	for (i=1; i<10; i++) 
		if (hazne[i] > eb)
			eb = hazne[i];

	printf ("\nJetonlarin histogram seklinde dagilimlari:\n\n");

	for (i=eb; i>0; i--) //grafik en çok jeton düþen hazneden baþlar
	{
		printf ("%2d|", i);
		for (j=0; j<10; j++) //bütün hazneler her satýr için taranýr
		{
			if (hazne[j] >= i)// eðer jeton sayýsýna eþitse " o |" stringi basýlýr
				printf (" o |");
			else
				printf ("   |");
		}
		printf ("\n");
	}

	printf ("--+"); //görsellik açýsýndan bu string yazýlýr
	for (i=1; i<11; i++) //grafiðin altýna çizgi çekilir
		printf ("---+");

	printf ("\n");
	printf ("  |");

	for (i=1; i<11; i++)
		printf ("%2d |", i);

	printf ("\n");
}