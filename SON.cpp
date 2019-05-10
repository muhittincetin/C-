//===========================================================================
// ECZANE OTOMASYONU (C++)
// Muhittin Cetin
// muhittincetinn@outlook.com
// the most important program for me...it's my first oop try.
//===========================================================================

#include <iostream>
#include <string>
#include <locale.h>
#include <iomanip>
#include <Windows.h>
#include <fstream>

using namespace std;

class Klas1 
{
	string ad, soyad, tckn,ilacismi,firmaismi,barkodno;
protected:
	void setad(char ad1);
	void setsoyad(char soyad1);
	void settckn(double tckn1);
	void setilacismi(char ilacismi1);
	void setfirmaismi(char firmaismi1);
	void setbarkodno(double barkodno1);
	ofstream dosyaYaz;
	ifstream dosyaOku;
	void IlacEkle();
	void PersonelEkle();
	void IlacListele();
	void PersonelListele();
};

void Klas1::setad(char ad1){
	ad=ad1;
}
void Klas1::setsoyad(char soyad1){
	soyad=soyad1;
}
void Klas1::settckn(double tckn1){
	tckn=tckn1;
}
void Klas1::setilacismi(char ilacismi1){
	ilacismi=ilacismi1;
}
void Klas1::setfirmaismi(char firmaismi1){
	firmaismi=firmaismi1;
}
void Klas1::setbarkodno(double barkodno1){
	barkodno=barkodno1;
}


void Klas1::IlacEkle()
{
	string kontrol;
					string a;
					int pl; //ad ve soyadda rakam ve kullanýlamayan karakterilerin kontrolü için oluþturulan deðiþken.
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
								cout << "ISIM BOLUMUNDE INGILIZCE HARFLERDEN BASKA KARAKTER KULLANILAMAZ\n\a";
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
								cout << "ISIM BOLUMUNDE INGILIZCE HARFLERDEN BASKA KARAKTER KULLANILAMAZ\n\a";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						int u = 0, olo = 0;  //tc no ve müþteri no'larý nizamimi ve daha önceden kullanýlmýþ mý diye kontrol ederken kullanýlan deðiþkenler.
						char n;
						string tutBarkodNo, tg, yh, th; //dosyada nokuma esnasýnda ad,soyad ve tcnin karýþmamasý için kullanýlan deðiþkenler.
						do {
							dosyaOku.open("IlacKayit.txt");
							u = 0,olo = 0; int p = 0;
							cout << "5 HANELI BARKOD NUMARASINI GIRIN: ";
							cin >> barkodno;
							tutBarkodNo = barkodno;
							while (dosyaOku >> tg >> th >> barkodno >> yh) {
								if (tutBarkodNo == barkodno)          //eðer tckn sistemde kayýtlýysa olo deðiþkenine 1 atar.
									olo = 1;
							}
							dosyaOku.close();

							for (int i = 0; i < (tutBarkodNo.length()); i++) {
								n = tutBarkodNo[i];
								p = static_cast<int>(n);
								if (!(p > 47 && p < 58))						//eðer tckn de rakamdan farklý bir karakter kulllanýlmýþsa u deðiþkenine 1 atar.
									u = 1;
							}
							if (u == 1) {
								system("cls");
								cout << "BARKOD NUMARASI SADECE RAKAMLARDAN OLUSMALI...\n\a";			//u deðiþkenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
							else if (tutBarkodNo.length() != 5) {
								system("cls");
								cout << "BARKOD NUMARASI 5 HANELI OLMALI...\n\a";					//tckn 11 haneli deðilse uyarý verir.
								system("pause");
								system("cls");
							}
							else if (olo == 1) {
								system("cls");
								cout << "BU BARKOD NUMARASI KAYITLARDA BULUNMAKTA. BASKA BIR NUMARA GIRINIZ...\n\a";			//olo deðikenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
						} while (u == 1 || tutBarkodNo.length() != 5 || olo == 1); //eðer uyarýlardan biri bile olduysa tckn nin yeniden girilmesini ister.
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
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n\a";
								system("pause");
								system("cls");
							}
						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");
}

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
								cout << "ISIM BOLUMUNDE INGILIZCE HARFLERDEN BASKA KARAKTER KULLANILAMAZ\n\a";
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
								cout << "SOYAD BOLUMUNDE INGILIZCE HARFLERDEN BASKA KARAKTER KULLANILAMAZ\n\a";
								system("pause");
								system("cls");
							}
						} while (pl == 1);
						int u = 0, olo = 0;  //tc no ve müþteri no'larý nizamimi ve daha önceden kullanýlmýþ mý diye kontrol ederken kullanýlan deðiþkenler.
						char n;
						string tutTC, tg, yh, th; //dosyada nokuma esnasýnda ad,soyad ve tcnin karýþmamasý için kullanýlan deðiþkenler.
						do {
							dosyaOku.open("PersoenlKayit.txt");
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
								cout << "TCKN SADECE RAKAMLARDAN OLUÞMALI...\n\a";			//u deðiþkenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
							else if (tutTC.length() != 11) {
								system("cls");
								cout << "TCKN 11 HANELI OLMALI...\n\a";					//tckn 11 haneli deðilse uyarý verir.
								system("pause");
								system("cls");
							}
							else if (olo == 1) {
								system("cls");
								cout << "BU TCKN KAYITLARDA BULUNMAKTA. BASKA BIR TCKN GIRINIZ...\n\a";			//olo deðikenine 1 atanmýþsa uyarý verir.
								system("pause");
								system("cls");
							}
						} while (u == 1 || tutTC.length() != 11 || olo == 1); //eðer uyarýlardan biri bile olduysa tckn nin yeniden girilmesini ister.
						dosyaYaz.open("PersonelKayit.txt", ios::app);
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
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n\a";
								system("pause");
								system("cls");
							}
						} while (kontrol != "e"&&kontrol != "h");
					} while (kontrol == "e");
}

