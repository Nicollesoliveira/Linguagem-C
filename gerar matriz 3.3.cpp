// Gerar uma matriz de 3x3  e imprimar formatado
#include<stdio.h>
main()
{
	int mat[3][3];
	int l,c;
	int valor=100;
	for (l=0 ; l < 3; l++)
	{
		for (c=0; c< 3; c++)
		{
			mat[l][c]=valor;
			valor++;
		}
	}
	// Imprimindo
	for (l=0 ; l < 3; l++)
	{
		for (c=0; c< 3; c++)
		{
			printf("\tposicao %d,%d = %d", l,c,mat[l][c]);
		}
		printf("\n");
	}

}
