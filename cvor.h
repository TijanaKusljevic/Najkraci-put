#ifndef CVOR_H
#define CVOR_H

#include "podatak.h"

class Cvor {
	int broj;
	Podatak* podatak;
	bool preb;
public:
	Cvor* sledeci;
	~Cvor() { delete podatak; }
	Cvor(int br, Podatak* pod = nullptr, bool p = false) { podatak = pod; broj = br; sledeci = nullptr; preb = p; }
	bool pr() { return preb; }
	void postavi() { preb = true; }
	int br() { return broj; }
	Cvor* sled() { return sledeci; }
	Podatak* pod() { return podatak; }
	friend ostream& operator<<(ostream& it, Cvor& p) { return it << p.broj << " " << *p.podatak << endl; }
};

#endif

