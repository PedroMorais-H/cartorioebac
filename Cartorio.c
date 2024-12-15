#include <stdio.h> // biblioteca de comunica��o com usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o de mem�ria 
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h>  //biblioteca responsavel por cuidar do string

int registro()  // Func��o responsavel por cadastrar o usuario no sistema
{
	// Inicio cria��o de variaveis / string
	char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da cria��o de variaveis
	
	printf("Digita seu CPF: "); // Coletando informa��o do usu�rio
	scanf("%s" , cpf);  // %s refere-se as strings
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores da strings
	
	FILE *file;  // cria o arquivo
	file = fopen(arquivo, "w");  //cria o arquivo e "w" write escrever
	fprintf(file,cpf);  // salvo valor da variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo, "a");  // abre o arquivo e atualiza
	fprintf(file,",");  // salva valor da variavel
	fclose(file);  // fecha arquivo
	
	printf("Digite seu primeiro nome: ");  
	scanf("%s" ,nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu sobrenome: ");
	scanf("%s" , sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite seu cargo: ");
	scanf("%s" , cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
		
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
    char cpf[40];
	char conteudo[200];
	
	printf("Digite seu CPF para consulta: ");
	scanf("%s" ,cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usuario n�o localizado !\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas s�o as informa��es do usu�rio: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	system("pause");
	fclose(file);
		

}

int deletar()
{
    char cpf[40];
    
    printf("Digite o CPF a ser deletado: ");
    scanf("%s", cpf);
    
    remove(cpf);
    
    FILE *file;
    file = fopen(cpf,"r");
    fclose(file);
    
    if(file == NULL)
    {
    	system("cls");
		printf("Usu�rio inexistente \n");
    	system("pause");
	}
    
	fclose(file);
}

int main()
{
    int opcao=0;  // Definindo as variaveis 
	int laco=1;
	 
	 for(laco=1;laco=1;)
	{
	 
	     system("cls");  // responsavel limpar a tela
	     
	     setlocale(LC_ALL, "Portuguese"); // Definindo a linguagem
	
	     printf("\t Cart�rio da EBAC \n\n"); // Inicio do menu
	     printf("-> Escolha a op��o desejada no menu:\n\n");
	     printf("\t1 - Registro de nomes:\n");
	     printf("\t2 - Consulta de nomes:\n");
	     printf("\t3 - Deletar nomes:\n\n");
	     printf("-> Op��o desejada:");  // Fim so menu
	
	     scanf("%d" , &opcao);  // Armazenando a escolha do usuario
	
	     system("cls");  // responsavel limpar a tela
	     
	     switch(opcao)  // inicio sele��o de menu
	    {
		    case 1:
			registro();  // chamada de fun��o de registro
			break;
			
			case 2:
			consulta();  // chamada de fun��o de consulta
			break;
			
			case 3:
		    deletar();  // chamada de fun��o de deletar
			break;  

			default: 	 
	        printf("Voc� selecionou uma op��o indispon�vel. \n\n"); 
	        system("pause");
	        break;
	    	
		}  // Fim de sele��o
    }
}
