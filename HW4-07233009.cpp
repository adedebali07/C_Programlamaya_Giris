// 07233009 Adem Dedebali
#include <stdio.h>
#include <time.h> //time() fonksiyonu i�in kullan�lm��t�r
#include <stdlib.h> // srand() ve rand() fonksiyonlar� i�in kullan�lm��t�r
#include <conio.h> // getch() fonksiyonu i�in kullan�lm��t�r

void main ()
{
	int kurbaga[20]; // Kurbagalar�n konumunu belirten de�i�ken
	int i,j,t, atlayis = 0; //d�ng� de�i�kenleri ve atlay�� sayac�
	char finishbayragi = 'f'; // Herhangi bir kurbaga 1. gelince yar��� sonland�racak d�ng� de�i�keni
	for (i=0; i<20; i++) //B�t�n kurbagalar 1. havuza konulur
		kurbaga[i] = 1;
	srand (time(NULL)); //rand() fonksiyonunun esas alaca�� srand() fonksiyonu sistem saatine e�itlenir
	while (finishbayragi == 'f') // Bayrak kalkana kadar yar�� devam edecektir
	{
		atlayis++; //Atlay�� 1 art�r�l�r
		printf ("%d. Atlayis:\n", atlayis);
		getch();
		for (i=0; i<20; i++) //B�t�n kurba�alar�n rand() fonksiyonu ile ne kadar atlayaca�� belirlenir
		{
			if (kurbaga[i] < 8) //E�er 8. havuzun gerisindeyse 1,2 veya 3 atlayis yapabilir
				kurbaga[i] = kurbaga[i] + (rand() % 3 + 1); //Atlama de�erinin 0 olmamas� i�in 1 eklenir
			else if (kurbaga[i] == 8) // E�er 8. havuzdaysa 1 veya 2 atlayis yapabilir
				kurbaga[i] = kurbaga[i] + (rand() % 2 + 1);
			else // 10. havuzdaysa zaten d�ng� sonlanacak. Yani 9. havuzda 1 atlayis daha yapar
				kurbaga[i] += 1;
		}
		printf ("            "); // G�rsellik a��s�ndan biraz bo�luk b�rak�l�r
		for (j=1; j<21; j++) // Her bir kurbagan�n numaras� tabloya eklenir
			printf ("%-2d ", j);
		printf ("\n");
		for (t=1; t<11; t++) //B�t�n havuzlar� tabloya eklemek i�in d�ng� a��l�r
		{	
			printf ("%2d. Havuz:  ", t); //Ka��nc� havuz oldu�u yaz�l�r
			for (j=0; j<20; j++) // B�t�n kurbagalar�n de�erlerini s�namak i�in d�ng� a��l�r
				if (kurbaga[j] == t) // E�er kurba�a bu havuzdaysa & yaz�l�r
					printf ("&  "); // Kurba�a numaras� ile altalta gelmesi i�in 2 de bo�luk b�rak�l�r
				else // Bu havuzda de�ilse
					printf ("|  "); // | i�areti yaz�l�r.
			printf ("\n");
		}
		for (i=0; i<20; i++) //B�t�n kurba�alar i�in
			if (kurbaga[i] == 10) //e�er 10. havuzda olan varsa
				finishbayragi = 'k'; //finish bayra�� kalkar ve yar�� biter
		printf ("\n");
	}
	printf ("\n");
	printf ("Birinci gelen kurbaga(lar)\n");
	printf ("--------------------------\n");
	for (j=0; j<20; j++)
	{
		if (kurbaga[j] == 10) //Ve de 1. gelen kurbagalar ekrana yazd�r�l�r
			printf ("%d. ", j+1);
	}
	printf ("\n");
}
