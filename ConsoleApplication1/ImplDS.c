#include "HeaderDS.h"

ELEMENTDS dodajElementDS(){
	ELEMENTDS noviEl;
	printf("Broj: ");
	scanf("%d", &noviEl.broj);
	printf("Ime: ");
	scanf("%s", &noviEl.ime);
	noviEl.izbrisan = 0;

	return noviEl;
}

void ubaciNaPocetakDS() {
	char opcija = ' ';
	printf("Ubacivanje na pocetak...\n");
	while (opcija != 'n') {
		ubaciNaPocetakDSS();
		printf("\nNastavak? (y/n)\n");
		fflush(stdin);
		opcija = getchar();
	}
	return 0;
}

void ubaciNaPocetakDSS(){
	ELEMENTDS novi, yo;
	int i, brEl, j = 0, k = 2;
	FILE * datoteka = fopen(PATHDS, "r+b");
	if (datoteka == NULL) {
		return 1;
	}
	fseek(datoteka, 0, SEEK_END);
	brEl = ftell(datoteka) / sizeof(ELEMENTDS);
	if (brEl == 0) {
		novi = dodajElementDS();
		novi.prethodni = -1;
		novi.sledeci = 1;
		fwrite(&novi, sizeof(ELEMENTDS), 1, datoteka);
	}
	else {
		for (i = 1; i <= brEl; i++) {
			fseek(datoteka, sizeof(ELEMENTDS)*(brEl - i), SEEK_SET);
			fread(&yo, sizeof(ELEMENTDS), 1, datoteka);
			yo.prethodni++;
			yo.sledeci++;
			fseek(datoteka, sizeof(ELEMENTDS)*(brEl - i + 1), SEEK_SET);
			fflush(datoteka);
			fwrite(&yo, sizeof(ELEMENTDS), 1, datoteka);
			fflush(datoteka);
		}
		fseek(datoteka, 0, SEEK_SET);
		novi = dodajElementDS();
		novi.prethodni = -1;
		novi.sledeci = 1;
		fwrite(&novi, sizeof(ELEMENTDS), 1, datoteka);
	}
	fclose(datoteka);
	return;

}
void prikaziDS(){
	ELEMENTDS ele;
	int i = 0;
	FILE * datoteka = fopen(PATHDS, "rb");
	if (datoteka == NULL){
		return;
	}
	fseek(datoteka, 0, SEEK_END);
	int brel = ftell(datoteka) / sizeof(ELEMENTDS);
	if (brel == 0){
		printf("Datoteka je prazna.\n");
		return 0;
	}
	else rewind(datoteka);

	while (fread(&ele, sizeof(ELEMENTDS), 1, datoteka) != 0){
		if (ele.izbrisan == 0){
			i++;
		}
	}
	if (i == 0){
		printf("Datoteka je prazna.\n");
	}
	else{
		printf("=====PRIKAZ=====\n");
		rewind(datoteka);
		while (fread(&ele, sizeof(ELEMENTDS), 1, datoteka) != 0){
			if (ele.izbrisan == 0){
				printf("Broj: %d\t Ime: %s \n", ele.broj, ele.ime);
			}
			fseek(datoteka, ele.sledeci*sizeof(ELEMENTDS), SEEK_SET);
		}
	}
	fclose(datoteka);
}
void ubaciNaKrajDS(){
	char opcija = ' ';
	printf("Ubacivanje na kraj...\n");
	while (opcija != 'n') {
		ubaciNaKrajDSS();
		printf("\nNastavak? (y/n)\n");
		fflush(stdin);
		opcija = getchar();
	}

	return 0;
}
void ubaciNaKrajDSS(){
	ELEMENTDS novi, yo;
	int brEl;
	FILE * datoteka = fopen(PATHDS, "r+b");
	if (datoteka == NULL) {
		return 1;
	}
	fseek(datoteka, 0, SEEK_END);
	brEl = ftell(datoteka) / sizeof(ELEMENTDS);
	if (brEl == 0) {
		novi = dodajElementDS();
		novi.prethodni = -1;
		novi.sledeci = 1;
		fwrite(&novi, sizeof(ELEMENTDS), 1, datoteka);
	}
	else {
		novi = dodajElementDS();
		fseek(datoteka, (signed)sizeof(ELEMENTDS)*(-1), SEEK_END);
		fread(&yo, sizeof(ELEMENTDS), 1, datoteka);
		novi.prethodni = yo.sledeci - 1;
		novi.sledeci = yo.sledeci + 1;
		fseek(datoteka, 0, SEEK_END);
		fwrite(&novi, sizeof(ELEMENTDS), 1, datoteka);

	}
	fclose(datoteka);

}
void izbaciSaPocetkaDS(){
	ELEMENTDS ele;
	int brel;
	int i = 0;
	FILE * datoteka = fopen(PATHDS, "r+b");
	if (datoteka == NULL){
		return;
	}
	fseek(datoteka, 0, SEEK_END);
	brel = ftell(datoteka) / sizeof(ELEMENTDS);
	if (brel == 0){
		printf("Datoteka je prazna!\n");
		return 0;
	}
	else if (brel == 1){
		rewind(datoteka);
		fread(&ele, sizeof(ELEMENTDS), 1, datoteka);
		if (ele.izbrisan == 0){
			rewind(datoteka);
			ele.izbrisan = 1;
			fwrite(&ele, sizeof(ELEMENTDS), 1, datoteka);
			fclose(datoteka);
			return 0;
		}
		else{
			printf("Datoteka je prazna\n");
			return 0;
		}
	}
	while (brel - i>0){
		fseek(datoteka, sizeof(ELEMENTDS)*i, SEEK_SET);
		fread(&ele, sizeof(ELEMENTDS), 1, datoteka);
		if (ele.izbrisan == 0){
			fseek(datoteka, sizeof(ELEMENTDS)*i, SEEK_SET);
			ele.izbrisan = 1;
			fflush(datoteka);
			fwrite(&ele, sizeof(ELEMENTDS), 1, datoteka);
			fclose(datoteka);
			return 0;
		}
		else i++;
		if (i == brel){
			printf("Datoteka je prazna.\n");
			fclose(datoteka);
			return 0;
		}
	}


	return 0;
}
void izbaciSaKrajaDS(){
	ELEMENTDS yo;
	FILE * datoteka = fopen(PATHDS, "r+b");
	if (datoteka == NULL){
		return;
	}
	int brel;
	int i = -1;
	fseek(datoteka, 0, SEEK_END);
	brel = ftell(datoteka) / sizeof(ELEMENTDS);
	if (brel == 0){
		printf("Datoteka je prazna!\n");
		fclose(datoteka);
		return 0;
	}
	else if (brel == 1){
		rewind(datoteka);
		fread(&yo, sizeof(ELEMENTDS), 1, datoteka);
		if (yo.izbrisan == 0){
			rewind(datoteka);
			yo.izbrisan = 1;
			fwrite(&yo, sizeof(ELEMENTDS), 1, datoteka);
			fclose(datoteka);
			return 0;
		}
		else{
			printf("Datoteka je prazna\n");
			fclose(datoteka);
			return 0;
		}
	}
	while (i + brel >= 0){
		fseek(datoteka, (signed)sizeof(ELEMENTDS)*i, SEEK_END);
		fread(&yo, sizeof(ELEMENTDS), 1, datoteka);
		if (yo.izbrisan == 0){
			yo.izbrisan = 1;
			fseek(datoteka, (signed)sizeof(ELEMENTDS)*i, SEEK_END);
			fflush(datoteka);
			fwrite(&yo, sizeof(ELEMENTDS), 1, datoteka);
			fclose(datoteka);
			return 0;
		}
		else i--;
		if (i + brel < 0){
			printf("Datoteka je prazna.\n");
			fclose(datoteka);
			return 0;
		}

	}
}
void prikaziUnazadDS(){
	ELEMENTDS ele;
	int i = 0;
	FILE * datoteka = fopen(PATHDS, "r+b");
	if (datoteka == NULL){
		return;
	}
	fseek(datoteka, 0, SEEK_END);
	int brel = ftell(datoteka) / sizeof(ELEMENTDS);
	if (brel == 0){
		printf("Datoteka je prazna.\n");
		return 0;
	}
	else rewind(datoteka);

	while (fread(&ele, sizeof(ELEMENTDS), 1, datoteka) != 0){
		if (ele.izbrisan == 0){
			i++;
		}
	}
	if (i == 0){
		printf("Datoteka je prazna.\n");
	}
	else{
		printf("=====PRIKAZ UNAZAD=====\n");
		fseek(datoteka, (signed)sizeof(ELEMENTDS)*(-1), SEEK_END);
		fread(&ele, sizeof(ELEMENTDS), 1, datoteka);
		if (ele.izbrisan == 0){
			printf("Broj: %d\t Ime: %s\n", ele.broj, ele.ime);
		}
		while (ele.prethodni != -1){
			fseek(datoteka, sizeof(ELEMENTDS)*ele.prethodni, SEEK_SET);
			fread(&ele, sizeof(ELEMENTDS), 1, datoteka);
			if (ele.izbrisan == 0){
				printf("Broj: %d\t Ime: %s\n", ele.broj, ele.ime);
			}

		}
	}
	fclose(datoteka);

	return 0;
}
void obrisiDS(){
	FILE * datoteka = fopen(PATHDS, "wb");
	if (datoteka == NULL){
		printf("Greska!\n");
		return;
	}
	printf("\nSvi unosi su obrisani.\n");
	fclose(datoteka);
	return 0;
}
void brojElemenataDS(){
	ELEMENTDS ele;
	FILE * datoteka = fopen(PATHDS, "rb");
	int brel = 0;
	if (datoteka == NULL){
		printf("Greska!\n");
		return;
	}
	while (fread(&ele, sizeof(ELEMENTDS), 1, datoteka) != 0){
		if (ele.izbrisan == 0){
			brel++;
		}
	}
	printf("Broj elemenata u datoteci je: %d.\n", brel);
	fclose(datoteka);
	return 0;

}
void sortirajDS(){
	int i, j, brel, drzac;
	ELEMENTDS jedan, dva;
	FILE *datoteka;
	datoteka = fopen(PATHDS, "r+b");
	if (datoteka == NULL){
		printf("Dogodila se greska!\n");
		return;
	}
	printf("Sortiranje datoteke.... \n");
	fseek(datoteka, 0, SEEK_END);
	brel = ftell(datoteka) / sizeof(ELEMENTDS);

	for (i = 0; i<brel - 1; i++){
		for (j = i + 1; j<brel; j++){
			fseek(datoteka, sizeof(ELEMENTDS)*i, SEEK_SET);
			fread(&jedan, sizeof(ELEMENTDS), 1, datoteka);
			fseek(datoteka, sizeof(ELEMENTDS)*j, SEEK_SET);
			fread(&dva, sizeof(ELEMENTDS), 1, datoteka);
			if (jedan.broj>dva.broj){
				drzac = jedan.prethodni;
				jedan.prethodni = dva.prethodni;
				dva.prethodni = drzac;
				drzac = jedan.sledeci;
				jedan.sledeci = dva.sledeci;
				dva.sledeci = drzac;
				fseek(datoteka, sizeof(ELEMENTDS)*i, SEEK_SET);
				fwrite(&dva, sizeof(ELEMENTDS), 1, datoteka);
				fseek(datoteka, sizeof(ELEMENTDS)*j, SEEK_SET);
				fwrite(&jedan, sizeof(ELEMENTDS), 1, datoteka);
				fflush(datoteka);
			}
		}
	}
	fclose(datoteka);
}

