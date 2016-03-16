#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATHJS "D:\\yo.dat"

typedef struct element{
	int broj;
	char ime[10];
	int izbrisan;
} ELEMENT;

void pritisniEnterZaNastavak();
void Meni();
ELEMENT dodajElement();
void obrisiJS();
void brojElemenataJS();
void prikaziJS();
void prikaziUnazadJS();
void ubaciNaPocetakJS();
void ubaciNaPocetakJSS();
void ubaciNaKrajJS();
void izbaciSaPocetkaJS();
void izbaciSaKrajaJS();
void sortirajJS();

