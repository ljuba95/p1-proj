#include "HeaderJS.h"


ELEMENT dodajElement(){
	ELEMENT noviEl;
	printf("Broj: ");
	scanf("%d", &noviEl.broj);
	printf("Ime: ");
	scanf("%s", &noviEl.ime);
	noviEl.izbrisan = 0;

	return noviEl;
}


void obrisiJS(){
	FILE * datoteka = fopen(PATHJS, "wb");
	if (datoteka == NULL){
		printf("Greska!\n");
		return;
	}
	printf("\nSvi unosi su obrisani.\n");
	fclose(datoteka);
	return 0;
}
void brojElemenataJS(){
	ELEMENT ele;
	FILE * datoteka = fopen(PATHJS, "rb");
	int brel=0;
	if (datoteka == NULL){
		printf("Greska!\n");
		return;
	}
	while (fread(&ele, sizeof(ELEMENT), 1, datoteka) != 0){
		if (ele.izbrisan == 0){
			brel++;
		}
	}
	printf("Broj elemenata u datoteci je: %d.\n", brel);
	fclose(datoteka);
	return 0;

}

void prikaziJS(){
	ELEMENT ele;
	int i = 0;
	FILE * datoteka = fopen(PATHJS, "rb");
	if (datoteka == NULL){
		return;
	}
	
	while(fread(&ele, sizeof(ELEMENT), 1, datoteka) != 0){
		if (ele.izbrisan == 0){
			i++;
		}
	}
	if (i == 0){
		printf("Datoteka je prazna.\n");
	}else{
		printf("=====PRIKAZ=====\n");
		rewind(datoteka);
		while (fread(&ele, sizeof(ELEMENT), 1, datoteka) != 0){
			if (ele.izbrisan == 0){
				printf("Broj: %d\t Ime: %s\n", ele.broj, ele.ime);
			}
		}
	}
	fclose(datoteka);
}
void prikaziUnazadJS(){
	ELEMENT ele;
	int i = 0;
	FILE * datoteka = fopen(PATHJS, "rb");
	if (datoteka == NULL){
		return;
	}
	while (fread(&ele, sizeof(ELEMENT), 1, datoteka) != 0){
		if (ele.izbrisan == 0){
			i++;
		}
	}
	if (i == 0){
		printf("Datoteka je prazna.\n");
	}
	else{
		printf("=====PRIKAZ UNAZAD=====\n");
		fseek(datoteka, (signed)sizeof(ELEMENT)*(-1), SEEK_END);
		while (fread(&ele, sizeof(ELEMENT), 1, datoteka) != 0){
			if (ele.izbrisan == 0){
				printf("Broj: %d\t Ime: %s\n", ele.broj, ele.ime);
			}
			fseek(datoteka, (signed)sizeof(ELEMENT)*(-2), SEEK_CUR);
		}
	}
	fclose(datoteka);
}


void ubaciNaPocetakJS() {
	
	
	char opcija = ' ';
	
	printf("Ubacivanje na pocetak...\n");
	while (opcija != 'n') {
		ubaciNaPocetakJSS();
		printf("\nNastavak? (y/n)\n");
		fflush(stdin);
		opcija = getchar();

	}

	return 0;
}
void ubaciNaPocetakJSS(){
	ELEMENT novi, yo;
	int i, brEl;
	FILE * datoteka = fopen(PATHJS, "r+b");
	if (datoteka == NULL) {
		return 1;
	}
	fseek(datoteka, 0, SEEK_END);
	brEl = ftell(datoteka) / sizeof(ELEMENT);
	if (brEl == 0) {
		novi = dodajElement();
		fwrite(&novi, sizeof(ELEMENT), 1, datoteka);
	}
	else {

		for (i = 1; i <= brEl; i++) {
			fseek(datoteka, sizeof(ELEMENT)*(brEl - i), SEEK_SET);
			fread(&yo, sizeof(ELEMENT), 1, datoteka);
			fseek(datoteka, sizeof(ELEMENT)*(brEl - i + 1), SEEK_SET);
			fflush(datoteka);
			fwrite(&yo, sizeof(ELEMENT), 1, datoteka);
			fflush(datoteka);
		}
		fseek(datoteka, 0, SEEK_SET);
		novi = dodajElement();
		fwrite(&novi, sizeof(ELEMENT), 1, datoteka);
	}
	fclose(datoteka);
}

