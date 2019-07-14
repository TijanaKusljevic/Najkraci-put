#include "cvor.h"
# include "podatak.h"
# include <climits>
# include <list>
# include <iostream>
#include "greske.h"
using namespace std;

const float beskonacno = INT_MAX;


class Lista {
	Cvor** lista;
	int kap;
	float **a;
	int **t;
public:

	Lista(int k = 10);
	Lista& dodaj(Cvor* c, int zavrsni);

	friend ostream& operator<<(ostream& it, Lista& l) {
		Cvor* k = nullptr;
		for (int i = 0; i < l.kap; i++) {
			if (l.lista[i] != nullptr) {
				k = l.lista[i];
				while (k) { it << *k << endl; k = k->sledeci; }
			}
		}
		return it;
	}
	Lista& trazi(string trazena);

	Lista& promenismerdela(int polazni, int zavrsni);

	Lista& izbacideo(int pol, int zav);

	Lista& izbaciulicu(string trazena);

	Lista& izbaciulicuodmkav(string trazena);

	Lista& izbaciulicuodvkam(string trazena);

	Lista& promenismerulici(string trazena);

	Lista& formirajm();

	Lista&  formirajt();

	Lista& ispisi() {
		for (int i = 1; i < kap; i++)
		{
			cout << endl;
			for (int j = 1; j < kap; j++) cout << a[i][j] << " ";
		}
		return *this;
	}

	Lista& ispisit() {
		for (int i = 1; i < kap; i++)
		{
			cout << endl;
			for (int j = 1; j < kap; j++) cout << t[i][j] << " ";
		}
		return *this;
	}


	Lista& flojd();

	float path(int i, int j);

	int nadjikubr(string trazena, int kubr);

	float adrese(string t1, string t2, int a1, int a2) {
		int k1 = nadjikubr(t1, a1);
		int k2 = nadjikubr(t2, a2);
		if (k1 == k2) { cout << "\nmesta su jako blizu, nabolje otici peske :)" << endl; }
		float v = path(k1, k2) / 60;
		return v;
	}
};