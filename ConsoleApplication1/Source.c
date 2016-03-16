#include "HeaderJS.h"
#include "HeaderDS.h"

void pritisniEnterZaNastavak(){
	char ch;
	fflush(stdin);
	printf("\nPritisnite enter za nastavak....");
	scanf("%c", &ch);
	fflush(stdin);
}

void Meni(){
	FILE * datotekaJS;
	FILE * datotekaDS;
	int yo=20, yo1=30, yo2=40;
	while (yo != 0){
		printf("========== GLAVNI MENI ==========\n\n");
		printf("1. Datoteka kao jednostruko-spregnuta lista\n");
		printf("2. Datoteka kao dvostruko-spregnuta lista\n");
		printf("0. IZLAZ\n\n");
		printf("Izaberite opciju.\n");
		scanf("%d", &yo);
		fflush(stdin);

		switch (yo){
			//=========================================================================
		case 1: //JEDNOSTRUKO-SPREGNUTA LISTA
			datotekaJS = fopen(PATHJS, "wb");
			fclose(datotekaJS);
			while (yo1 != 0){
				printf("\n=============================\n");
				printf("DATOTEKA KAO JEDNOSTRUKO-SPREGNUTA LISTA\n");
				printf("=============================\n\n");
				printf("1. Ubaci element na pocetak\n"); 
				printf("2. Ubaci element na kraj\n");    
				printf("3. Izbaci element sa pocetka\n");
				printf("4. Izbaci element sa kraja\n");  
				printf("5. Sortiraj\n");				 
				printf("6. Prikazi\n");					
				printf("7. Obrisi\n");					
				printf("8. Prikazi broj elemenata\n");	
				printf("9. Prikazi unazad\n");
				printf("10.Pronadji igraca\n");
				printf("0. Nazad\n\n");
				printf("Izaberite opciju.\n");
				scanf("%d", &yo1);
				printf("\n");

				switch (yo1){

				case 1: ubaciNaPocetakJS();
					pritisniEnterZaNastavak();
					break;

				case 2: ubaciNaKrajJS();
					pritisniEnterZaNastavak();
					break;

				case 3: izbaciSaPocetkaJS();
					pritisniEnterZaNastavak();
					break;

				case 4: izbaciSaKrajaJS();
					pritisniEnterZaNastavak();
					break;

				case 5: sortirajJS();
					pritisniEnterZaNastavak();
					break;

				case 6: prikaziJS();
					pritisniEnterZaNastavak();
					break;

				case 7: obrisiJS();
					pritisniEnterZaNastavak();
					break;

				case 8: brojElemenataJS();
					pritisniEnterZaNastavak();
					break;

				case 9: prikaziUnazadJS();
					pritisniEnterZaNastavak();
					break;

				case 10: pronadji();
					pritisniEnterZaNastavak();
					break;

				case 0:	break;

				default: printf("Ne postoji ta opcija!\n");
					pritisniEnterZaNastavak();
					break;
				}
			}
			break;//kraj
		
			//SKLONI OVO KAD BUDES RADIO DSL<<
			//^^^^^^^
		//^^^^^^^
			//=============================================================================
		case 2:	//DVOSTRUKO-SPREGNUTA LISTA
			datotekaDS = fopen(PATHDS, "wb");
			fclose(datotekaDS);
			while (yo2 != 0){
				printf("=============================\n");
				printf("DATOTEKA KAO DVOSTRUKO-SPREGNUTA LISTA\n");
				printf("=============================\n");
				printf("\nOPCIJE:\n");
				printf("1. Ubaci element na pocetak\n");
				printf("2. Ubaci element na kraj\n");
				printf("3. Izbaci element sa pocetka\n");
				printf("4. Izbaci element sa kraja\n");
				printf("5. Prikazi datoteku\n");
				printf("6. Prikazi datoteku unazad\n");
				printf("7. Obrisi sve\n");
				printf("8. Prikazi broj elemenata datoteke\n");
				printf("9. Sortiraj datoteku\n");
				printf("0. Nazad\n\n");
				printf("Vasa opcija?\n");
				scanf("%d", &yo2);
				printf("\n");

				switch (yo2){

				case 1: ubaciNaPocetakDS();			
					pritisniEnterZaNastavak();
					break;

				case 2: ubaciNaKrajDS();
					pritisniEnterZaNastavak();
					break;

				case 3: izbaciSaPocetkaDS();
					pritisniEnterZaNastavak();
					break;

				case 4: izbaciSaKrajaDS();
					pritisniEnterZaNastavak();
					break;

				case 5: prikaziDS();				
					pritisniEnterZaNastavak();
					break;

				case 6: prikaziUnazadDS();
					pritisniEnterZaNastavak();
					break;

				case 7: obrisiDS();
					pritisniEnterZaNastavak();
					break;

				case 8: brojElemenataDS();
					pritisniEnterZaNastavak();
					break;

				case 9: sortirajDS();
					pritisniEnterZaNastavak();
					break;

				case 0: break;

				default: printf("Ta opcija ne postoji!\n");
					pritisniEnterZaNastavak();
					break;
				}
			}
			break;//kraj
		case 0: printf("\n====KRAJ====\n\n");
			break;
		default: printf("Ta opcija ne postoji!\n");
			pritisniEnterZaNastavak();
			break;

		}

	}
}


int main(void){
	Meni();
	return 0;
}
