#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>

using namespace std;

class Klas1 
{	
    char *ilacismi;
    float barkodno;
    int adet;
	int fiyat;
public:
	
	void IlacEkle();
};

void Klas1::IlacEkle()
{
	
eczane girdi;  // eczane tipinde bir degisken tanimi
                              girdi.ilacismi=(char *)malloc(sizeof(char)*300);
                              printf("Ilac Ismi Giriniz:");
                              scanf("%s",girdi.ilacismi);
                              printf("Barkod Numarasi:");
                              scanf("%f",&girdi.barkodno);
                              printf("Adet sayisi:");
                              scanf("%d",&girdi.adet);
                              printf("Ilac Fiyat:");
                              scanf("%d",&girdi.fiyat); 
                              FILE *fp=fopen("Ilac.txt","a");   // append modunda acar dosyaya ekleme yapar
                              fprintf(fp,"%s %s %s %f %d %d %d %d %d\n",girdi.ilacismi,girdi.barkodno,girdi.adet,girdi.fiyat); // ve dosyadan yazdirir
                              printf("--Kayit Basari Ile Gerceklestirilmistir--\n");
                              fclose(fp); // islem bittiginde dosyayi kapatir
                              }
int main()
{
	 typedef ilac eczane;
	Klas1 ilac1;
	ilac1.IlacEkle();
	
	return 0;
}
