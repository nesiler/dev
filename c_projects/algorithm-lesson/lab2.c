/*Enes Diler- 19120205016
 *Lab2.c 
 */

#include <limits.h>

#include <stdio.h>

int max(int a, int b, int c)
{

	int max = (a > b) ? a : b;

	max = (max > c) ? max : c;

	return max;
}

//yazmanız gereken asil fonksiyon budur. Gerekirse ekstra yardımcı fonksiyon yazabilirsiniz.

int ortaninToplami(int arr[], int sol, int orta, int sag)
{
	//bu kodu yazınız
	int solkisim = INT_MIN;
	int sagkisim = INT_MIN;
	int toplam = 0;

	for (int i = orta; i >= sol; i--)
	{
		toplam += arr[i];
		if ((toplam > solkisim))
			solkisim = toplam;
	}

	toplam = 0;

	for (int j = orta + 1; j <= sag; j++)
	{
		toplam += arr[j];
		if (toplam > sagkisim)
			sagkisim = toplam;
	}

	return max(solkisim + sagkisim, solkisim, sagkisim);
}

//diziyi, ilk indisi, son indisi input olarak alır.
int enBuyukToplam(int arr[], int sag, int sol)
{

	//base case
	int orta;
	if (sag == sol)
	{
		return arr[sag];
	}
	else
	{
		orta = (sag + sol) / 2;
	} // Find middle point

	/* 3 ihtimalin maxmumunu dondurunuz
            1. maximum sol tarafta
            2. maximum sag tarafta
            3.maximum sağ ve solun ortasının toplamında */

	//aşağıdaki max fonksyonunu yazın
	return max(enBuyukToplam(arr, sol, orta),
			   enBuyukToplam(arr, orta + 1, sag),
			   ortaninToplami(arr, sag, orta, sol)); //bu fonksiyonu yukarıya yazın
}

int main()
{ //mainde hiçbir şey değiştirmeyiniz.

	//diziyi tanımla
	/*int arr[] = {-2, -5, 6, -2, -3, 1, 5, -6};
	//dizinin boyunu bul
	int n = sizeof(arr) / sizeof(arr[0]);

	//fonksiyonu çağır
	int toplam_max = enBuyukToplam(arr, 0, n - 1);

	//yazdır
	printf("%d", toplam_max);*/

	printf("asdas:");
	int x;
	scanf("%d", &x);
	printf("x : %d", x);

	return 0;
}