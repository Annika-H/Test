//Uebung 1 Zahlen genererieren und sortieren
//Autor: Annika Huebner

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
// #include "funktionen.h"


void zahlenerzeugen(unsigned int ptzahlen[], int anzahl, int Obere, int Untere ) {
	srand(time(NULL));
	int i;
	for (i=0; i<anzahl; i++){
	ptzahlen[i]=(rand() % (Obere - Untere +1))+Untere;

}
void zahlen_ausgabe(unsigned int  zahlen[], int anzahl, int zproz){
	int i=0, k;
	for(k=0; k<anzahl; k++){
		printf("%d",zahlen[k]);
		i++;
		if(i==9){
			printf("\n");
			i=0;
			}
	}
}

int comp_auf(const void *p1, const void *p2){
	int e1=*((int *)p1);
	int e2=*((int *)p2);
	if(e1==e2) return 0;
	if(e1<e2) return -1;
	return +1;
}

int comp_ab(const void *p1, const void *p2){
	int e1=*((int *)p1);
	int e2=*((int *)p2);
	if(e1==e2) return 0;
	if(e1>e2) return -1;
	return +1;
}

void zahlen_auf(unsigned int  zahlen[], int anzahl){
	qsort(zahlen, anzahl, sizeof(int), comp_auf);
}

void zahlen_ab(unsigned int  zahlen[], int anzahl){
	qsort(zahlen, anzahl, sizeof(int), comp_ab);
}

int main(){

enum {
	anzahl = 500,
	Ugrenze = 100,
	Ogrenze = 1000,
	ZahlenpZeile = 10
};

unsigned int zahlen[anzahl];

	//Random Zahlen zwischen 100-1000 erstellen
	zahlenerzeugen(zahlen, anzahl, Ogrenze, Ugrenze);

	//Zahlen  unsortiert ausgeben
	printf("Unsortiert:\n");
	zahlen_ausgabe(zahlen, anzahl, ZahlenpZeile);

	//Zahlen aufsteigend sortieren
	zahlen_auf(zahlen, anzahl);
	//Zahlen  aufsteigend sortiert ausgeben
	printf("Aufsteigend:\n");
	zahlen_ausgabe(zahlen, anzahl, ZahlenpZeile);

	//Zahlen absteigend sortieren
	zahlen_ab(zahlen, anzahl);
	//Zahlen  bsteigend sortiert ausgeben
	printf("Absteigend:\n");
	zahlen_ausgabe(zahlen, anzahl, ZahlenpZeile);

return 0;
}
