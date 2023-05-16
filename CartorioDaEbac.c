#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o na mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o (exemp. acentos da lingua portuguesa)
#include <string.h> //biblioteca respons�vel pela cria��o das strings (exemp. textos entre aspas "hello world")
#include <unistd.h> //biblioteca respons�vel para utilizar fun��o sleep pelo tempo que quisermos

//in�cio das fun�oes do programa
int cadastro()//fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//in�cio da cria��o das vari�veis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o das vari�veis
	
	//cabe�alho da tela de cadastro
	printf(" __________________________\n");
	printf("|                          |\n");
	printf("| ## Cadastro de Nomes! ## |\n");
	printf("|__________________________|\n\n\n");
	//fim do cabe�alho
	
	printf("Digite o CPF para cadastro: ");//coletando informa��es do usuario
	scanf("%s", cpf);//%s quer dizer que � uma string
	
	strcpy(arquivo, cpf); //copia valores das strings
	
	FILE *file;//acessa a fun�ao FILE na biblioteca para criar o arquivo
	file = fopen(arquivo, "w");//comando file responsavel para criar um arquivo novo "W"
	fprintf(file, cpf);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona informa��o "a"
	fprintf(file, ", ");//adiciona uma virgula como separador de cada dado digitado pelo usuario
	fclose(file);//fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//responsavel por adicionar informa��es no arquivo
	fprintf(file, nome);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//responsavel por adicionar informa��es no arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//responsavel por adicionar informa��es no arquivo
	fprintf(file, sobrenome);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//responsavel por adicionar informa��es no arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//responsavel por adicionar informa��es no arquivo
	fprintf(file, cargo);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//responsavel por adicionar informa��es no arquivo
	fprintf(file, ", ");//adiciona uma virgula no texto no arquivo
	fclose(file);
	
	printf(" _____________________________\n");
	printf("|                             |\n");
	printf("| Cadastro feito com sucesso! |\n");
	printf("|_____________________________|\n\n\n");
    
    sleep(2);//faz a tela parar por 2 segundos antes de retornar ao menu principal
    
    
}

int consulta()
{
	char cpf[40];//cria novamente a variavel por estar em outra fun��o
	char conteudo[200];
	
	printf(" __________________________\n");
	printf("|                          |\n");
	printf("| ## Consulta de Nomes! ## |\n");
	printf("|__________________________|\n\n\n");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//solicita a fun��o file a abrir o arquivo do banco de dados e ler o cpf
	
	if(file == NULL)
	{
		printf(" __________________________\n");
		printf("|                          |\n");
		printf("| Cadastro n�o encontrado! |\n");
		printf("|__________________________|\n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf(" __________________________\n");
		printf("|                          |\n");
		printf("| Informa��es encontradas: |\n");
		printf("|__________________________|\n\n\n");
		printf("%s", conteudo);
		printf("\n\n\n");
	}

	system("pause");//faz o sistena parar na tela selecionada
	
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)	
{
	
	printf(" __________________________\n");
	printf("|                          |\n");
	printf("|   Exclu�do com sucesso!  |\n");
	printf("|__________________________|\n\n\n");
				
	sleep(2);
}
	
}

//in�cio da fun��o main do tipo inteiro
int main ()
{
	//setlocale chama a bliblioteca por regi�o para adicionar os acentos nas strings
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //vari�bvel do tipo inteiro que ir� armazenar a op��o do usu�rio
	int laco=1;
	
	// exibe a tela de boas vindas
    printf(" __________________________\n");
    printf("|                          |\n");
    printf("| ### Cart�rio da EBAC ### |\n");
    printf("|                          |\n");
    printf("|       Bem Vindo(a)!      |\n");
    printf("|__________________________|\n\n");
    
    sleep(1.5); //faz a tela parar por 1.5 segundos ou o tempo que definirmos entre ()
	
	for(laco=1; laco=1;)
	{
		system("cls");//limpa a tela
		
			
		/*printf respon�vel por exibir na tela para o usu�rio
		cada \n - pula uma linha, cada \t - faz com que a linha de um espa�o antes coo um "tab"
		por quest�o est�tica decidi n�o usar o \t para fazer uma esp�cie de "layout" estilo moldura*/
						
		printf(" __________________________\n");
		printf("|                          |\n");
		printf("| ### Cart�rio da EBAC ### |\n");
		printf("|                          |\n");
		printf("|  1-Cadastrar Nomes:      |\n");
		printf("|  2-Consultar Nomes:      |\n");
		printf("|  3-Excluir Nomes:        |\n");
		printf("|                          |\n");
		printf("|__________________________|\n\n\n");
		
		
		//scanf serve com input do usuario
		printf("Digite a op�o desejada: ");
		
		scanf("%d", &opcao); //%d serve para indormar que ir� armazenar uma variavel do tipo inteiro em &opcao
		
		system("cls");  //limpa a tela ap�s o usuario digitar a op��o desejada
		
		switch(opcao)
		{
			case 1: //caso o usuario digite 1 chama a fun��o cadastro
				cadastro();				
				break;
				
			case 2: //caso o usuario digite 2 chama a fun��o consulta
				consulta();				
				break;
				
			case 3: //caso o usuario digite 1 motrar� a tela excluir nomes
				excluir();				
				break;
				
			default: //se o usu�rio digitar qualquer numero ou caractere fora do "padrao" mostrar� tela inv�lida
				
				printf(" ____________________________\n");
				printf("|                            |\n");
				printf("|   ### Op��o inv�lida! ###  |\n");
				printf("| Escolha as op��es de 1 a 3 |\n");
				printf("|____________________________|\n\n\n");
				
				system("pause");
				break;			
		}
		
	}
}


