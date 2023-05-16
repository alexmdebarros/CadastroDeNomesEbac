#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço na memória
#include <locale.h> //biblioteca de alocação de texto por região (exemp. acentos da lingua portuguesa)
#include <string.h> //biblioteca responsável pela criação das strings (exemp. textos entre aspas "hello world")
#include <unistd.h> //biblioteca responsável para utilizar função sleep pelo tempo que quisermos

//início das funçoes do programa
int cadastro()//função responsável por cadastrar os usuários no sistema
{
	//início da criação das variáveis
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação das variáveis
	
	//cabeçalho da tela de cadastro
	printf(" __________________________\n");
	printf("|                          |\n");
	printf("| ## Cadastro de Nomes! ## |\n");
	printf("|__________________________|\n\n\n");
	//fim do cabeçalho
	
	printf("Digite o CPF para cadastro: ");//coletando informações do usuario
	scanf("%s", cpf);//%s quer dizer que é uma string
	
	strcpy(arquivo, cpf); //copia valores das strings
	
	FILE *file;//acessa a funçao FILE na biblioteca para criar o arquivo
	file = fopen(arquivo, "w");//comando file responsavel para criar um arquivo novo "W"
	fprintf(file, cpf);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre o arquivo e adiciona informação "a"
	fprintf(file, ", ");//adiciona uma virgula como separador de cada dado digitado pelo usuario
	fclose(file);//fecha o arquivo
	
	printf("Digite o NOME a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//responsavel por adicionar informações no arquivo
	fprintf(file, nome);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//responsavel por adicionar informações no arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o SOBRENOME a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");//responsavel por adicionar informações no arquivo
	fprintf(file, sobrenome);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//responsavel por adicionar informações no arquivo
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o CARGO a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");//responsavel por adicionar informações no arquivo
	fprintf(file, cargo);//salva o valor digitado no arquivo file
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//responsavel por adicionar informações no arquivo
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
	char cpf[40];//cria novamente a variavel por estar em outra função
	char conteudo[200];
	
	printf(" __________________________\n");
	printf("|                          |\n");
	printf("| ## Consulta de Nomes! ## |\n");
	printf("|__________________________|\n\n\n");
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");//solicita a função file a abrir o arquivo do banco de dados e ler o cpf
	
	if(file == NULL)
	{
		printf(" __________________________\n");
		printf("|                          |\n");
		printf("| Cadastro não encontrado! |\n");
		printf("|__________________________|\n\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf(" __________________________\n");
		printf("|                          |\n");
		printf("| Informações encontradas: |\n");
		printf("|__________________________|\n\n\n");
		printf("%s", conteudo);
		printf("\n\n\n");
	}

	system("pause");//faz o sistena parar na tela selecionada
	
}

int excluir()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	scanf("%s", cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	fclose(file);
	
	if(file == NULL)	
{
	
	printf(" __________________________\n");
	printf("|                          |\n");
	printf("|   Excluído com sucesso!  |\n");
	printf("|__________________________|\n\n\n");
				
	sleep(2);
}
	
}

//início da função main do tipo inteiro
int main ()
{
	//setlocale chama a bliblioteca por região para adicionar os acentos nas strings
	setlocale(LC_ALL, "Portuguese");
	
	int opcao=0; //variábvel do tipo inteiro que irá armazenar a opção do usuário
	int laco=1;
	
	// exibe a tela de boas vindas
    printf(" __________________________\n");
    printf("|                          |\n");
    printf("| ### Cartório da EBAC ### |\n");
    printf("|                          |\n");
    printf("|       Bem Vindo(a)!      |\n");
    printf("|__________________________|\n\n");
    
    sleep(1.5); //faz a tela parar por 1.5 segundos ou o tempo que definirmos entre ()
	
	for(laco=1; laco=1;)
	{
		system("cls");//limpa a tela
		
			
		/*printf responável por exibir na tela para o usuário
		cada \n - pula uma linha, cada \t - faz com que a linha de um espaço antes coo um "tab"
		por questão estética decidi não usar o \t para fazer uma espécie de "layout" estilo moldura*/
						
		printf(" __________________________\n");
		printf("|                          |\n");
		printf("| ### Cartório da EBAC ### |\n");
		printf("|                          |\n");
		printf("|  1-Cadastrar Nomes:      |\n");
		printf("|  2-Consultar Nomes:      |\n");
		printf("|  3-Excluir Nomes:        |\n");
		printf("|                          |\n");
		printf("|__________________________|\n\n\n");
		
		
		//scanf serve com input do usuario
		printf("Digite a opão desejada: ");
		
		scanf("%d", &opcao); //%d serve para indormar que irá armazenar uma variavel do tipo inteiro em &opcao
		
		system("cls");  //limpa a tela após o usuario digitar a opção desejada
		
		switch(opcao)
		{
			case 1: //caso o usuario digite 1 chama a função cadastro
				cadastro();				
				break;
				
			case 2: //caso o usuario digite 2 chama a função consulta
				consulta();				
				break;
				
			case 3: //caso o usuario digite 1 motrará a tela excluir nomes
				excluir();				
				break;
				
			default: //se o usuário digitar qualquer numero ou caractere fora do "padrao" mostrará tela inválida
				
				printf(" ____________________________\n");
				printf("|                            |\n");
				printf("|   ### Opção inválida! ###  |\n");
				printf("| Escolha as opções de 1 a 3 |\n");
				printf("|____________________________|\n\n\n");
				
				system("pause");
				break;			
		}
		
	}
}


