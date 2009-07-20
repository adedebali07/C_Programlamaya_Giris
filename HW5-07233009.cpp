// 07233009 Adem Dedebali
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main ()
{
	char i, s, eb, j;	//bellekte �ok yer kaplamamas� i�in char olarak  tan�mlad�m.
	char hazne[11];		//128den b�y�k de�eri olabilecek de�i�ken olmad��� i�in
	srand (time (NULL));//rand fonksiyonunun esas alaca�� de�er sistem saati

	for(i=0; i<10; i++) //b�t�n haznelerin de�erini 0'a e�itledim
		hazne[i] = 0;

	for(i=0; i<50; i++)	//50 jetonu atan d�ng�. De�eri ne ��karsa o kutunun de�eri 1 artar
	{
		s = (rand() % 10) + 1;
		hazne[s-1]++;
	}

	for(i=0; i<10; i++) //Haznelerin de�erini yazd�ran d�ng�
		printf ("%2d. hazne: %d\n", i+1, hazne[i]);
	
	eb = hazne[0]; //grafikte gerekli oldu�u i�in en �ok jetonun d��t��� hazneyi buluruz
	for (i=1; i<10; i++) 
		if (hazne[i] > eb)
			eb = hazne[i];

	printf ("\nJetonlarin histogram seklinde dagilimlari:\n\n");

	for (i=eb; i>0; i--) //grafik en �ok jeton d��en hazneden ba�lar
	{
		printf ("%2d|", i);
		for (j=0; j<10; j++) //b�t�n hazneler her sat�r i�in taran�r
		{
			if (hazne[j] >= i)// e�er jeton say�s�na e�itse " o |" stringi bas�l�r
				printf (" o |");
			else
				printf ("   |");
		}
		printf ("\n");
	}

	printf ("--+"); //g�rsellik a��s�ndan bu string yaz�l�r
	for (i=1; i<11; i++) //grafi�in alt�na �izgi �ekilir
		printf ("---+");

	printf ("\n");
	printf ("  |");

	for (i=1; i<11; i++)
		printf ("%2d |", i);

	printf ("\n");
}