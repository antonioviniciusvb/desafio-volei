/*
Programa: Escala��o de V�lei
Desenvolvedor: Vinicius Veras
Data: 16.05.2015
	Objetivo: O program ir� receber 2 times de V�lei(nome do jogador e n�mero), onde ter� op��o de ordenar a escala��o
	por ordem Alfab�tica ou conforme n�mera��o do jogador

	EXERC�CIO
Elabore um diagrama de blocos utilizando o Diagram Designer e um �nico programa em linguagem C utilizando os conceitos de programa��o estruturada (m�dulos ou fun��es) para resolver as quest�es descritas nos itens a seguir.

ITEM A � Escreva um programa que receba a escala��o dos seis jogadores de cada equipe jogador por jogador e mostre a escala��o em ordem alfab�tica ou por ordem de n�mero da camisa do jogador, de acordo com a escolha do usu�rio.

ITEM B � O programa deve ter uma op��o para exibir  a vista superior de uma quadra de voleibol com as medidas oficiais, como mostrado no desenho a seguir.

ITEM C - O programa deve ler os placares dos sets de uma partida de voleibol, respeitando as regras descritas para o jogo.
Como j� foi dito anteriormente, o programa deve obrigatoriamente utilizar fun��es.
Caso um placar seja inv�lido, o programa dever� desconsider�-lo e pedir uma nova digita��o, at� que o usu�rio entre com um placar v�lido.
A leitura de placar ir� terminar quando uma equipe for a vencedora da partida, ou seja, vencer 3 sets primeiro. Neste caso, deve ser exibida uma mensagem informando o vencedor e o placar final da partida.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define limpa_tela system("cls")


//***************************************************Pr�totipos***********************************

void ordena_numero_de_camisas(void);
void ordena_nome(void);
void mostra_tabela(void);
void calcule_equipe_vencedora(void);
void mostra_time_vencedor_do_set(int ptime1set, int ptime2set);

//***************************************vari�veis globais****************************************

//struct declarada como global para poder ser utilizada nas fun��es

struct time
{	int numero_camisa, set;
	char nome[11], auxiliar[11];
	int retorno;
}; struct time time1[3], time2[3];

int aux=0;

//***************************************************main**********************************************

int main(void)
{
	int i=0,j=0, modo_exibicao=0;
	int tamanho=3;
	char vquadra;

	puts("\n''''''''''''''' Campeonato SP de Volei ''''''''''''''''''");
	puts("\n\n*************   Lista de Escalacao    **************");

//capitando nomes e n�meros de camisas do time 1

	puts("\n-----------------   Ouro Verde FC ---------------");
	for(i=0; i<3;i++)
		{

			printf("\nJogador[%d] = ", i+1);
			fflush(stdin);
			fgets(time1[i].nome, 11, stdin);
			printf("\nN Camisa[%d] = ", i+1);
			scanf("%d", &time1[i].numero_camisa);

		}

//capitando nomes e n�meros de camisas do time 2

	puts("\n---------------  Benfica FC ------------------");
	for(i=0; i<3;i++)
		{
			printf("\nJogador[%d] = ", i+1);
			fflush(stdin);
			fgets(time2[i].nome, 11, stdin);
			printf("\nCamisa[%d] = ", i+1);
			scanf("%d", &time2[i].numero_camisa);
		}

//Receber� escolha de ordena��o para exibi��o da escala��o, alfab�tica ou n�merica

			puts("\n-------------  Modo de Exibicao das Escalacoes -------------------\n");
			printf("\n1) Modo Nome:	Escalacao dos times em ordem Alfabetica\n");
			printf("\n2) Modo Camisa: Escalacao dos times em ordem numerica\n\n");

//Escolha de Modo de exibi��o
		do
		  {
			printf("\nEscolha Modo de Exibicao: ");
			scanf(" %d", &modo_exibicao);

				if((modo_exibicao!=1)&&(modo_exibicao!=2))
					{
						printf("\nEscolha invalida!\n");
					}

		  }while((modo_exibicao!=1)&&(modo_exibicao!=2));

//chamando a fun��o conforme escolha do cliente, ordenar_nome ou ordenar_numero_de_camisas

	if(modo_exibicao == 1)
		{
			ordena_nome();
		}
		else
			if(modo_exibicao == 2)
			{
				ordena_numero_de_camisas();
			}

// Visualiza�ao de tabela, caso desejo do usu�rio
		do
		{
			printf("\nS-N Visualizar Dimensoes da Quadra ");
			scanf(" %c", &vquadra);

			if((vquadra !='s')&&(vquadra!='S')&&(vquadra!='n')&&(vquadra!='N'))
				printf("\nValor invalido!!\n");

		}while((vquadra !='S')&&(vquadra!='s')&&(vquadra!='n')&&(vquadra!='S')&&(vquadra!='N'));

			if((vquadra == 's')||(vquadra == 'S'))
				mostra_tabela();



//Exibi��o de escala��es, ap�s tratados dos dados nas func�es ordenar_nome ou ordenar_n�mero de camisa.

		  		puts("\n''''''''''''''''''''    ESCALACOES ''''''''''''''''''''''''");
			  	puts("\n----------------    Ouro Verde FC --------------------");

				for(i=0; i<tamanho;i++)
				{
					printf("\nJogador[%d]: %s",  i+1, time1[i].nome);
					printf("Camisa [%d]: %d\n", i+1, time1[i].numero_camisa);
				}
					puts("\n------------      BENFICA FC --------------------");

				for(i=0; i<tamanho;i++)
				{
					printf("\nJogador[%d]: %s",  i+1, time2[i].nome);
					printf("Camisa [%d]: %d\n", i+1, time2[i].numero_camisa);
				}
//Chamada de fun��o calcule_equipe_vencedora

						calcule_equipe_vencedora();

system("pause");

//***********************************************************fim da main *********************************************************
}



/*Fun��o: ordena_numero_de_camisas
Objetivo: Organizar n�mero de camisas dos jogadores para mostrar na escala��o
Par�metros Formais: (nenhum, pois os mesmos est�o globais)
Retorno: (nenhum, pois a fun��o ir� trocar as posi��es da struct conforme n�meros e n�o retornar� nada.*/



	void ordena_numero_de_camisas(void)
		{
			int tamanho = 3, i=0, j=0;
//Ir� comparar o n�mero da struct de time 1 e conforme camisa ir� ordenar, e ordenar nome tbm, para a camisa e o nome do jogador ser iguais na hora da escala�ao


			for(i=0; i<tamanho;i++)
			  {
				for(j= i+1; j<tamanho ;j++)
			     {
			     	if(time1[i].numero_camisa>time1[j].numero_camisa)
			     	{
			     		aux = time1[i].numero_camisa;
			     		time1[i].numero_camisa= time1[j].numero_camisa;
			     		time1[j].numero_camisa = aux;

						strcpy(time1[i].auxiliar, time1[i].nome);
		 				strcpy(time1[i].nome, time1[j].nome);
						strcpy(time1[j].nome, time1[i].auxiliar);
					}
				 }
			  }
//Ir� comparar o n�mero da struct de time 2 e conforme camisa ir� ordenar, e ordenar nome tbm, para a camisa e o nome do jogador ser iguais	na hora da escala�ao

			for(i=0; i<tamanho;i++)
			  {
				for(j= i+1; j<tamanho ;j++)
			     {
			     	if(time2[i].numero_camisa>time2[j].numero_camisa)
			     	{
			     		aux = time2[i].numero_camisa;
			     		time2[i].numero_camisa= time2[j].numero_camisa;
			     		time2[j].numero_camisa = aux;

						strcpy(time2[i].auxiliar, time2[i].nome);
		 				strcpy(time2[i].nome, time2[j].nome);
						strcpy(time2[j].nome, time2[i].auxiliar);
					}
				 }
			  }
		}

