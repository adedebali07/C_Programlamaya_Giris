// 07233009 Adem Dedebali
#include <stdio.h> //kullanýlan printf() ve scanf() fonksiyonlarýnýn kayýtlý olduðu header dosyasýný aktif hale getirir.
#include <conio.h> //kullanýlan getche () fonksiyonunu barýndýran conio.h programa dahil edilmiþtir.

void main ()
{ 
	char c; //programýn devam sorgusu için c karakteri kullanýlmýþtýr
	c = 'e'; //bu satýrý kullanmazsak program while döngüsüne girmez ve hemen sonlanýr.
	while (c == 'e') //while döngüsü ile programýn istenildiði taktirde sürekli çalýþmasý saðlanýr.
	{ 
		int top, x, f; // toplama iþlemi için top, kullanýcýnýn gireceði x ve faktöriyelde kullanýlacak f programa dahil edilmiþtir.
		top=0, f=1; // top deðiþkenine 0, f deðiþkenine 1 deðeri aktarýlmýþtýr.
		printf ("Lutfen bir sayi giriniz:"); //Ekranda Lütfen bir sayi giriniz yazmasý saðlanmýþtýr.
		scanf ("%d", &x); // Kullanýcýnýn girdiði deðer x deðiþkenine aktarýlmýþtýr
		if (x >= 10) // Parçalý fonksiyona göre x'in 10'dan büyük olmasý durumunda yapýlacak iþlemler belirtilmistir
		{
			for (; x>0; x--) // for döngüsü ile x deðeri 0 a eþit olana kadar her adýmda 1 azaltýlýr
				top+=x; // top=top+x anlamýna gelir ve her seferinde toplama 1 azaltýlmýþ olan x deðerini ekler
			printf ("Sayilarin Toplami: %d\n", top); //Bulunan toplam sonucu ekrana yazýlýr 
		}
		else if (x >= 0 && x <= 9) // Fonksiyona göre x'in 10dan küçük ve 0a büyük eþit olduðu durumda yapýlacak iþlemleri gösterir
		{
			for (; x>0; x--) // x 0dan büyük olduðu sürece x i her bir dönüþte 1 azaltýr. x o iken döngü dönmez fakat f 1 olarak tanýmlandýðý için sonuç 1 olur
				f=f*x; // Her seferinde 1 azaltýlmýþ olan x f ile çarpýlýr
			printf ("Faktoriyel: %d\n", f); // bulunan sonuç ekrana yazdýrýlýr.
		}
		else if (x < 0) // x 0 dan küçük olduðu zaman yapýlacak iþlemler sýralanýr
			printf ("Lutfen negatif sayi girmeyiniz...\n"); // Ekrana uyarý yazdýrýlýr
		printf ("Devam etmek istiyor musunuz e/h:"); // Devam koþulu kullanýcýya sorulur. h görsel olmasý için yazýlmýþtýr. e dýþýndaki her cevap programý sonlandýrýr.
		scanf ("%c", &c); // Kullanýcýnýn cevabý c deðiþkenine aktarýlýr
		c = getche (); // c deðiþkeni de getche() fonksiyonuna aktarýlýr
		printf ("\n"); //programýn görsel olmasý açýsýndan 1 satýr aþaðý inilmesi belirtilir
	}
}