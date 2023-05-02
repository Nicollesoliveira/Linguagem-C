#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<locale.h>
/*
C�digo do Question�rio com um sequencial de 1001 a 1075
Valores aleat�rios para:
- Total de Membros na Fam�lia (1 a 6)
- Tipo Cidad�o (0 = Emprego Formal com carteira� 1 = ConPS Contribuinte da
Previd�ncia Social - 2 = TrInf Trabalhador Informal � 3 = MEI
Microempreendedor Individual)
- Recebe algum Benef�cio (1 Bolsa fam�lia � 2 Seguro Desemprego � 3
Benef�cio Previdenci�rio ou Rendimentos tribut�veis acima de R$28.000,00 - 4
� Nenhum,)
- Renda familiar ( R$ 450,00 at� R$ 4000,00) 

C�digo 	Membros 	Tipo 		Benef�cio 	Renda 	Renda/P
1001 	3 			ConPS 			1 		1500,00
1002 	1 			MEI 			0 		500,00
*/
struct caixa{
	int codigo;
	int mf;
	char tipo[12];
	int cidadao;
	int benefi;
	char beneficio[10];
	float renda;
	float rendaporp;
	int sit;
	char situacao[10];
};
float renda50=0,percent50;
float percentber,neg=0,ben_total=0;
void preenche (int n, caixa*cx){
	for(int i=0;i<n;i++){
		cx[i].codigo=1001+i;
		cx[i].mf=(rand()%6)+1;
		cx[i].cidadao=rand()%4;
		cx[i].benefi=(rand()%4)+1;		
		if(cx[i].cidadao==0){
			sprintf(cx[i].tipo,"Emp. F ");
		}
		if(cx[i].cidadao==1){
			sprintf(cx[i].tipo,"ConPS ");
		}
		if(cx[i].cidadao==2){
			sprintf(cx[i].tipo,"TrInf  ");
		}		
        if(cx[i].cidadao==3){
			sprintf(cx[i].tipo,"MEI   ");	
		}
		if(cx[i].benefi==1){
			sprintf(cx[i].beneficio,"Bolsa fam�lia   ");	 
		}
		if(cx[i].benefi==2){
			sprintf(cx[i].beneficio,"Seguro Desemprego ");
		}
		if(cx[i].benefi==3){
			sprintf(cx[i].beneficio,"Benef�cio Previdenci�rio ");	
		}
		if(cx[i].benefi==4){
			sprintf(cx[i].beneficio,"Nenhum                    ");
		}	
		cx[i].renda=(rand()%3351)+450;
		cx[i].rendaporp=((cx[i].renda/30)*cx[i].mf);		
	}
}
void q3 (int n, caixa*cx){
	for (int i=0;i<n;i++){
	sprintf(cx[i].situacao,"Aceito");
		if((cx[i].renda>3135)||(cx[i].rendaporp>522.5)){
			sprintf(cx[i].situacao,"N�o");	
						
		}
		if(cx[i].benefi==3)sprintf(cx[i].situacao,"N�o");
	}
}
void q4 (int n, caixa*cx){
	for(int i=0;i<n;i++){
		if(cx[i].rendaporp>522.50){
			renda50++;
			percent50=renda50/100;
		}
	}
}

float q5(int n,caixa*cx){
	for(int i=0;i<n;i++){
		if(cx[i].sit==0){
			neg++;
			if (cx[i].benefi==1 && cx[i].sit==1){
				ben_total;
			}
		}
	}
	percentber=(ben_total/neg)*100;
	return(percentber);
}
void apresenta(int n,caixa*cx,float resp_5){
	printf("========================================================================================\nC�digo 	Membros   Tipo 		Benef�cio 	Renda   	Renda/P		Direito\n");
	
	for(int i=0;i<n;i++){
		
		printf("%d\t  %d\t  %s\t%s\tR$ %.2f\tR$ %.2f\t%s\n",cx[i].codigo,cx[i].mf,cx[i].tipo, cx[i].beneficio,cx[i].renda,cx[i].rendaporp,cx[i].situacao);
	}
	printf("=========================================================================================\n");
	printf("\nO percentual de solicitantes com renda familiar acima de meio sal�rio � de: %2.1f%% \n", percent50);
	printf("O percentual de solicita��es negadas por j� estarem recebendo outros benef�cios e aceitos que tem bolsa fam�lia: � de: %2.1f%%\n", percentber);
}
void grava(int n, caixa*cx){
	FILE *pont_arq;
	pont_arq = fopen("TESTE.txt", "w");
	if(pont_arq == NULL){
		printf("Erro na abertura do arquivo!");
	}
	fprintf(pont_arq,"========================================================================================\nC�digo 	Membros   Tipo 		Benef�cio 	Renda   	Renda/P		Direito\n");
	for(int i=0;i<n;i++){
		fprintf(pont_arq,"%d\t  %d\t  %s\t%s\tR$ %.2f\tR$ %.2f\t%s\n",cx[i].codigo,cx[i].mf,cx[i].tipo, cx[i].beneficio,cx[i].renda,cx[i].rendaporp,cx[i].situacao);
	}
	fprintf(pont_arq,"===============================================================================\n");
	fprintf(pont_arq,"\nO percentual de solicitantes com renda familiar acima de meio sal�rio � de: %2.1f%% \n", percent50);
	fprintf(pont_arq,"O percentual de solicita��es negadas por j� estarem recebendo outros benef�cios e aceitos que tem bolsa fam�lia: � de: %2.1f%%\n", percentber);
	fprintf(pont_arq,"Dados gravados com sucesso!");
	fclose(pont_arq);
}
main (){
	setlocale(LC_ALL,"portuguese");
	float resp_5;
	caixa cx [75];
	preenche (75,cx);
	q3 (75,cx);
	q4 (75,cx);
	resp_5=q5 (75,cx);
	apresenta (75,cx,resp_5);
	grava (75, cx);
}