/*Fun��o: ordena_nome
Objetivo: Organizar nome dos jogadores para mostrar na escala��o
Par�metros Formais: (nenhum, pois os mesmos est�o globais)
Retorno: (nenhum, pois a fun��o ir� trocar as posi��es da struct conforme n�meros e n�o retornar� nada.*/


void ordena_nome(void)
{
	int tamanho = 3, i=0, j=0;

//Ir� comparar o n�mero da struct de time 1 e conforme nome ir� ordenar, e ordenar n�mero tbm, para o nome e a camisa do jogador ser iguais na hora da escala�ao
	for(i=0; i<tamanho; i++)
	 {
	 	for(j=i+1; j<tamanho; j++)
	 	{
		 	if(strcmp(time1[i].nome, time1[j].nome)>0)
		 	{
		 			strcpy(time1[i].auxiliar, time1[i].nome);
		 			strcpy(time1[i].nome, time1[j].nome);
					strcpy(time1[j].nome, time1[i].auxiliar);
					aux = time1[i].numero_camisa;
			      	time1[i].numero_camisa= time1[j].numero_camisa;
			     	time1[j].numero_camisa = aux;
			}
		}
	 }
	 			for(i=0; i<tamanho; i++)
	 			{
	 				for(j=i+1; j<tamanho; j++)
	 				{
		 				if(strcmp(time2[i].nome, time2[j].nome)>0)
		 				{
		 					strcpy(time2[i].auxiliar, time2[i].nome);
		 					strcpy(time2[i].nome, time2[j].nome);
							strcpy(time2[j].nome, time2[i].auxiliar);
							aux = time1[i].numero_camisa;
			     			time2[i].numero_camisa= time2[j].numero_camisa;
			     			time2[j].numero_camisa = aux;
						}
					}
	 			}
}

