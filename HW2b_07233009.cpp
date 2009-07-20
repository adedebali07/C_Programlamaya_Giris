// 07233009 Adem Dedebali
#include <stdio.h> //header dosyas� programa dahil edilir
void main ()
{
	int n, i, j, a, s; // n girilen sayi, i ve j d�ng� de�i�kenleri, a break komutu i�in, s de saya� i�in kullan�lm��t�r
	s=0; // Sayaca 0 de�eri verilir
	printf ("Lutfen bir sayi giriniz:"); // Ekrana say� girilmesi istendi�i yaz�l�r
	scanf ("%d", &n); // Girilen de�er n de�i�kenine aktar�l�r
	if (n < 2) // Asal say�lar 2 den ba�lad���ndan 2 den k���k say�lar elenir.
		printf ("Asal sayilar 2'den baslar...\n"); //Kullan�c�ya uyar� verilir
	for (i=2; i<=n; i++) // Burada 2 den ba�lan�p n e kadar olan b�t�n say�lar tek tek kendisinden k���k olan say�lara
						 // b�l�necektir. ��i�e 2 d�ng� ile yap�lacak bu i�lemin ilk d�ng�s� budur.
	{
		a=1; // Asal olmayan say�n�n atlanmas� i�in a de�i�keni kullan�lm��t�r. Modu 0'a e�it olan say�da a 0'a e�itlenecek
			 // ve printf fonksiyonu sadece a'n�n 1 oldu�u durumda devreye girece�inden ekrana yaz�lmayacakt�r
		for (j=2; j<i; j++) // i yi kendisinden k���k olan say�lara tek tek b�lmek i�in d�ng� kullan�l�r.
		{
			if (i%j == 0) // i mod j 0 ise yap�lacak i�lemler a�a��dad�r
			{
				a=0; // Say�n�n printf () fonksiyonuna girmemesi i�in a de�eri 0 olur. Burada 0 yerine ba�ka bir say� da yaz�labilirdi
				break; // break komutu ile i� d�ng�den ��k�l�r ve d�� d�ng�ye ge�ilerek ba�ka bir say� denenir
			}
		}
		if (a == 1) // a=1 ise yukar�da anlatt���m gibi denenen say� asald�r
		{
			printf ("%d\n", i); // printf fonksiyonu ile asal olan say� ekrana yaz�l�r ve \n ile bir sat�r a�a�� ge�ilir
			s+=1; //s=s+1 ile ayn� �eydir ve bulunan her asal say�da 1 artar
		}
	}
	if (s>0) // burada if kullan�lmas�n�n sebebi 2den k���k say� girildi�inde a�a��dakin yaz�lmamas�, g�rselli�in bozulmamas� i�indir
	{
		printf ("\n"); //Program�n g�rselli�i a��s�ndan 1 sat�r a�a�� iner
		printf ("%d sayisina kadar %d tane asal sayi vardir...\n", n, s); //Burada da sayac�n de�eri ekrana yazd�r�l�r
	}
}