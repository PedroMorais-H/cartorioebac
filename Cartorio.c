#include <stdio.h> // biblioteca de comunicação com usuário
#include <stdlib.h> // biblioteca de alocação de espaço de memória 
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h>  //biblioteca responsavel por cuidar do string

int registro()  // Funcção responsavel por cadastrar o usuario no sistema
{
	// Inicio criação de variaveis / string
	char arquivo[40];
    char cpf[40];
    char nome[40];
	char sobrenome[40];
	char cargo[40];
	// Final da criação de variaveis
	
	printf("Digita seu CPF: "); // Coletando informação do usuário
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
		printf("Usuario não localizado !\n");
	}	
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
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
		printf("Usuário inexistente \n");
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
	
	     printf("\t Cartório da EBAC \n\n"); // Inicio do menu
	     printf("-> Escolha a opção desejada no menu:\n\n");
	     printf("\t1 - Registro de nomes:\n");
	     printf("\t2 - Consulta de nomes:\n");
	     printf("\t3 - Deletar nomes:\n\n");
	     printf("-> Opção desejada:");  // Fim so menu
	
	     scanf("%d" , &opcao);  // Armazenando a escolha do usuario
	
	     system("cls");  // responsavel limpar a tela
	     
	     switch(opcao)  // inicio seleção de menu
	    {
		    case 1:
			registro();  // chamada de função de registro
			break;
			
			case 2:
			consulta();  // chamada de função de consulta
			break;
			
			case 3:
		    deletar();  // chamada de função de deletar
			break;  

			default: 	 
	        printf("Você selecionou uma opção indisponível. \n\n"); 
	        system("pause");
	        break;
	    	
		}  // Fim de seleção
    }
}
