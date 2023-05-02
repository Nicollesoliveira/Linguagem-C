/*
Programa: Construir uma matriz 5x5 com opção de itens
Autora: Nicolle Oliveira
Data de criação: 18/06/2021
Data de modificação: 18/06/2021
*/
	#include <stdlib.h>
	#include <stdio.h>
	#include <locale.h>
main(){
	setlocale(LC_ALL,"portuguese");
	int mat[5][5], i, n, num=0, cont;
	
	for(i=0; i<5;i++){
		for (n=0; n<5; n++){
			mat[i][n] = rand()%101;
		}
	}
	for (i=0; i<5; i++) {
    	for (n=0; n<5; n++) {
      		printf("%d\t",mat[i][n]);
    }
   	 printf("\n");
 	}
 	printf("\n");
 	printf("a) Imprimir o maior elemento par da matriz\n");
	printf("b) Imprimir o menor elemento impar da matriz\n");
 	printf("c) Imprimir a matriz sem a diagonal principal (mantendo a formatação)\n");
 	printf("d) Imprimir apenas os números pares (mantendo a formatação)\n");
 	printf("e) Fim\n\n");
  
  	printf("Escolha uma opção de 1 a 5 conforme o alfabeto (ex: a=1, b=2, c=3, d=4, e=5), \nFavor inserir à frente: ");
  	scanf("%d", &cont);
  	printf("\n");
  	fflush(stdin);
  	
  	if (cont==1){
  		for (i=0; i<5; i++) {
        	if (num < (mat[i][n]%2==0)) {
            	num = mat[i][n];
          }
        }
        printf("O maior elemento par da matriz é: %d\n", num);
	}
	if (cont==2){
        for (i=0; i<5; i++) {
        	if (num > (mat[i][n]%2==0)) {
            	mat[i][n]++;
          	}
        	else {
          	num = mat[i][n];
			}
        }
        printf("O menor elemento impar da matriz é: %d\n", num);
	}
	if (cont==3){
		for (i=0; i<5; i++) {          
            for (n=0; n<5; n++) {
            	if (i!=n)
				printf("%d\t", mat[i][n]);
			else
				printf("*\t");
            }
          printf("\n");
        }
	}
	if (cont==4){
		for (i=0; i<5; i++) {
          for (n=0; n<5; n++) {
            if (mat[i][n]%2==0) {
              printf("%d\t",mat[i][n]);
            }
            else {
              printf(" *\t");
            }
          }
          printf("\n");
        }
	}
	if (cont==5){
		printf("Fim");
	} 
	if ((cont==1) || (cont==2) || (cont==3) || (cont==4)){
	printf ("\nDeseja retornar ao menu? Escolha o número desejado: ");
	scanf("%d",& cont);
	fflush (stdin);
	return (cont);
	}
}