void Klas1::IlacListele()
{	system("cls");
	cout << "ILAC ISMI" << "\t" << "FIRMA ADI" << "\t" << "BARKOD NO\n";
					for (int i = 0; i < 53; i++) {
						cout << "*";
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

void Klas1::PersonelListele()
{	system("cls");
	cout << "PERSONEL ADI" << "\t" << "PERSONEL SOYADI" << "\t" << "PERSONEL TCKN\n";
					for (int i = 0; i < 53; i++) {
						cout << "*";
						if (i == 10)
							cout << "\t";
						if (i == 25)
							cout << "\t";
					}
					cout << endl;
					dosyaOku.open("PersonelKayit.txt");
					while (dosyaOku >> ad >> soyad >> tckn) {
						string ad1 = ad, soyad1 = soyad;

						cout << left << setw(18 - (ad1.length())) << ad << "\t" << left << setw(16 - (soyad1.length())) << soyad << "\t" << tckn << endl;
					}
					dosyaOku.close();

					system("pause");
					system("cls");
}

class Klas2
{
	string ad, soyad, tckn,ilacismi,firmaismi,barkodno;
	ofstream dosyaYaz;
	ifstream dosyaOku;
	protected:
	void setad(char ad1);
	void setsoyad(char soyad1);
	void settckn(double tckn1);
	void setilacismi(char ilacismi1);
	void setfirmaismi(char firmaismi1);
	void setbarkodno(double barkodno1);
	
	
	void IlacSil();
	void PersonelSil();
};


void Klas2::setad(char ad1){
	ad=ad1;
}
void Klas2::setsoyad(char soyad1){
	soyad=soyad1;
}
void Klas2::settckn(double tckn1){
	tckn=tckn1;
}
void Klas2::setilacismi(char ilacismi1){
	ilacismi=ilacismi1;
}
void Klas2::setfirmaismi(char firmaismi1){
	firmaismi=firmaismi1;
}
void Klas2::setbarkodno(double barkodno1){
	barkodno=barkodno1;
}



void Klas2::IlacSil()
{
string kontrol2;
					string no1;  //tc numarasý sistemde varmý diye kontrol eden deðiþken.
					do {
						int barkodnokontrol = 0;      //silinmesi için girilen tc numaranýn var olup olmadýðýný anlamak için kullanýlan deðiþken.
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
								cout << "BOYLE BIR KAYIT BULUNMAMAKTADIR.\n\a";
								system("pause");
								system("cls");
							}
						} while (barkodnokontrol == 0);
						dosyaYaz.open("IlacKayitTut.txt");
						dosyaOku.open("IlacKayit.txt");
						while (dosyaOku >> ilacismi >> firmaismi >> barkodno ) 
						{
							if (barkodno != no1)
								dosyaYaz << ilacismi << "\t" << firmaismi << "\t" << barkodno << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("IlacKayit.txt");
						dosyaOku.open("IlacKayitTut.txt");
						while (dosyaOku >> ilacismi >> firmaismi >> barkodno ) 
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
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n\a";
								system("pause");
								system("cls");
							}
						} while (kontrol2 != "e"&&kontrol2 != "h");
					} while (kontrol2 == "e");
}

