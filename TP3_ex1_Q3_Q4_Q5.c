#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//************************************** Question 3**********************************

int * codon_start(char * ADN,int N){
	int i,j=0;
	int *ind;
	int n=1;
	ind=(int*) malloc(n*sizeof(int));
	for(i=0;i<N-2;i++){
		if((*(ADN+i)=='A')&&(*(ADN+i+1)=='T')&&(*(ADN+i+2)=='G')){
			ind[j]=i; // i+1 ?
			j++;
			n++;
			ind=(int*)realloc(ind, n*sizeof(int));
		}
	}
	ind[j]=-1;
	return ind;
}

//************************************** Question 4**********************************
int codon_stop(char *ADN,int i){
	int k;
	int j ;
	int N=strlen(ADN);
	
	for(j=i;j<N;j+=3){
		if(((*(ADN+j)=='T')&&(*(ADN+j+1)=='A')&&(*(ADN+j+2)=='A'))||((*(ADN+j)=='T')&&(*(ADN+j+1)=='A')&&(*(ADN+j+2)=='G'))||((*(ADN+j)=='T')&&(*(ADN+j+1)=='G')&&(*(ADN+j+2)=='A'))){
			k=j;
			break;
		}
	}
	if(k==-1)
		printf("\naucun codon STOP n'est trouve");
//	else
//		printf("\nle codon STOP est dans la position %d ",k);
	return k;	
}

//************************************** Question 5**********************************
void region_codante(char * ADN, int i,int j){
	int l;
	for(l=i+3;l<j;l++) {
		printf("%c",*(ADN+l)); 
	}
	printf("\n");
}


int main() {
	char* T; 
	int *tab;
	int N,M; 
	int k;

	T="ATCTCAATGCTCGGTAATCTCTCATAGCCGACGATGCTACGATAA";
	//N=44;
	N=strlen(T)-1;
	
	// *************** test de codon_start
	printf("---- la recherche de tous les codons start ---- \n");
  	tab=codon_start(T,N);
   	for(k=0;k<N-2;k++){
		if( tab[k]!=-1){ 
			printf("\n le codon (ATG) est dans la position %d",*(tab+k));
			continue;
		}
		else{
			break;	
		}
		
	}	
	// *************** test de codon_stop
		printf("\n\n---- la recherche de tous les codons stop ---- \n");
	for(k=0;k<N-2;k++){
		if( tab[k]!=-1){
			printf("\nle premier codon STOP rencontre apres ATG (start) en position %d est dans la position %d ",*(tab+k),codon_stop(T, *(tab+k))); 
			printf("\n---- affichage Region codante ----\n");
			region_codante(T,*(tab+k),codon_stop(T, *(tab+k)));
		}
		else
			break;
	}
	free(tab);
	return 0;
}