/*Fun��o: mostra_tabela
Objetivo: mostrar quadra
Pararamtro Formais:(void)
Retorno:(void)*/

void mostra_tabela()
{
	int i,j,k,l,m,n;

	puts("\n-------- Vista Superior da Quadra ---------\n");

//1� ret�ngulo - maior 1
	for(i=0; i<6;i++)
	{
			if(i==0)
			{		for(m=0;m<1;m++)
					{
						if(m==0)
							{
									printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n             TESTE", 196,196,196,196,196,196, 196,196,196,196,196,196, 196,196,196,196,196,196, 196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
									printf("                           %c          %c", 194,179);
							}
						printf("\n                           %c          %c", 179,179);
					}

						printf("\n                     >3-8m %c    >3-5m %c",193,179);


						printf("\n        %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",218,218,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,191);
			}

				if(i ==0)
				{
					printf("%c%c%c%c%c%c%c%c%c", 195,196,196,196,196,196,196,180,179);

				}
					printf(" \n        %c %c                  %c        %c",179,179,179,179);

	}

//2�ret�ngulo - pequeno 1

		for(j=0; j<=3;j++)
		{
			if(j==0)
			{
				printf("\n    ----%c-%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %C---   %c",179,195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180, 191,179);
			}
				if(j==1)
				{
					printf("      %c",179);
				}
					if(j==2)
					{
						printf(" 3m   %c",179);
					}

						if(j == 3)
							{
								printf("      %c",179);
							}

								printf(" \n        %c %c                  %c %c",179,179,179,179,179);
		}


								printf("\n   9m   %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c-%c-     %c",179,195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180,180,179);

//3�ret�ngulo - pequeno 2

		for(k=0; k<3;k++)
		{
			printf(" \n        %c %c                  %c %c",179,179,179,179);

			if(k==1)
				{
					printf(" 3m   %c",179);
				}
					if(k==2)
					{
						printf("      %c",179);
					}
		}
					printf("\n    ----%c-%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c ----   %c",179,195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,179,179);

//4�ret�ngulo - maior 2

		for(l=0;l<6;l++)
		{
			printf(" \n        %C %c                  %c        %c",179,179,179,179);

		}

			printf("\n        %c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c        %c",192,192,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,217,179);
			printf("\n          %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c        %c\n                   9m                 %c\n", 195,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,196,180,179,179);
			printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 196,196,196,196,196,196, 196,196,196,196,196,196, 196,196,196,196,196,196, 196,196,196,196,196,196,196,196,196,196,196,196, 196,196,196,196,196,196,196,196,217);
}

