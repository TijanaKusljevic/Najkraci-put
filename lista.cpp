# include "lista.h"

Lista::Lista(int k) {
	lista = new Cvor*[kap = k];
	for (int i = 0; i < kap; i++) { lista[i] = nullptr; }
}

Lista& Lista::dodaj(Cvor* c, int zavrsni) {
	if (zavrsni < kap) {
		if (lista[zavrsni] == nullptr)
			lista[zavrsni] = c;
		else {
			Cvor *k = lista[zavrsni];
			while (k->sledeci) { k = k->sledeci; }
			k->sledeci = c;
		}

	}
	else {
		Lista pom(kap + zavrsni);
		for (int i = 0; i < kap; i++) {
			pom.lista[i] = lista[i];
		}
		for (int i = kap; i < pom.kap; i++) { pom.lista[i] = nullptr; }
		if (pom.lista[zavrsni] == nullptr) {
			pom.lista[zavrsni] = c;
		}
		else {
			Cvor *k = pom.lista[zavrsni];
			while (k->sledeci) { k = k->sledeci; }
			k->sledeci = c;
		}
		for (int i = 0; i < kap; i++) {
			if (lista[i]) {
				Cvor *k = lista[i];
				Cvor *stari = k;
				while (k) { stari = k; stari->sledeci = nullptr; k = k->sledeci; delete stari; }
			}
		}
		kap = pom.kap;
		delete[] lista;
		lista = pom.lista;
	}
	return *this;
}

Lista& Lista::trazi(string trazena) {
	int niz[10];
	int d = 0;
	bool nadjeni = false;
	bool nadjenpol = false;
	for (int i = 0; i < kap; i++) {
		if (lista[i] != nullptr) {
			Cvor *k;
			k = lista[i];
			while (k) {
				if (k->pod()->ul() == trazena) {
					for (int j = 0; j < d; j++) {
						if (niz[j] == i) nadjeni = true; break;
					}
					for (int j = 0; j < d; j++) {
						if (niz[j] == k->br()) nadjenpol = true;
					}
					if (!nadjeni) niz[d++] = i;
					if (!nadjenpol) niz[d++] = k->br();
				}
				k = k->sledeci;
			}
		}//if
	}//for
	if (d == 0) { throw Gnema(); }
	for (int k = 0; k < d; k++) { cout << niz[k] << ' '; }
	return *this;
}//fja

Lista& Lista::promenismerdela(int polazni, int zavrsni) {
	Cvor *k;
	bool np = false;
	bool nz = false;
	if (lista[zavrsni]) {
		nz = true;
		k = lista[zavrsni];
		while (k) {
			if (k->br() == polazni) {
				np = true;
				Podatak *p = new Podatak(k->pod()->duz(), k->pod()->brz(), k->pod()->ul());
				Cvor *cv = new Cvor(zavrsni, p);
				dodaj(cv, polazni);
				break;
			}
			k = k->sledeci;
		}
		izbacideo(polazni, zavrsni);
	}
	if (np && nz) {
		return *this;
	}
	else { throw Gcvor(); }

}

Lista& Lista::promenismerulici(string trazena) {
	int num = 0;
	for (int i = 0; i <kap; i++) {
		if (lista[i] != nullptr) {
			Cvor *k = lista[i];
			Cvor *stari = k;
			while (k) {
				if (k->pod()->ul() == trazena && !k->pr())
				{
					num++;
					if (k == lista[i]) {
						Podatak *p = new Podatak(k->pod()->duz(), k->pod()->brz(), k->pod()->ul());
						Cvor *cv = new Cvor(i, p, true);
						dodaj(cv, k->br());
						lista[i] = k->sledeci; stari = k; k = k->sledeci; stari->sledeci = nullptr; delete stari;
					}
					else {
						Podatak *p = new Podatak(k->pod()->duz(), k->pod()->brz(), k->pod()->ul());
						Cvor *cv = new Cvor(i, p, true);
						dodaj(cv, k->br());
						stari->sledeci = k->sledeci; stari = k; k = k->sledeci;  stari->sledeci = nullptr; delete stari;
					}
				}
				else {
					stari = k;
					k = k->sledeci;
				}
			}//while
		}//if
	}//for
	if (num == 0) { throw Gnema(); }
	return *this;
}

Lista& Lista::izbacideo(int pol, int zav) {
		bool np = false;
		bool nz = false;
		if (lista[zav]) {
			nz = true;
			Cvor *k = lista[zav];
			Cvor *stari = k;
			while (k) {
				if (k->br() == pol) {
					np = true;
					if (k == lista[zav])
						lista[zav] = k->sledeci;
					k->sledeci = nullptr;
					delete k;
					return *this;
				}
				else {
					stari->sledeci = k->sledeci;
					k->sledeci = nullptr;
					delete k;
					return*this;
				}
				stari = k;
				k = k->sledeci;
			}
		}
		if (np && nz) {
			return *this;
		}
		else
		{
			throw Gcvor();
		}
		return *this;
}

Lista& Lista::izbaciulicu(string trazena) {
	int num = 0;
	for (int i = 0; i < kap; i++) {
		if (lista[i] != nullptr) {
			Cvor *k = lista[i];
			Cvor *stari = k;
			while (k) {
				if (k->pod()->ul() == trazena)
				{
					num++;
					if (k == lista[i]) {
						lista[i] = k->sledeci;
						stari = k;
						k = k->sledeci;
						stari->sledeci = nullptr;
						delete stari;
					}
					else {
						stari->sledeci = k->sledeci;
						stari = k; k = k->sledeci;
						stari->sledeci = nullptr;
						delete stari;
					}
				}
				else {
					stari = k;
					k = k->sledeci;
				}
			}//while
		}//if
	}//for
	if (num == 0) { throw Gnema(); }
	return *this;
}

