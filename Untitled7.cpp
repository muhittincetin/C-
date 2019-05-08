#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>
using namespace std;
class Klas1
{
	string ad, soyad, tckn;
	public:
		ofstream dosyaYaz;
		ifstream dosyaOku;
		void PersonelEkle();
		void PersonelSil();
		void PersonelGuncelle();
};

void Klas1::PersonelEkle()
{
	string kontrol;
					string a;
					int pl; //ad ve soyadda rakam ve kullanýlamayan karakterilerin kontrolü için oluþturulan deðiþken.
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
								cout << "ISIM BÖLÜMÜNDE INGILIZCE HARFLERDEN BAÞKA KARAKTER KULLANILAMAZ\n";
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
						int u = 0, olo = 0;  //tc no ve müþteri no'larý nizamimi ve daha önceden kullanýlmýþ mý diye kontrol ederken kullanýlan deðiþkenler.
						char n;
						string tutTC, tg, yh, th; //dosyada nokuma esnasýnda ad,soyad ve tcnin karýþmamasý için kullanýlan deðiþkenler.
						do {
							dosyaOku.open("persoenlKayit.txt");
							u = 0, olo = 0; int p = 0;
							cout << "PERSONELIN 11 HANELI TC KIMLIK NUMARASINI GIRIN: ";
							cin >> tckn;
							tutTC = tckn;
							while (dosyaOku >> tg >> th >> tckn >> yh) {
								if (tutTC == tckn)          //eðer tckn sistemde kayýtlýysa olo deðiþkenine 1 atar.
									olo = 1;
							}
							dosyaOku.close();

							for (int i = 0; i < (tutTC.length()); i++) {
								n = tutTC[i];
								p = static_cast<int>(n);
								if (!(p > 47 && p < 58))						//eðer tckn de rakamdan farklý bir karakter kulllanýlmýþsa u deðiþkenine 1 atar.
									u = 1;
							}
							if (u == 1) {
								system("cls");
								cout << "TCKN SADECE RAKAMLARDAN OLUÞMALI...\n";			//u deðiþkenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
							else if (tutTC.length() != 11) {
								system("cls");
								cout << "TCKN 11 HANELI OLMALI...\n";					//tckn 11 haneli deðilse uyarý verir.
								system("pause");
								system("cls");
							}

							else if (olo == 1) {
								system("cls");
								cout << "BU TCKN KAYITLARDA BULUNMAKTA. BASKA BIR TCKN GIRINIZ...\n";			//olo deðikenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
						} while (u == 1 || tutTC.length() != 11 || olo == 1); //eðer uyarýlardan biri bile olduysa tckn nin yeniden girilmesini ister.
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
					string no;  //tc numarasý sistemde varmý diye kontrol eden deðiþken.

					do {
						int tcnokontrol = 0;      //silinmesi için girilen tc numaranýn var olup olmadýðýný anlamak için kullanýlan deðiþken.
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
				}

void Klas1::PersonelGuncelle()
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
	Klas1 Personel1;
	Personel1.PersonelEkle();
	Personel1.PersonelSil();
	Personel1.PersonelGuncelle();
	return 0;
}
