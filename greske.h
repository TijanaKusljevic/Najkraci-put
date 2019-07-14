#ifndef GRESKE_H
#define GRESKE_H


#include <iostream>
using namespace std;

class Gdat {};
inline ostream& operator<< (ostream& it, const Gdat&) {
	return it << "\n datoteka nije lepo povezana \n" << endl;
}

class Gnema{};
inline ostream& operator<< (ostream& it, const Gnema&) {
	return it << "\n trazite nepostojecu ulicu\n" << endl;
}

class Gbroj{};
inline ostream& operator<<(ostream& it, const Gbroj&) {
	return it << "\n trazite kucni broj koji ne postoji u navedenoj ulici \n";
}

class Gcvor{};
inline ostream& operator<<(ostream& it, const Gcvor&) {
	return it << "\n trazena sekvenca ne postoji \n";
}

class Gopcija{};
inline ostream& operator<<(ostream& it, const Gopcija&) {
	return it << "\n izabrali ste nepostojecu opciju \n";
}

class Gput{};
inline ostream& operator<<(ostream& it, const Gput&) {
	return it << "\n nema puta izmedju trazenih cvorova\n";
}

#endif
