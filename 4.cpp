#include <stdio.h> //biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria 
#include <locale.h> //bilbioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar das string 

int registro() // Fun��o por cadrastar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��p de variaveis/string
	
	printf("Digite o CPF a ser cadastrado: "); // coletando informa��o do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsavel por copiar ps valores das string
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); // cria o arquivo e o "w" siginifica escrever
	fprintf(file,cpf); //salva o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
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
	setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser cadastrado: ");
    scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file)!= NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
		
	}
	
	system("pause");

}
int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usu�rio a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usu�rio n�o se encontra no sistema!.\n");
		system("pause");
	}
	
}




int main()
{
	int opcao=0; //Ddefinindo vari�veis
	int laco=1;
	
	for(laco=1;laco=1;)
	{
	
	system("cls"); //respons�vel por limpar a tela
	
        setlocale(LC_ALL, "portuguese"); //Definindo a linguagem 
    
	    printf("### cart�rio da EBAC ###\n\n"); // inicio do menu
	    printf("escolha a op�o desejada do menu:\n\n");
	    printf("\t1 - registrar nomes\n");
	    printf("\t2 - consultar nomes\n");
	    printf("\t3 - Deletar nomes\n\n");
	    printf("\t4 - sair do sistema\n\n");
	    printf("Op��o:"); // fim do menu
	
	    scanf("%d", &opcao); //Armazenamenando a escolha do usu�rio
	
	    system("cls");
	    
	    switch(opcao) // inicio da sele��o menu
	    {
	    	case 1:
	    	registro(); //chamada de fun��es
	    	break;
	    	
	    	case 2:
	    	consulta();
		    break;
		    
		    case 3:
			deletar();
		    break;
		    
		    case 4:
		    printf("obrigado por utilizar o sistema!\n");
			return 0;
			break;	
		    
		    default:
			printf("Essa op��o n�o esta disponivel");
			system("pause");
			break;
	    }//fim da sele��o
	    
	    
	    
    }
}
