#define _CRT_SECURE_NO_WARNINGS
#define PATHDS "D:\\ds.dat"
#include <stdio.h>
typedef struct elementds{
	int broj;
	char ime[10];
	int izbrisan;
	int prethodni;
	int sledeci;
} ELEMENTDS;
ELEMENTDS dodajElementDS();
void ubaciNaPocetakDS();
void ubaciNaPocetakDSS();
void ubaciNaKrajDS();
void ubaciNaKrajDSS();
void izbaciSaPocetkaDS();
void izbaciSaKrajaDS();
void prikaziDS();
void prikaziUnazadDS();
void brojElemenataDS();
void obrisiDS();
void sortirajDS();