/*Fun��o: calcule_equipe_vencedora
Objetivo: Calcular equipe vencedora de cada set
Pararamtro Formais:(par�metros globais)
Retorno:(void)*/

void calcule_equipe_vencedora()
{
	int i=0,j=0, resultado=0, resultado_2=0, ac_placares_time1=0,ac_placares_time2=0;



		//Inicio For

		for(i=0;i<5;i++)
		 {


		// Caso alguma equipe chegue nos 3 tentos, o break ir� quebrar o looping e mostrar o Placar final

			 if((ac_placares_time1 == 3)||(ac_placares_time2 ==3))
		    	break;

		//Caso o jogo chegue no 5 set ser� enviar para c�, o taie-break

			    if(i == 4)
				{
						puts("\n--------------------- Tie-Break ------------------------\n");


					//Resultado == 0 volta

					 do
					 {

					   //captamdo dados do tie- break e testando, caso resultados <0 e resultados iguais o do while ser� acionado
					  	  do
					  		{
					  			printf("\nPontos - Ouro Verde FC: ");
								scanf(" %d", &time1[i].set);
								printf("\nPontos -  Benfica   FC: ");
								scanf(" %d", &time2[i].set);

								if((time1[i].set<0)||(time2[i].set<0)||(time1[i].set == time2[i].set))
									printf("\nPlacar Invalido!!\n");

							}while((time1[i].set<0)||(time2[i].set<0)||(time1[i].set == time2[i].set));



						//Efetuando o c�lculo para  obter o resultado, onde ser� utilizado nos pr�ximos testes

						if(time1[i].set> time2[i].set)
							{
								resultado = time1[i].set -time2[i].set;

							}
							else
								if(time1[i].set<time2[i].set)
								{
									resultado = time2[i].set-time1[i].set;
								}


							//Caso Resultado == 2, signfica que temos um vencedor, ent�o o break ir� quebraro looping e mostrar� o Placar final

							if(resultado == 2)
								break;

						// *******************************Todas Condic�es Possiveis de Placares


						//CASO os 2 times >=15 e o resultado !=2, siginifica que o valor inserido � inv�lido, ex: time 1 = 16, time 2 = 29, ent�o atribui 0 no resultado para voltar ao 1� do while

						while((time1[i].set>15)&&(time2[i].set>15)&&(resultado !=2))
						{
							resultado = 0;
							break;
						}

						//CASO os 2 times <15 e o resultado !=2, siginifica que o valor inserido � v�lido, ex: time 1 = 15, time 2 = 13, ent�o atribui 2 no resultado para sair do looping e mostrar Placar final							while((time1[i].set<15)&&(time2[i].set<15)&&(resultado !=2))
							while((time1[i].set<15)&&(time2[i].set<15)&&(resultado !=2))
							{
								resultado = 2;
								break;
							}

						//CASO os 2 times <15 e o resultado  == 0 ou  1, siginifica que o valor inserido � inv�lido, ex: time 1 = 15, time 2 = 14, ent�o atribui 0 no resultado para voltar ao 1� do while

								while((time1[i].set<15)&&(time2[i].set<15)&&(resultado == 0)||(resultado == 1))
								{
									resultado = 0;
									break;
								}

						//Caso time 1 <15  e < time 2 ou ao contr�rio e resultado !=2, siginifica que o valor inserido � inv�lido, ex: time 1 = 30, time 2 = 14, ent�o atribui 0 no resultado para voltar ao 1� do while

									while((time1[i].set>15)&&(time1[i].set>time2[i].set)&&(resultado!=2)||(time2[i].set>15)&&(time2[i].set>time1[i].set)&&(resultado!=2))
									{
										resultado = 0;
										break;
									}


						// Acionado quando testes inv�lidos

							if(resultado == 0)
								printf("\nValor Invalido!!\n");

					  //looping resp�nsavel por iniciar o processo de capt��o de dados, caso valores inv�lidos

	       			 }while(resultado == 0);

	       			 //Chamada fun��o mostra_time_vencedor _do_set

						mostra_time_vencedor_do_set(time1[i].set,time2[i].set);


					//acumulador para o resulatdo do tie- break

						if(time1[i].set>time2[i].set)
								{
										ac_placares_time1 = ac_placares_time1 +1;

								}
								else
									if(time1[i].set<time2[i].set)
									{
										ac_placares_time2 = ac_placares_time2 +1;

							   	    }

				//quebrar� todo o looping for e encerra programa

					break;

				}

					printf("\n----------------- Placar do %d%c Set ----------------------\n", i+1,167);


			// A l�gica � a mesma do tie-break
			do
			{   do
				  {

					printf("\nPontos - Ouro Verde FC: ");
					scanf(" %d", &time1[i].set);
					printf("\nPontos -  Benfica   FC: ");
					scanf(" %d", &time2[i].set);

						if((time1[i].set == time2[i].set)||(time1[i].set<0)||(time2[i].set<0)||(time1[i].set<25)&&(time2[i].set<25))
							printf("\nValor Invalido!!\n");

				  }while((time1[i].set == time2[i].set)||(time1[i].set<0)||(time2[i].set<0)||(time1[i].set<25)&&(time2[i].set<25));


								if(time1[i].set>time2[i].set)
								{
									resultado = time1[i].set-time2[i].set;
								}
								else
									if(time1[i].set<time2[i].set)
									{
										resultado = time2[i].set-time1[i].set;
							   	    }

						if((resultado == 2))
							break;


						while((time1[i].set>=25)&&(time2[i].set>=25)&&(resultado !=2))
						{
							resultado = 0;
							break;
						}
							while((time1[i].set<25)&&(time2[i].set<25)&&(resultado !=2))
							{
								resultado = 2;
								break;
							}
								while((time1[i].set<25)&&(time2[i].set<25)&&(resultado == 0)||(resultado == 1))
								{
									resultado = 0;
									break;
								}
									while((time1[i].set>25)&&(time1[i].set>time2[i].set)&&(resultado!=2)||(time2[i].set>25)&&(time2[i].set>time1[i].set)&&(resultado!=2))
									{
										resultado = 0;
										break;
									}


							if(resultado == 0)
								printf("\nValor Invalido!!\n");


	       }while(resultado == 0);


						mostra_time_vencedor_do_set(time1[i].set,time2[i].set);

						if(time1[i].set>time2[i].set)
								{
										ac_placares_time1 = ac_placares_time1 +1;
								}
								else
									if(time1[i].set<time2[i].set)
									{
										ac_placares_time2 = ac_placares_time2 +1;
							   	    }
	   	 }

//Mostrar o Resultado Final, quando algum time ganhar os 3 sets

						if((ac_placares_time1 == 3)||(ac_placares_time2 == 3))
						{
							puts("\n\n\n*********** Resultado Final ***********\n");
							printf("Ouro Verde FC               Benfica FC\n");
							printf("\n    %d                           %d\n", ac_placares_time1,ac_placares_time2);

						}

}

/*Fun��o: Mostra_time_vencedor_do_set
Objetivo: exibir o vencedor de cada set
Pararamtro Formais: ptime1set e ptime2set
Retorno:(void)*/

void mostra_time_vencedor_do_set(int ptime1set,int ptime2set)
{
	//compara time1 e time2 e exibi na tela time vencedor do set

	if(ptime1set>ptime2set)
	{
		printf("\nVencedor: Ouro Verde FC\n");

	}
	else
		if(ptime1set<ptime2set)
		{
			printf("\nVencedor: Benfica FC\n");
		}
}



