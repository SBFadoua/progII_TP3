#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

char * ADN_Sequences(int N){
	char *T;
	int i;
	T=(char *)malloc((N+1)*sizeof(char));
	int k;
	int nba=0, nbc=0, nbt=0, nbg=0;
	int countA=round(0.1*N); // Arrondir aux entiers les plus proche
	int countT=round(0.3*N);
	int countG=round(0.5*N);
	int countC=N - countA - countG - countT;
	char Tab[4]={'A','T','C','G'};
	srand(time(NULL));// Initialiser le générateur de nombres aléatoires
	for (i=0;i<N;i++){
		k = rand()%4; // choisir aléatoirement un nucléotide
		if (k==0 && nba<countA){
			T[i]=Tab[k];
			nba++;
		}
		else if (k==1 && nbt<countT){
			T[i]=Tab[k];
			nbt++;
		}
		else if (k==2 && nbc<countC){
			T[i]=Tab[k];
			nbc++;
		}
		else if (k==3 && nbg<countG){
			T[i]=Tab[k];
			nbg ++;
		}
		else {
			//k = rand()%4;
			i--;
		}		
	}
	T[N] = '\0';
	return T; 
}

//************************************** Question 2 **********************************

int compte_nucleotide(char * mot){
	int i;
	int nba=0, nbc=0, nbg=0, nbt=0;
	int n=strlen(mot);
	for(i=0;i<n;i++){
		if(mot[i]=='A')
			nba++;
		if(mot[i]=='G')
			nbg++;
		if(mot[i]=='C')
			nbc++;
		if(mot[i]=='T')
			nbt++;
		}
	if( nba<2 && nbc<2 && nbt<2 && nbg<2)
		return 1;
	else 
		return 0;
}
void isogram(char * ADN, int N){
	int c; int i;
	char mot[3];
	int start=0;
	int end=3;
	char *T;
	int l,j;
	// Boucle pour parcourir la séquence d'ADN
	do{
		for (i = 0; i < 3; i++) {
            mot[i] = ADN[start + i];
        }
        mot[3] = '\0';
		c=compte_nucleotide(mot);
		if(c==1){ // nucléo apparait une fois
			printf("%s",mot);
			printf("\t");}
		start+=1; //déplacer la séq
		end+=1;
	} while (end<=N); // répéter jusqu'a la fin de la séquence
}


void affiche(char *t,int N){
	 if (t != NULL) { // Vérifie si la séquence a été générée avec succès
        printf("%s", t); // Affiche la séquence d'ADN

    }
}
int main() {
	char* T; 
	int *tab;
	int N,M; 
	int k;
	// exemple de test de la série en cas de besoin
	/* T="ATCGTTTAGCTATATTTGC";
	N=strlen(T); */
	
	printf("Entrer la taille du tableau ");
	scanf("%d",&N);
	T=ADN_Sequences(N);	
	printf("La sequence generee est:\n");
	affiche(T,N);
	printf("\n\nLa sequence des heterogrammes:\n");
	// test de la fonction isogram 
  	isogram(T,N);

	return 0;
}
