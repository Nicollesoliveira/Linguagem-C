/*VERIFICAR QUANTAS VOGAIS TEM EM UMA STRING


*/
#include<stdio.h>
#include<string.h>
main()
{
	int i, qtd=0;
	char nome[50];
	printf("Digite seu nome: ");
	gets(nome);
	i=0;
	while (i < strlen(nome)) 
	{
		if			 (nome[i]=='A' || nome[i]=='E' || nome[i]=='I' || nome[i]=='O' || nome[i]=='U')
		{
			printf("A posicao da vogal %c e %d\n", nome[i], i);
			qtd++;
		}
		i++;
	}
	printf("\nO a quantidade de vogais he %d", qtd);
}
