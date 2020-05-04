//Uebung 1 Zahlen genererieren und sortieren
//Autor: Annika Huebner

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void woerter_einlesen(FILE *infile, char *woerter[], int MAXWORT, int *numworte, int MIN){ //Ausgelagerte Funktion
  	char puffer[MAXWORT];
	int nw=0;
 	while(fgets(puffer,MAXWORT,infile)){
		puffer[strlen(puffer)-1]='\0';
		woerter[nw]=strdup(puffer);
		if(strlen(woerter[nw]>=MIN)
			nw++;
    	}
	*numworte=nw;
}

int cmpAZ(const void *p1, const void *p2){
	char *s1 =*((char **)p1);
	char *s2=*((char **)p2);
	return strcmp(s1,s2);
}

void woerter_AZ(char *woerter[], int MAXWORT, int MIN, int MAX, int numworte){
	qsort(woerter, numworte, sizeof(woerter[0]), cmpAZ);
}

void woerter_ausgabe(char *woerter[], int numworte){
	int i=0;
	for(i=0; i<20;i++)
		printf("Index: %d, Wort: %s \n", i, woerter[i]);
	for(i=numworte; i>(numworte-20);i--)
		printf("Index: %d, Wort: %s \n", i, woerter[i]);
}

int cmpdrei(const void *p1, const void *p2){
	char *s1 =*((char **)p1[2]);
	char *s2=*((char **)p2[2]);
	return strcmp(s1,s2);
}
void woerter_dritter_buchstabe(char *woerter[], int numworte){
	qsort(woerter, numworte, sizeof(woerter[0]), cmpdrei);
}

int cmplaenge(const void *p1, const void *p2){
	int e1 =srtlen(*((char **)p1));
	int e2=strlen(*((char **)p2));
	return e1-e2;
}
void woerter_laenge(char *woerter[], int numworte){
	qsort(woerter, numworte, sizeof(woerter[0]), cmplaenge);

int main(){

enum {
	MAXWORT =250000 ,
	MIN= 4,
	MAX= 60,
};


char *woerter[MAXWORT];
int num_worte=0;
FILE *infile; 
char infilename[] = "dict-american.txt";
unsigned int i=0;

//Datei oeffnen
if((infile =fopen(infilename, "r")) == NULL) {
	fprintf(stderr, " Fehler: Datei kann nicht geöffnet werden \n");
	return 1;
}
//Woerter einlesen
printf("Datei wird eingelesen \n");
woerter_einlesen(infile, woerter, MAXWORT,&num_worte, MIN);
fclose(infile);
printf("Wörter eingelesen: %d \n", num_worte);

//Testausgabe
for(i=0; i<20;i++)
	printf("%s \n", woerter[i]);

//Woerter von A-Z sortieren
woerter_AZ(woerter,MAXWORT, MIN, MAX, num_worte);
//Ausgabe 1. 20 und letzen 20
woerter_ausgabe(woerter,num_worte);
//Woerter nach dem 3. Zeichen sortieren
woerter_dritter_buchstabe(woerter, num_worte)
woerter_ausgabe(woerter,num_worte);
//Nach Wortlaenge sortieren
woerter_laenge(woerter, num_worte)
woerter_ausgabe(woerter, num_worte);


return 0;
    
}
