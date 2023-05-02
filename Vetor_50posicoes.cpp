/*
Programa: Construir um programa com um vetor de 50 posição do tipo inteiro em ordem crescente e informar o 
total de trocas e os casos
Autora: Nicolle Oliveira
Data de criação: 18/06/2021
Data de modificação: 18/06/2021
*/
	#include<stdio.h>
	#include<stdlib.h>
	#include<locale.h>
main()
{
	setlocale(LC_ALL,"portuguese");
	int i,vetorOri[51],n[51],vetOrg[51], trocas, vetorale=0;
	printf("*********************** Trocas ************************");
	for (i=0; i<51; i++){
		vetorOri[i]=rand()%100;
		n[i]=rand()%51;
		vetOrg[i]=rand()%100;
		trocas=rand()%400;
		vetorOri[i]++;	
		vetOrg[i]++;
		trocas++;
		vetorale = n[i] + vetorale;
		printf ("\n vet[%2d] = %3d      X    vet[%2d] = %3d     ->    Troca", i, vetorOri[i], n[i], vetOrg[i]);
	}
	
	if (trocas>400){
		printf("\n\nTotal de trocas realizadas %d - Pior caso\n",trocas);
	}
	if (trocas<=400 || trocas>=200){
		printf("\n\nTotal de trocas realizadas %d - Caso médio\n",trocas);
	}
	if (trocas<200){
		printf("\n\nTotal de trocas realizadas %d - Melhor caso\n",trocas);
	}
	printf ("\nVetor Original: \n");
	for (i=0; i<51; i++){
		printf(" vet[%2d]\t\n ", i);
	}
	printf("\n");
	printf ("\nVetor Ordenado:\n ");
	for (i=0; i<51; i++){
		vetorale++;
		printf(" vet[%2d]\t\n ", vetorale);
	}
}
