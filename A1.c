/* Armazenar informacoes de veiculos
- No maximo 10 veiculos
marca do veiculo
modelo - 
ano de fabricacao
placa (formato XXX-YYYY; onde X denota as letras e Y denota os numeros da placa).
===========Funcionalidades===========================
-Listar os veiculos cadastrados;
-Inserir um novo veiculo;
-Listar os veiculos filtrando-se por ano de fabricacao;
-Listar os veiculos com o ano de fabricacao acima de um certo valor especificado pelo usuario. 
- Listar os veiculos filtrando-se pelo modelo.

Obs: O sistema devera armazenar os veiculos ordenados pelo ano de fabricacao, ou seja, 
ao inserir um novo veiculo, este deve ser inserido em ordem crescente de ano de fabricacao.

Funcoes: 
- insert
- list
- listByYear
- listByFilter
- sort
- populate
- menu

*/


#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //colocar acentuacao no prompt
#include <stdbool.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>

//Structs
//Chamado aqui de dados heterogeeos

//Variï¿½vel auxiliar de indice
int i=0;
int j=0;
int num=10;
int close=0;
int countVehicle=0;
int opcao;
int ano;
char modelo[50]="";
int modelSelect=0;
/*Criando a struct vehicle*/
struct vehicle{
	char brand[50];		//Marca do carro
	char model[50];		//modelo do carro
	int year;			//Ano de fabricacao
	char plate[8];		//Placa do carro
};

struct vehicle veiculo[10];			//Criando um array de structs 
struct vehicle veiculoOrdenado[10];	//Criando um array de structs ordenada
struct vehicle temp[1];

char toUpperString(char stringParaMaiuscula[])
{
	for (i=0;i=strlen(stringParaMaiuscula[]);i++)
	{
		stringParaMaiuscula[i] = toupper (stringParaMaiuscula[i]);
	}
	return stringParaMaiuscula;
}


bool insert(void){				//funcao para insercao de um novo veiculo
	//	insere um novo veiculo e incrementa countVehicle
	if (countVehicle < 10)
	{
		i = countVehicle;
		//
		printf ("\n==== Cadastro de veiculo ====\n");
		
		printf ("Fabricante: ");
		//fflush stdin para ler o teclado e fgets() para atribuir na string
		fflush(stdin);
		fgets(veiculo[i].brand,50,stdin);
		//veiculo[i].brand = toupper(veiculo[i].brand);	//Deixa tudo em maiusculas
		veiculo[i].brand = toUpperString(veiculo[i].brand);
		
		printf("Modelo: ");
		//fflush stdin para ler o teclado e fgets() para atribuir na string
		fflush(stdin);
		fgets(veiculo[i].model,50,stdin);
		veiculo[i].model = toupper(veiculo[i].model);	//Deixa tudo em maiusculas
		
		printf("Ano: ");
		scanf("%d", &veiculo[i].year);
		
		printf("Placa (formato XXX-YYYY) : ");
		//fflush stdin para ler o teclado e fgets() para atribuir na string
		fflush(stdin);
		fgets(veiculo[i].plate,9,stdin);
		//
		sortList();
		//
		countVehicle++;
		//
		printf ("\n Veiculo %d inserido com sucesso\n",countVehicle);
		//
	}
	//
	return (0);
}

void list(void){
	printf("\n === IMPRIMINDO ===\n");
	for (i=0;i<10;i++){

		printf("\n===== Veiculo %d =====\n",i+1);
		printf("\n Fabricante : %s",veiculo[i].brand);
		printf("\n Modelo : %s",veiculo[i].model);
		printf("\n Ano : %d",veiculo[i].year);
		printf("\n Placa : %s\n",veiculo[i].plate);

		getch();
	}
	getch();

}

void sortList(void){

	
/* Inicio do Bubble sort */
	for (i = 0; i < num; i++)
	{
			for (j = 0; j < (num - i - 1); j++)
			{
				if (veiculo[j].year > veiculo[j + 1].year)
				{
					temp[0]= veiculo[j];
					veiculo[j] = veiculo[j + 1];
					veiculo[j + 1] = temp[0];
				}
			}
	}
		
}

