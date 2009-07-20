// 07233009 Adem Dedebali
#include <stdio.h> //header dosyasý programa dahil edilir
void main ()
{
	int n, i, j, a, s; // n girilen sayi, i ve j döngü deðiþkenleri, a break komutu için, s de sayaç için kullanýlmýþtýr
	s=0; // Sayaca 0 deðeri verilir
	printf ("Lutfen bir sayi giriniz:"); // Ekrana sayý girilmesi istendiði yazýlýr
	scanf ("%d", &n); // Girilen deðer n deðiþkenine aktarýlýr
	if (n < 2) // Asal sayýlar 2 den baþladýðýndan 2 den küçük sayýlar elenir.
		printf ("Asal sayilar 2'den baslar...\n"); //Kullanýcýya uyarý verilir
	for (i=2; i<=n; i++) // Burada 2 den baþlanýp n e kadar olan bütün sayýlar tek tek kendisinden küçük olan sayýlara
						 // bölünecektir. Ýçiçe 2 döngü ile yapýlacak bu iþlemin ilk döngüsü budur.
	{
		a=1; // Asal olmayan sayýnýn atlanmasý için a deðiþkeni kullanýlmýþtýr. Modu 0'a eþit olan sayýda a 0'a eþitlenecek
			 // ve printf fonksiyonu sadece a'nýn 1 olduðu durumda devreye gireceðinden ekrana yazýlmayacaktýr
		for (j=2; j<i; j++) // i yi kendisinden küçük olan sayýlara tek tek bölmek için döngü kullanýlýr.
		{
			if (i%j == 0) // i mod j 0 ise yapýlacak iþlemler aþaðýdadýr
			{
				a=0; // Sayýnýn printf () fonksiyonuna girmemesi için a deðeri 0 olur. Burada 0 yerine baþka bir sayý da yazýlabilirdi
				break; // break komutu ile iç döngüden çýkýlýr ve dýþ döngüye geçilerek baþka bir sayý denenir
			}
		}
		if (a == 1) // a=1 ise yukarýda anlattýðým gibi denenen sayý asaldýr
		{
			printf ("%d\n", i); // printf fonksiyonu ile asal olan sayý ekrana yazýlýr ve \n ile bir satýr aþaðý geçilir
			s+=1; //s=s+1 ile ayný þeydir ve bulunan her asal sayýda 1 artar
		}
	}
	if (s>0) // burada if kullanýlmasýnýn sebebi 2den küçük sayý girildiðinde aþaðýdakin yazýlmamasý, görselliðin bozulmamasý içindir
	{
		printf ("\n"); //Programýn görselliði açýsýndan 1 satýr aþaðý iner
		printf ("%d sayisina kadar %d tane asal sayi vardir...\n", n, s); //Burada da sayacýn deðeri ekrana yazdýrýlýr
	}
}