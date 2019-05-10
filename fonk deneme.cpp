#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;
class Klas1
{
	string ad, soyad, tckn,ilacismi,firmaismi,barkodno,ilacadet;
	public:
		ofstream dosyaYaz;
		ifstream dosyaOku;
		void IlacEkle();
		void IlacSil();
		void IlacListele();
		void PersonelEkle();
		void PersonelSil();
		void PersonelListele();
};

void Klas1::IlacEkle()
{
	string kontrol;
					string a;
					int pl; //ad ve soyadda rakam ve kullan�lamayan karakterilerin kontrol� i�in olu�turulan de�i�ken.
					do {
						system("cls");
						do {
							pl = 0;
							cout << "ILAC ISMINI GIRIN: ";
							cin >> ilacismi;
							for (int i = 0; i < ((ilacismi).length()); i++) {
								int n = static_cast<int>(ilacismi[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;
								}
							}
							if (pl == 1) {
								system("cls");
								cout << "ISIM B�L�M�NDE INGILIZCE HARFLERDEN BA�KA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						
						do {
							pl = 0;
							cout << "ILAC FIRMASINI GIRIN: ";
							cin >> firmaismi;
							for (int i = 0; i < ((firmaismi).length()); i++) {
								int n = static_cast<int>(firmaismi[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "ISIM BOLUMUNDE INGILIZCE HARFLERDEN BASKA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						int u = 0, olo = 0;  //tc no ve m��teri no'lar� nizamimi ve daha �nceden kullan�lm�� m� diye kontrol ederken kullan�lan de�i�kenler.
						char n;
						string tutBarkodNo, tg, yh, th; //dosyada nokuma esnas�nda ad,soyad ve tcnin kar��mamas� i�in kullan�lan de�i�kenler.
						do {
							dosyaOku.open("IlacKayit.txt");
							u = 0,olo = 0; int p = 0;
							cout << "5 HANELI BARKOD NUMARASINI GIRIN: ";
							cin >> barkodno;
							tutBarkodNo = barkodno;
							while (dosyaOku >> tg >> th >> barkodno >> yh) {
								if (tutBarkodNo == barkodno)          //e�er tckn sistemde kay�tl�ysa olo de�i�kenine 1 atar.
									olo = 1;
							}
							dosyaOku.close();

							for (int i = 0; i < (tutBarkodNo.length()); i++) {
								n = tutBarkodNo[i];
								p = static_cast<int>(n);
								if (!(p > 47 && p < 58))						//e�er tckn de rakamdan farkl� bir karakter kulllan�lm��sa u de�i�kenine 1 atar.
									u = 1;
							}
							if (u == 1) {
								system("cls");
								cout << "BARKOD NUMARASI SADECE RAKAMLARDAN OLUSMALI...\n";			//u de�i�kenine 1 atanm��sa uyar� verir.
								system("pause");
								system("cls");
							}
							else if (tutBarkodNo.length() != 5) {
								system("cls");
								cout << "BARKOD NUMARASI 5 HANELI OLMALI...\n";					//tckn 11 haneli de�ilse uyar� verir.
								system("pause");
								system("cls");
							}
							else if (olo == 1) {
								system("cls");
								cout << "BU BARKOD NUMARASI KAYITLARDA BULUNMAKTA. BASKA BIR NUMARA GIRINIZ...\n";			//olo de�ikenine 1 atanm��sa uyar� verir.
								system("pause");
								system("cls");
							}

						} while (u == 1 || tutBarkodNo.length() != 5 || olo == 1); //e�er uyar�lardan biri bile olduysa tckn nin yeniden girilmesini ister.
						dosyaYaz.open("IlacKayit.txt", ios::app);
						dosyaYaz << ilacismi << "\t" << firmaismi << "\t" << tutBarkodNo << endl;
						dosyaYaz.close();
						system("cls");
						cout << "ILAC KAYDI YAPILMISTIR\n";
						system("pause");
						do {
							system("cls");
							cout << "YENI KAYIT(e/h): ";
							cin >> kontrol;
							if (kontrol != "e"&&kontrol != "h") {
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");
}

					
void Klas1::IlacSil()
{
	string kontrol2;
					string no1;  //tc numaras� sistemde varm� diye kontrol eden de�i�ken.

					do {
						int barkodnokontrol = 0;      //silinmesi i�in girilen tc numaran�n var olup olmad���n� anlamak i�in kullan�lan de�i�ken.
						do {
							barkodnokontrol = 0;
							system("cls");
							cout << "SILINECEK ILACIN BARKOD NUMARASINI GIRIN: ";
							cin >> no1;
							dosyaOku.open("IlacKayit.txt");
							while (dosyaOku >> ilacismi >> firmaismi >> barkodno)
							{
								if (no1 == barkodno )
									barkodnokontrol = 1;
							}
							dosyaOku.close();
							if (barkodnokontrol == 0) {
								system("cls");
								cout << "BOYLE BIR KAYIT BULUNMAMAKTADIR.\n";
								system("pause");
								system("cls");
							}
						} while (barkodnokontrol == 0);
						dosyaYaz.open("IlacKayitTut.txt");
						dosyaOku.open("IlacKayit.txt");
						while (dosyaOku >> ad >> soyad >> tckn ) 
						{
							if (barkodno != no1)
								dosyaYaz << ilacismi << "\t" << firmaismi << "\t" << barkodno << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("IlacKayit.txt");
						dosyaOku.open("IlacKayitTut.txt");
						while (dosyaOku >> ilacismi >> soyad >> tckn ) 
						{
							dosyaYaz << ilacismi << "\t" << firmaismi << "\t" << barkodno << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						system("cls");
						cout << "SILME ISLEMI YAPILMISTIR\n";
						system("pause");
						do {
							system("cls");
							cout << "SILME ISLEMINE DEVAM ETMEK ISTERMISINIZ(e/h): ";
							cin >> kontrol2;
							if (kontrol2 != "e"&& kontrol2 != "h") {
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol2 != "e"&&kontrol2 != "h");
					} while (kontrol2 == "e");
					system("pause");
					system("cls");
}

void Klas1::IlacListele()
{
cout << "ILAC ISMI" << "\t" << "FIRMA ADI" << "\t" << "BARKOD NO\n";
					for (int i = 0; i < 53; i++) {
						cout << "_";
						if (i == 10)
							cout << "\t";
						if (i == 25)
							cout << "\t";
					}
					cout << endl;
					dosyaOku.open("IlacKayit.txt");
					while (dosyaOku >> ilacismi >> firmaismi >> barkodno) {
						string isim1 = ilacismi, isim2 = firmaismi;

						cout << left << setw(18 - (isim1.length())) << ilacismi << "\t" << left << setw(16 - (isim2.length())) << firmaismi << "\t" << barkodno << endl;
					}
					dosyaOku.close();

					system("pause");
					system("cls");
}

void Klas1::PersonelEkle()
{
	string kontrol;
					string a;
					int pl; //ad ve soyadda rakam ve kullan�lamayan karakterilerin kontrol� i�in olu�turulan de�i�ken.
					do {
						system("cls");
						do {
							pl = 0;
							cout << "PERSONEL ADINI GIRIN: ";
							cin >> ad;
							for (int i = 0; i < ((ad).length()); i++) {
								int n = static_cast<int>(ad[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;
								}
							}
							if (pl == 1) {
								system("cls");
								cout << "ISIM B�L�M�NDE INGILIZCE HARFLERDEN BA�KA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);

						do {
							pl = 0;
							cout << "PERSONEL SOYADINI GIRIN: ";
							cin >> soyad;
							for (int i = 0; i < ((soyad).length()); i++) {
								int n = static_cast<int>(soyad[i]);
								if (!((n > 64 && n < 91) || (n > 96 && n < 123))) {
									pl = 1;

								}
							}
							if (pl == 1) {
								system("cls");
								cout << "SOYAD BOLUMUNDE INGILIZCE HARFLERDEN BASKA KARAKTER KULLANILAMAZ\n";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						int u = 0, olo = 0;  //tc no ve m��teri no'lar� nizamimi ve daha �nceden kullan�lm�� m� diye kontrol ederken kullan�lan de�i�kenler.
						char n;
						string tutTC, tg, yh, th; //dosyada nokuma esnas�nda ad,soyad ve tcnin kar��mamas� i�in kullan�lan de�i�kenler.
						do {
							dosyaOku.open("persoenlKayit.txt");
							u = 0, olo = 0; int p = 0;
							cout << "PERSONELIN 11 HANELI TC KIMLIK NUMARASINI GIRIN: ";
							cin >> tckn;
							tutTC = tckn;
							while (dosyaOku >> tg >> th >> tckn >> yh) {
								if (tutTC == tckn)          //e�er tckn sistemde kay�tl�ysa olo de�i�kenine 1 atar.
									olo = 1;
							}
							dosyaOku.close();

							for (int i = 0; i < (tutTC.length()); i++) {
								n = tutTC[i];
								p = static_cast<int>(n);
								if (!(p > 47 && p < 58))						//e�er tckn de rakamdan farkl� bir karakter kulllan�lm��sa u de�i�kenine 1 atar.
									u = 1;
							}
							if (u == 1) {
								system("cls");
								cout << "TCKN SADECE RAKAMLARDAN OLU�MALI...\n";			//u de�i�kenine 1 atanm��sa uyar� verir.
								system("pause");
								system("cls");
							}
							else if (tutTC.length() != 11) {
								system("cls");
								cout << "TCKN 11 HANELI OLMALI...\n";					//tckn 11 haneli de�ilse uyar� verir.
								system("pause");
								system("cls");
							}

							else if (olo == 1) {
								system("cls");
								cout << "BU TCKN KAYITLARDA BULUNMAKTA. BASKA BIR TCKN GIRINIZ...\n";			//olo de�ikenine 1 atanm��sa uyar� verir.
								system("pause");
								system("cls");
							}
						} while (u == 1 || tutTC.length() != 11 || olo == 1); //e�er uyar�lardan biri bile olduysa tckn nin yeniden girilmesini ister.
						dosyaYaz.open("personelKayit.txt", ios::app);
						dosyaYaz << ad << "\t" << soyad << "\t" << tutTC << endl;
						dosyaYaz.close();
						system("cls");
						cout << "PERSONEL KAYDI YAPILMISTIR\n";
						system("pause");
						do {
							system("cls");
							cout << "YENI KAYIT(e/h): ";
							cin >> kontrol;
							if (kontrol != "e"&&kontrol != "h") {
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");
}

void Klas1::PersonelSil()
{
	string kontrol1;
					string no;  //tc numaras� sistemde varm� diye kontrol eden de�i�ken.

					do {
						int tcnokontrol = 0;      //silinmesi i�in girilen tc numaran�n var olup olmad���n� anlamak i�in kullan�lan de�i�ken.
						do {
							tcnokontrol = 0;
							system("cls");
							cout << "SILINECEK PERSONELIN TC NUMARASINI GIRIN: ";
							cin >> no;
							dosyaOku.open("personelKayit.txt");
							while (dosyaOku >> ad >> soyad >> tckn)
							{
								if (no == tckn )
									tcnokontrol = 1;
							}
							dosyaOku.close();
							if (tcnokontrol == 0) {
								system("cls");
								cout << "BOYLE BIR KAYIT BULUNMAMAKTADIR.\n";
								system("pause");
								system("cls");
							}
						} while (tcnokontrol == 0);
						dosyaYaz.open("personelKayitTut.txt");
						dosyaOku.open("personelKayit.txt");
						while (dosyaOku >> ad >> soyad >> tckn ) 
						{
							if (tckn != no)
								dosyaYaz << ad << "\t" << soyad << "\t" << tckn << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("personelKayit.txt");
						dosyaOku.open("personelKayitTut.txt");
						while (dosyaOku >> ad >> soyad >> tckn ) 
						{
							dosyaYaz << ad << "\t" << soyad << "\t" << tckn << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						system("cls");
						cout << "SILME ISLEMI YAPILMISTIR\n";
						system("pause");
						do {
							system("cls");
							cout << "SILME ISLEMINE DEVAM ETMEK ISTERMISINIZ(e/h): ";
							cin >> kontrol1;
							if (kontrol1 != "e"&&kontrol1 != "h") {
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n";
								system("pause");
								system("cls");
							}

						} while (kontrol1 != "e"&&kontrol1 != "h");
					} while (kontrol1 == "e");
					system("pause");
					system("cls");
				}

void Klas1::PersonelListele()
{
	cout << "PERSONEL ADI" << "\t" << "PERSONEL SOYADI" << "\t" << "PERSOENL TCKN\n";
					for (int i = 0; i < 53; i++) {
						cout << "_";
						if (i == 10)
							cout << "\t";
						if (i == 25)
							cout << "\t";
					}
					cout << endl;
					dosyaOku.open("personelKayit.txt");
					while (dosyaOku >> ad >> soyad >> tckn) {
						string ad1 = ad, soyad1 = soyad;

						cout << left << setw(18 - (ad1.length())) << ad << "\t" << left << setw(16 - (soyad1.length())) << soyad << "\t" << tckn << endl;
					}
					dosyaOku.close();

					system("pause");
					system("cls");
}

int main()
{
	system("color F4");
	Klas1 Ilac1;
	Ilac1.IlacEkle();
	
	Ilac1.IlacListele();
	return 0;
}