void Klas2::PersonelSil()
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
							dosyaOku.open("PersonelKayit.txt");
							while (dosyaOku >> ad >> soyad >> tckn)
							{
								if (no == tckn )
									tcnokontrol = 1;
							}
							dosyaOku.close();
							if (tcnokontrol == 0) {
								system("cls");
								cout << "BOYLE BIR KAYIT BULUNMAMAKTADIR.\n\a";
								system("pause");
								system("cls");
							}
						} while (tcnokontrol == 0);
						dosyaYaz.open("PersonelKayitTut.txt");
						dosyaOku.open("PersonelKayit.txt");
						while (dosyaOku >> ad >> soyad >> tckn ) 
						{
							if (tckn != no)
								dosyaYaz << ad << "\t" << soyad << "\t" << tckn << endl;
						}
						dosyaOku.close();
						dosyaYaz.close();
						dosyaYaz.open("PersonelKayit.txt");
						dosyaOku.open("PersonelKayitTut.txt");
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
								cout << "\n-e- VEYA -h- HARFLERINDEN BIRINI GIRIN...\n\a";
								system("pause");
								system("cls");
							}
						} while (kontrol1 != "e"&&kontrol1 != "h");
					} while (kontrol1 == "e");
}

class Klas3:protected Klas1,protected Klas2
{	
	string secim,secim1,secim2;  //Menü seçimlerinde kullanýlan deðiþken.
	public:
	void GenelFonksiyon();
};

void Klas3::GenelFonksiyon()
{
	do {
		system("cls");
		cout << "ECZANE OTOMASYONU\n";
		for (int i = 0; i < 20; i++)
			cout << "*";
		cout << endl;
		cout << "1- ILAC ISLEMLERI\n";
		cout << "2- PERSONEL ISLEMLERI\n";
		cout << "0- CIKIS\n\n";
		cout << "SECIMINIZ: ";
		cin >> secim;
		if (secim == "1") {
			string secim1;		//Menü seçimlerinde kullanýlan deðiþken.
			do {
				system("cls");
				cout << "ILAC ISLEMLERI\n";
				for (int i = 0; i < 20; i++)
					cout << "*";
				cout << endl;
				cout << "1- ILAC EKLE\n";
				cout << "2- ILAC SIL\n";
				cout << "3- ILACLARI LISTELE\n";
				cout << "99- UST MENU\n\n";
				cout << "SECIMINIZ: ";
				cin >> secim1;
				if (secim1 == "1") 
				{
					IlacEkle();
				}
				else if (secim1 == "2")
				{
					IlacSil();
				}
				else if(secim1 == "3")
				{
					IlacListele();
				}
				if ((secim1 != "1") && (secim1 != "2") && (secim1 != "3") && (secim1 != "99")) {
					system("cls");
					cout << "HATALI SECIM\n\a";
					system("pause");
				}
			} while (secim1 != "99");
		}
		//------------------------------------------------------------------------ANA_MENU_1.SECENEK_CIKIS--------------------------------------	


		//------------------------------------------------------------------------ANA_MENU_2.SECENEK_GIRIS-------------------------------------
			if (secim == "2") {
			do {
				system("cls");
				cout << "PERSONEL ISLEMLERI\n";
				for (int i = 0; i < 20; i++)
					cout << "*";
				cout << endl;
				cout << "1- PERSONEL EKLE\n";
				cout << "2- PERSONEL SIL\n";
				cout << "3- PERSONEL LISTELE\n";
				cout << "99- UST MENU\n\n";
				cout << "SECIMINIZ: ";
				cin >> secim2;
				//------------------------------------2 nin icindeki 1 giris-------------
				if (secim2 == "1")
				{
					PersonelEkle();
				}
				else if (secim2 == "2")
				{
					PersonelSil();
				}
				else if (secim2 == "3")
				{
					PersonelListele();
				}
				if ((secim2 != "1") && (secim2 != "2") && (secim2 != "3") && (secim2 != "99")) {
					system("cls");
					cout << "HATALI SECIM\n\a";
					system("pause");
				}
			} while (secim2 != "99");
		}
		if ((secim != "1") && (secim != "2") && (secim != "3") && (secim != "0")) {
			system("cls");
			cout << "HATALI SECIM\n\a";
			system("pause");
		}
	} while (secim != "0");
	system("cls");
	system("del IlacKayitTut.txt");
	system("del PersonelKayitTut.txt");
	system("cls");
	cout << "PROGRAMDAN CIKILDI.\n";
	system("pause");
}

int main()
{
	system("color F4");
	Klas3 Nesne;
	Nesne.GenelFonksiyon();
	return 0;
}
