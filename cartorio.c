#include <stdio.h> //Biblioteca de comunicação com o usuário
#include <stdlib.h> //Biblioteca de alocação de espaço em memória
#include <locale.h>	//Biblioteca de alocação de texto por região
#include <string.h>	//Biblioteca responsável pelas strings

int registro()  //Função responsável por cadastrar os usuários no sistema
{
	//Início criação de variáveis/strings
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//Final criação de variáveis/strings
	
	printf("Digite o CPF a ser cadastrado: "); //Coletando informação do usuário
	scanf("%s", cpf);           //%s = armazenando string
	
	strcpy(arquivo, cpf);       //Responsável por copiar os valores das strings
	FILE *file;	                 //Cria o arquivo
	file = fopen(arquivo, "w");   //Cria o arquivo, w = escrever
	fprintf(file,cpf);           //Salva o valor da variável
	fclose(file);               //Fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
	
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, arquivo não localizado.\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE * file;
	file = fopen(cpf,"r");
	
	if (file == NULL)
	{
		printf("Usuário removido com sucesso.\n");
		system("pause");
	}
	
	else
	{
		printf("Falha ao remover arquivo.\n");
		system("pause");
	}
	
	
}

int main()
{
	int opcao=0;   //Definindo variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	{
		
		system("cls");      //Responsável por limpar a tela
		
		setlocale(LC_ALL, "Portuguese"); //Definindo linguagem
	
		printf("### Cartório da EBAC ###\n\n"); //Início do menu
		printf("Escolha as opções desejadas do menu:\n\n");
		printf("\t1 - Registra nomes\n");
		printf("\t2 - Consultar nomes\n");
		printf("\t3 - Deletar nomes\n\n"); 
		printf("Opção:");     //Fim do menu
		
		scanf("%d", &opcao);  //Armazenando a escolha do usuário
	
		system("cls");
		
		
		switch(opcao)        //Início da seleção do menu
		{
			case 1:
			registro();      //Chamada de funções
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			default:
			printf("Esta opção não está disponivel!\n");
			system("pause");
			break;
		    //Fim da seleção
		}
	}
}


//Simbolos importantes:		//		\n		""		&		||
