/*Digite um nome, calcule e mostre quantas letras tem (USANDO FOR E 
WHILE). 


*/
#include<stdio.h>
#include<string.h>
main()
{
	int i, tamanho=0;
	char nome[50];
	printf("Digite seu nome: ");
	gets(nome);
	for (i=0; i< strlen(nome); i++){
		printf("\nletra %c, posicao %d\n", nome[i], i);
		tamanho=tamanho + 1;
	}
	printf("\nO tamnho da string e %d ", tamanho);
}
