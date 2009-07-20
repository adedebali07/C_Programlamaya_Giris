// 07233009 Adem Dedebali
#include <stdio.h>
#include <time.h> //time() fonksiyonu için kullanýlmýþtýr
#include <stdlib.h> // srand() ve rand() fonksiyonlarý için kullanýlmýþtýr
#include <conio.h> // getch() fonksiyonu için kullanýlmýþtýr

void main ()
{
	int kurbaga[20]; // Kurbagalarýn konumunu belirten deðiþken
	int i,j,t, atlayis = 0; //döngü deðiþkenleri ve atlayýþ sayacý
	char finishbayragi = 'f'; // Herhangi bir kurbaga 1. gelince yarýþý sonlandýracak döngü deðiþkeni
	for (i=0; i<20; i++) //Bütün kurbagalar 1. havuza konulur
		kurbaga[i] = 1;
	srand (time(NULL)); //rand() fonksiyonunun esas alacaðý srand() fonksiyonu sistem saatine eþitlenir
	while (finishbayragi == 'f') // Bayrak kalkana kadar yarýþ devam edecektir
	{
		atlayis++; //Atlayýþ 1 artýrýlýr
		printf ("%d. Atlayis:\n", atlayis);
		getch();
		for (i=0; i<20; i++) //Bütün kurbaðalarýn rand() fonksiyonu ile ne kadar atlayacaðý belirlenir
		{
			if (kurbaga[i] < 8) //Eðer 8. havuzun gerisindeyse 1,2 veya 3 atlayis yapabilir
				kurbaga[i] = kurbaga[i] + (rand() % 3 + 1); //Atlama deðerinin 0 olmamasý için 1 eklenir
			else if (kurbaga[i] == 8) // Eðer 8. havuzdaysa 1 veya 2 atlayis yapabilir
				kurbaga[i] = kurbaga[i] + (rand() % 2 + 1);
			else // 10. havuzdaysa zaten döngü sonlanacak. Yani 9. havuzda 1 atlayis daha yapar
				kurbaga[i] += 1;
		}
		printf ("            "); // Görsellik açýsýndan biraz boþluk býrakýlýr
		for (j=1; j<21; j++) // Her bir kurbaganýn numarasý tabloya eklenir
			printf ("%-2d ", j);
		printf ("\n");
		for (t=1; t<11; t++) //Bütün havuzlarý tabloya eklemek için döngü açýlýr
		{	
			printf ("%2d. Havuz:  ", t); //Kaçýncý havuz olduðu yazýlýr
			for (j=0; j<20; j++) // Bütün kurbagalarýn deðerlerini sýnamak için döngü açýlýr
				if (kurbaga[j] == t) // Eðer kurbaða bu havuzdaysa & yazýlýr
					printf ("&  "); // Kurbaða numarasý ile altalta gelmesi için 2 de boþluk býrakýlýr
				else // Bu havuzda deðilse
					printf ("|  "); // | iþareti yazýlýr.
			printf ("\n");
		}
		for (i=0; i<20; i++) //Bütün kurbaðalar için
			if (kurbaga[i] == 10) //eðer 10. havuzda olan varsa
				finishbayragi = 'k'; //finish bayraðý kalkar ve yarýþ biter
		printf ("\n");
	}
	printf ("\n");
	printf ("Birinci gelen kurbaga(lar)\n");
	printf ("--------------------------\n");
	for (j=0; j<20; j++)
	{
		if (kurbaga[j] == 10) //Ve de 1. gelen kurbagalar ekrana yazdýrýlýr
			printf ("%d. ", j+1);
	}
	printf ("\n");
}