void ubaciNaKrajJS(){
	char odg = ' ';
	ELEMENT novi;
	FILE * datoteka = fopen(PATHJS, "ab");
	if (datoteka == NULL){
		return;
	}
	printf("Ubacivanje na kraj....\n");
	fseek(datoteka, 0, SEEK_END);
	while (odg != 'n'){
		novi = dodajElement();
		fwrite(&novi, sizeof(ELEMENT), 1, datoteka);
		printf("\nNastavak? (y/n)\n");
		fflush(stdin);
		scanf("%c", &odg);
	}
	fclose(datoteka);
	return 0;
}
void izbaciSaPocetkaJS(){
	ELEMENT ele;
	int brel;
	int i = 0;
	FILE * datoteka = fopen(PATHJS, "r+b");
	fseek(datoteka, 0, SEEK_END);
	brel = ftell(datoteka) / sizeof(ELEMENT);
	if (brel == 0){
		printf("Datoteka je prazna!\n");
		fclose(datoteka);
		return 0;
	}
	else if (brel == 1){
		rewind(datoteka);
		fread(&ele, sizeof(ELEMENT), 1, datoteka);
		if (ele.izbrisan == 0){
			rewind(datoteka);
			ele.izbrisan = 1;
			fwrite(&ele, sizeof(ELEMENT), 1, datoteka);
			fclose(datoteka);
			return 0;
		}
		else{
			printf("Datoteka je prazna\n");
			fclose(datoteka);
			return 0;
		}
	}
	while (brel-i>0){
		fseek(datoteka, sizeof(ELEMENT)*i, SEEK_SET);
		fread(&ele, sizeof(ELEMENT), 1, datoteka);
		if (ele.izbrisan == 0){
			fseek(datoteka, sizeof(ELEMENT)*i, SEEK_SET);
			ele.izbrisan = 1;
			fflush(datoteka);
			fwrite(&ele, sizeof(ELEMENT), 1, datoteka);
			fclose(datoteka);
			break;
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
void izbaciSaKrajaJS(){
	ELEMENT yo;
	FILE * datoteka = fopen(PATHJS, "r+b");
	int brel;
	int i = -1;
	fseek(datoteka, 0, SEEK_END);
	brel = ftell(datoteka) / sizeof(ELEMENT);
	if (brel == 0){
		printf("Datoteka je prazna!\n");
		fclose(datoteka);
		return 0;
	}
	else if (brel == 1){
		rewind(datoteka);
		fread(&yo, sizeof(ELEMENT), 1, datoteka);
		if (yo.izbrisan == 0){
			rewind(datoteka);
			yo.izbrisan = 1;
			fwrite(&yo, sizeof(ELEMENT), 1, datoteka);
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
		fseek(datoteka, (signed)sizeof(ELEMENT)*i, SEEK_END);
		fread(&yo, sizeof(ELEMENT), 1, datoteka);
		if (yo.izbrisan == 0){
			yo.izbrisan = 1;
			fseek(datoteka, (signed)sizeof(ELEMENT)*i, SEEK_END);
			fflush(datoteka);
			fwrite(&yo, sizeof(ELEMENT), 1, datoteka);
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
void sortirajJS(){
	int i, j, brel;
	ELEMENT jedan, dva;
	FILE *datoteka;
	datoteka = fopen(PATHJS, "r+b");
	if (datoteka == NULL){
		printf("Dogodila se greska!\n");
		return;
	}
	printf("Sortiranje datoteke.... \n");
	fseek(datoteka, 0, SEEK_END);
	brel = ftell(datoteka) / sizeof(ELEMENT);

	for (i = 0; i<brel - 1; i++){
		for (j = i + 1; j<brel; j++){
			fseek(datoteka, sizeof(ELEMENT)*i, SEEK_SET);
			fread(&jedan, sizeof(ELEMENT), 1, datoteka);
			fseek(datoteka, sizeof(ELEMENT)*j, SEEK_SET);
			fread(&dva, sizeof(ELEMENT), 1, datoteka);
			if (jedan.broj>dva.broj){
				fseek(datoteka, sizeof(ELEMENT)*i, SEEK_SET);
				fwrite(&dva, sizeof(ELEMENT), 1, datoteka);
				fseek(datoteka, sizeof(ELEMENT)*j, SEEK_SET);
				fwrite(&jedan, sizeof(ELEMENT), 1, datoteka);
				fflush(datoteka);
			}
		}
	}
	fclose(datoteka);
}
void pronadji(){
	ELEMENT ele;
	char ime[10];
	char odg = ' ';
	int broj,pronadjen=0;
	FILE * datoteka = fopen(PATHJS, "rb");
	if (datoteka == NULL){
		return;
	}

	if (fread(&ele, sizeof(ELEMENT), 1, datoteka) == 0){
		printf("Datoteka je prazna.\n");
	}
	else{
		printf("Unesite ime igraca:\n");
		fflush(stdin);
		scanf("%s", &ime);
		printf("Trazim igrace...\n");
		rewind(datoteka);
		while (fread(&ele, sizeof(ELEMENT), 1, datoteka) != 0){
			if (ele.izbrisan == 0 && strcmp(ime,ele.ime)==0){
				printf("Pronadjen ----> Broj: %d\t Ime: %s\n", ele.broj, ele.ime);
				pronadjen = 1;
				}
			}
		}
	if (pronadjen == 0){
		printf("Nije pronadjen igrac pod imenom %s.\n\n", ime);
		printf("Da li zelite da trazite po broju?(y/n)\n");
		fflush(stdin);
		scanf("%c", &odg);
		if (odg == 'y'){
			printf("Unesite broj igraca:\n");
			scanf("%d", &broj);
			rewind(datoteka);
			printf("Trazim igrace...\n");
			while (fread(&ele, sizeof(ELEMENT), 1, datoteka) != 0){
				if (ele.izbrisan == 0 && broj==ele.broj){
					printf("Pronadjen ----> Broj: %d\t Ime: %s\n", ele.broj, ele.ime);
					pronadjen = 1;
				}

			}
			if (pronadjen == 0){
				printf("Nije pronadjen igrac pod brojem %d", broj);
			}
		}
	}
	
	fclose(datoteka);
	return 0;
}

//int status(FILE * f) {
//	printf("ftell:%d, feof:%s\n", ftell(f)/sizeof(ELEMENT), feof(f) != 0 ? "true" :
//		"false");
//}
//void unosLIFOv2(){
//	ELEMENT novi,yo;
//	int brel;
//	char odg = ' ';
//	FILE * datoteka = fopen(PATH, "w+b");
//	if (datoteka == NULL){
//		return;
//	}
//	while (odg!='n'){
//		fseek(datoteka, 0, SEEK_END);
//		brel = ftell(datoteka) / sizeof(ELEMENT);
//		if (brel != 0){
//			fseek(datoteka, (-1)*(signed)sizeof(ELEMENT), SEEK_END);
//		}
//		for (int i = 1; i <= brel; i++){
//			fread(&yo, sizeof(ELEMENT), 1, datoteka);
//			fwrite(&yo, sizeof(ELEMENT), 1, datoteka);
//			fflush(datoteka);
//			if (ftell(datoteka)/sizeof(ELEMENT) == 2){
//				fseek(datoteka, (-2)*(signed)sizeof(ELEMENT), SEEK_CUR);
//			}
//			else{
//				fseek(datoteka,(-3)*(signed)sizeof(ELEMENT), SEEK_CUR);
//			}
//		}
//		novi = dodajElement();
//		fwrite(&novi, sizeof(ELEMENT), 1, datoteka);
//		fflush(datoteka);
//		printf("\n?");
//		fflush(stdin);
//		scanf("%c", &odg);
//	}
//	fclose(datoteka);}

//DVOSTRUKO SPREGNUTA====================================

