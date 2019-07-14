# include <iostream>
# include <string>
# include <fstream>
# include <cstdlib>
# include "lista.h"
using namespace std;

int main() {
	int polazni, zavrsni ;
	float brz, duz;
	string ulica;
	int lj;
	int izb;
	Lista l;
	try {
		ifstream ulaz;
		ulaz.open("ulice.txt");
		if (ulaz.fail()) {
			throw Gdat();
		}

		while (!ulaz.eof()) {
			ulaz >> polazni >> zavrsni >> duz >> brz >> ulica;
			lj = polazni;
			Podatak *p = new Podatak(duz, brz, ulica);
			Cvor *cv = new Cvor(polazni, p);
			l.dodaj(cv, zavrsni);
		}//kraj
		ulaz.close();

		l.izbacideo(2, 3);

		cout << "Izaberite:" << endl;
		cout << "1. Dodaj novu raskrsnicu" << endl;
		cout << "2. Dodaj ulicu" << endl;
		cout << "3. Dodaj deo ulice " << endl;
		cout << "4. Zatvranje dela ulice zbog radova" << endl;
		cout << "5. Zatvaranje cele ulice zbog radova" << endl;
		cout << "6. Zatvaranje dela  u odredjenom smeru" << endl;
		cout << "7. Zatvaranje cele ulice u odredjenom smeru" << endl;
		cout << "8. Promena smera na delu ulice " << endl;
		cout << "9. Promena smera na celoj ulici " << endl;
		cout << "10. Ispis svih raskrsinca koje pripadaju jednoj ulici" << endl;
		cout << "11. Nalazenje puta izmedju dve loakcije u gradu " << endl;
		cout << "12. Kraj" << endl;
		while (true) {
			cout << "\nUneti redni broj zeljene aktivnosti" << endl;
			cin >> izb;
			switch (izb) {
			case 1:
				cout << "identifikator? " << endl;
				int m;
				cin >> m;
				cout << "sa koliko raskrsnica treba povezati novu raskrsnicu? " << endl; int p;
				cin >> p;
				for (int i = 0; i < p; i++) {
					cout << "identifikator raskrsnice koju treba povezati sa novom raskrsnicom: ";
					int n;
					cin >> n;
					cout << "duzina: " << endl;
					cin >> duz;
					cout << "brzina: " << endl;
					cin >> brz;
					cout << " naziv ulice: " << endl;
					cin >> ulica;
					Podatak *p = new Podatak(duz, brz, ulica);
					Cvor *cv = new Cvor(polazni, p);
					l.dodaj(cv, zavrsni);
				}
				break;
			case 2:
				cout << "ime ulice: ";
				cin >> ulica;
				cout << endl;
				cout << "iz koliko delova se sastoji ulica: ";
				int n;
				cin >> n;
				cout << endl;
				for (int i = 0; i < n; i++) {
					cout << "polazni i zavrsni cvor? " << endl;
					cin >> polazni >> zavrsni;
					cout << "duzina?";
					cin >> duz;
					cout << endl;
					cout << "brzina? ";
					cin >> brz;
					cout << endl;
					Podatak *p = new Podatak(duz, brz, ulica);
					Cvor *cv = new Cvor(polazni, p);
					l.dodaj(cv, zavrsni);
				}
				break;
			case 3: {
				cout << "ime ulice: ";
				cin >> ulica;
				cout << endl;
				cout << "polazni i zavrsni cvor? " << endl;
				cin >> polazni >> zavrsni;
				cout << "duzina?" << endl;
				cin >> duz;
				cout << endl;
				cout << "brzina? " << endl;
				cin >> brz;
				cout << endl;
				Podatak *p = new Podatak(duz, brz, ulica);
				Cvor *cv = new Cvor(polazni, p);
				l.dodaj(cv, zavrsni);
				break;
			}
			case 4:
				cout << "uneti polazni i zavrsni cvor dela koji treba zatvoriti: " << endl;
				cin >> polazni >> zavrsni;
				l.izbacideo(polazni, zavrsni);
				l.izbacideo(zavrsni, polazni);
				break;
			case 5:
				cout << "koju ulicu treba zatvoriti: ";
				cin >> ulica;
				l.izbaciulicu(ulica);
				break;
			case 6:
				cout << "uneti polazni i zavrsni cvor dela koji treba zatvoriti: " << endl;
				cin >> polazni >> zavrsni;
				l.izbacideo(polazni, zavrsni);
				break;
			case 7:
				cout << "koju ulicu treba zatvoriti: ";
				cin >> ulica;
				cout << "u kom smeru treba zatvoriti ulicu?" << endl;
				cout << "1. manje ka vecem" << endl;
				cout << "2. vece ka manjem" << endl;
				int o;
				cin >> o;
				switch (o) {
				case 1:
					l.izbaciulicuodmkav(ulica); break;
				case 2:
					l.izbaciulicuodvkam(ulica); break;
				}
				break;
			case 8:
				cout << "uneti polazni i zavrsni cvor dela na kome treba promeniti smer: ";
				cin >> polazni >> zavrsni;
				l.promenismerdela(polazni, zavrsni);
				break;
			case 9:
				cout << "kojoj ulici treba promeniti smer? " << endl;
				cin >> ulica;
				l.promenismerulici(ulica);
				break;
			case 10:
				cout << "ulica cije raskrsnice treba ispistai: ";
				cin >> ulica;
				l.trazi(ulica);
				break;
			case 11: {
				cout << "polazna adresa: ";
				cin >> ulica >> polazni;
				cout << "\nodredisna adresa: ";
				string nj;
				cin >> nj >> zavrsni;
				l.formirajm();
				l.formirajt();
				l.flojd();
				float ss=l.adrese(ulica, nj, polazni, zavrsni);
				cout <<' '<< nj;
				cout << "\nprocenjeno vreme puta: " << ss;
				break;
			}
			case 12:
				exit(1);
			default:
				throw Gopcija();
			}//switch;
		}
	}
	catch (Gdat g) {cout << g << endl;}
	catch (Gnema g) { cout << g << endl; }
	catch (Gbroj g) { cout << g << endl; }
	catch (Gcvor g) { cout << g << endl; }
	catch(Gopcija g) { cout << g << endl; }
	catch (Gput g) { cout << g << endl; }
}//main