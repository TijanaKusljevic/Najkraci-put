# ifndef PODATAK_H
# define PODATAK_H

#include <string>
#include <iostream>
using namespace std;

class Podatak {
	float duzina, brzina;
	string ulica;
public:
	~Podatak() {}
	Podatak(float duz, float brz, string ul) { duzina = duz; brzina = brz; ulica = ul; }
	float duz() { return duzina;}
	float brz() { return brzina; }
	string ul() { return ulica; }
	friend ostream& operator<<(ostream& it, Podatak& p) { it << p.duzina << " " << p.brzina << " "<<p.ulica << endl;  return it; }
};

#endif