void populate(void)
{
	//
	strcpy(veiculo[0].brand,"FIAT");
	strcpy(veiculo[0].model,"UNO");
	veiculo[0].year=1992;
	strcpy(veiculo[0].plate,"ABC-1234");
	//
	sortList();
	//
	strcpy(veiculo[1].brand,"VW");
	strcpy(veiculo[1].model,"GOL");
	veiculo[1].year=1991;
	strcpy(veiculo[1].plate,"YKJ-1254");
	//
	sortList();
	//
	strcpy(veiculo[2].brand,"JEEP");
	strcpy(veiculo[2].model,"WILLIS");
	veiculo[2].year=1965;
	strcpy(veiculo[2].plate,"OLD-1965");
	//
	sortList();
	//
	strcpy(veiculo[3].brand,"FIAT");
	strcpy(veiculo[3].model,"TORO");
	veiculo[3].year=2020;
	strcpy(veiculo[3].plate,"GMH-8753");
	//
	sortList();
	//
	strcpy(veiculo[4].brand,"GM");
	strcpy(veiculo[4].model,"VECTRA");
	veiculo[4].year=2016;
	strcpy(veiculo[4].plate,"KMF-8264");
	//
	sortList();
	//
	strcpy(veiculo[5].brand,"VW");
	strcpy(veiculo[5].model,"FOX");
	veiculo[5].year=2015;
	strcpy(veiculo[5].plate,"EBM-7842");
	//
	sortList();
	//
	strcpy(veiculo[6].brand,"FORD");
	strcpy(veiculo[6].model,"KA");
	veiculo[6].year=2018;
	strcpy(veiculo[6].plate,"FTN-7887");
	//
	sortList();
	//
	strcpy(veiculo[7].brand,"FORD");
	strcpy(veiculo[7].model,"FIESTA");
	veiculo[7].year=2014;
	strcpy(veiculo[7].plate,"EBM-4584");
	//
	sortList();
	//
	strcpy(veiculo[8].brand,"FIAT");
	strcpy(veiculo[8].model,"MOBI");
	veiculo[8].year=2019;
	strcpy(veiculo[8].plate,"PKX-8744");
	//
	sortList();
	//
	strcpy(veiculo[9].brand,"RENAULT");
	strcpy(veiculo[9].model,"DUSTER");
	veiculo[9].year=2016;
	strcpy(veiculo[9].plate,"FBM-8547");
	//
	sortList();
	//
	
}

void listByYear(int ano)
{
		printf("\n === Lista a partir do ano %d ===\n",ano);
	for (i=0;i<10;i++){
		if (veiculo[i].year >= ano)
		{
			printf("\n===== Veiculo %d =====\n",i+1);
			printf("\n Fabricante : %s",veiculo[i].brand);
			printf("\n Modelo : %s",veiculo[i].model);
			printf("\n Ano : %d",veiculo[i].year);
			printf("\n Placa : %s\n",veiculo[i].plate);
		}
		
	}
}

void listByModel(char modelo[])
{
		int aux;
		printf("\n === Lista veiculos modelo %s ===\n",modelo);
	for (i=0;i<10;i++){
		modelSelect=strcmp(veiculo[i].model, modelo);
		//
		/*
		//Precisei realizar a analise de porque o list by model nao funcionava
		printf("\n %s", veiculo[i].model);
		
		aux=strlen(veiculo[i].model);		//num caract 
		printf("%d",aux);
		printf("\n %s", modelo);
		aux=strlen(modelo);					//num caract variavel de entrada
		printf("%d",aux);
		*/
		//
		if (modelSelect==0)
		{
			printf("\n===== Veiculo %d =====\n",i+1);
			printf("\n Fabricante : %s",veiculo[i].brand);
			printf("\n Modelo : %s",veiculo[i].model);
			printf("\n Ano : %d",veiculo[i].year);
			printf("\n Placa : %s\n",veiculo[i].plate);
		}
		
	}
}

void menu (void)
{
	//
	//Laco para deixar todos os campos year com valores 9999
	//Para que o sort não encontre lixo e deixe tudo em ordem
	for(i=o;i<10;i++)
	{
		veiculo[i].year=9999;
	}
	//
	printf("\n === Selecione uma opcao ===\n");
	printf("\n 1 - Inserir novo veiculo   \n");
	printf("\n 2 - Inserir veiculos automaticamente\n");
	printf("\n 3 - Listar veiculos\n");
	printf("\n 4 - Listar veiculos com filtro por ano\n");
	printf("\n 5 - Listar veiculos com filtro por modelo\n");
	printf("\n 6 - Sair\n");
	//
	scanf("%d", &opcao);
	
	switch(opcao)
	{
		case 1:
			insert();
			break;
		case 2:
			populate();
			printf("\nVeiculos inseirdos com sucesso.\n");
			break;
		case 3:
			list();
			break;
		case 4:
			printf("Insira o ano: ");
			scanf("%d", &ano);
			listByYear(ano);
			break;
		case 5:
			printf("Modelo: ");
			//fflush(stdin);
			//fgets(modelo,50,stdin);
			scanf("%s",modelo);			//Apenas com scanf deu certo, fgets inclui um caracter a mais (lf??)
			modelo = toupper(modelo);
			listByModel(modelo);
			break;
		case 6:
			close=1;
	}
		
}

void main(void) {				//Funcao main

	while (close==0)
	{
		menu();
	}

}//main