Lista& Lista::izbaciulicuodmkav(string trazena) {
	int num = 0;
	for (int i = 0; i < kap; i++) {
		if (lista[i] != nullptr) {
			Cvor *k = lista[i];
			Cvor *stari = k;
			while (k) {
				if (k->pod()->ul() == trazena && k->br() <= i)
				{
					num++;
					if (k == lista[i]) {
						lista[i] = k->sledeci;
						stari = k;
						k = k->sledeci;
						stari->sledeci = nullptr;
						delete stari;
					}
					else {
						stari->sledeci = k->sledeci;
						stari = k; k = k->sledeci;
						stari->sledeci = nullptr;
						delete stari;
					}
				}
				else {
					stari = k;
					k = k->sledeci;
				}
			}//while
		}//if
	}//for
	if (num == 0) { throw Gnema(); }
	return *this;
}

Lista& Lista::izbaciulicuodvkam(string trazena) {
	int num = 0;
	for (int i = 0; i < kap; i++) {
		if (lista[i] != nullptr) {
			Cvor *k = lista[i];
			Cvor *stari = k;
			while (k) {
				if (k->pod()->ul() == trazena && k->br()>i)
				{
					if (k == lista[i]) {
						lista[i] = k->sledeci;
						stari = k; k = k->sledeci;
						stari->sledeci = nullptr;
						delete stari;
					}
					else {
						stari->sledeci = k->sledeci;
						stari = k; k = k->sledeci;
						stari->sledeci = nullptr;
						delete stari;
					}
				}
				else {
					stari = k;
					k = k->sledeci;
				}
			}//while
		}//if
	}//for
	if (num == 0) { throw Gnema(); }
	return *this;
}

Lista& Lista::formirajm() {
	Cvor* k;
	a = new float*[kap];
	for (int i = 0; i<kap; i++) {
		a[i] = new float[kap];
	}
	for (int i = 1; i < kap; i++) {
		for (int j = 1; j < kap; j++) {
			a[j][i] = beskonacno;
			if (lista[i]) {
				k = lista[i];
				while (k) {
					if (k->br() == j) {
						a[j][i] = k->pod()->duz() / k->pod()->brz();
						break;
					}
					else {
						k = k->sledeci;
						a[j][i] = beskonacno;
					}//else
				}//while
			}
		}//forj
	}//fori
	return *this;
}//fja

Lista&  Lista::formirajt() {
	Cvor* k;
	t = new int*[kap];
	for (int i = 0; i<kap; i++) {
		t[i] = new int[kap];
	}
	for (int i = 1; i < kap; i++) {
		for (int j = 1; j < kap; j++) {
			t[j][i] = 0;
			if (lista[i]) {
				k = lista[i];
				while (k) {
					if (k->br() == j)
					{
						t[j][i] = j; break;
					}
					else { k = k->sledeci; t[j][i] = 0; }
				}
			}
		}//forj
	}//fori
	return *this;
}//fja

Lista& Lista::flojd() {
	formirajm();
	formirajt();
	for (int k = 1; k < kap; k++)
		for (int i = 1; i < kap; i++)
			for (int j = 1; j < kap; j++) {
				if (a[i][j]>(a[i][k] + a[k][j])) {
					t[i][j] = t[k][j];
					a[i][j] = a[i][k] + a[k][j];
				}
			}
	return *this;
}

float Lista::path(int i, int j) {
	float vreme = 0;
	Cvor *k = lista[j];
	if (i == j) {
		return vreme;
	}
	else {
		if (t[i][j] == 0) { throw Gput(); }
		else {
			int nj = t[i][j];
			vreme += a[i][j];
			if (lista[j]) {
				while (k) {
					if (k->br() == t[i][j]) {
						break;
					}
					k = k->sledeci;
				}
			}
			path(i, t[i][j]);
			if (k != nullptr) {
				cout << k->pod()->ul() << ' ';
			}
		}
	}
	return vreme;
}

int Lista::nadjikubr(string trazena, int kubr) {
	int num = 0;
	struct Element {
		int polazni;
		int zavrsni;
		float duzina;
		Element *sledi;
		Element(int p, int z, float d) { polazni = p; zavrsni = z; duzina = d; sledi = nullptr; }
		bool operator< (Element& el) { return polazni < el.polazni; }
	};
	int  c;
	list<Element> listica;
	for (int i = 0; i < kap; i++) {
		if (lista[i] != nullptr) {
			Cvor *k;
			k = lista[i];
			while (k) {
				if (k->pod()->ul() == trazena) {
					num++;
					Element *e = new Element(k->br(), i, k->pod()->duz());
					listica.push_back(*e);
				}
				k = k->sledeci;
			}
		}//if
	}//for
	listica.sort();
	int suma = 0;
	for (list<Element>::const_iterator citer = listica.begin(); citer != listica.end(); citer++) {
		suma += (*citer).duzina;
		if (suma > kubr * 20) {
			int c = (*citer).polazni;
			return c;
		}
	}
	if (suma <= kubr * 20) { throw Gbroj(); }
}