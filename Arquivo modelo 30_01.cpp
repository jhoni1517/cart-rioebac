#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar dos strings 


int registro() //Função responsável por cadastrar o usuário
{ 
    //início da criação de variáveis(string)
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da criação das variáveis (strings) 
    
    printf("Digite o CPF a ser cadastrado:");
    scanf("%s",cpf); //"%s" se refere a strings

    strcpy(arquivo,cpf); //Responsável por copiar os valores dos arquivos

    FILE *file; //cria o arquivo 
    file= fopen(arquivo,"w"); //"w" é write // cria o arquivo 
    fprintf(file,cpf);// salva o valor da variável 
    fclose(file); // fecha o arquivo

    file= fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);




    printf("Digite o nome a ser cadastrado:");
    scanf("%s",nome);

    file= fopen(arquivo,"a");
    fprintf(file,nome);
    fclose(file);
    
    file= fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);



    printf("Digite o sobrenome a ser cadastrado:");
    scanf("%s",sobrenome);

    file= fopen(arquivo,"a");
    fprintf(file,sobrenome);
    fclose(file);

    file= fopen(arquivo,"a");
    fprintf(file,",");
    fclose(file);



    printf("Digite o cargo a ser cadastrado:");
    scanf("%s",cargo);

    file= fopen(arquivo,"a");
    fprintf(file,cargo);
    fclose(file);

    system("pause");
}

int consulta()  //Função responsável por consultar o usuário
{
	setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	
	char cpf[40];
	char conteudo[200];
	
    printf("Digite o CPF a ser consultado:");
    scanf("%s",cpf); //"%s" se refere a strings
    
    FILE *file;
    file = fopen(cpf,"r"); // "r" é read que significa ler 
    
    if(file==NULL) //"file==NULL significa caso não encontre o objetivo
    { 
    
    printf("Não foi possível localizar o aquivo!\n");
    
	}
	
	while(fgets(conteudo,200, file)!=NULL)
	{
		printf("\n Essas são as informações do usuário");
		printf("%s", conteudo);
		printf("\n\n\n");
	
	}
	system("pause");
	
}
int deletar()  //Função responsável por deletar o cadastro do usuário
{
	char cpf[40];
	printf("Digite o cpf a ser deletado:");
	scanf("%s",cpf);

    remove(cpf);
    
    FILE *file;
    file=fopen(cpf,"r");
    
    if(file==NULL)
    {
    	printf("O usuário não se encontra no sistema!.\n");
    	system("pause");
	}

    

}
int main() //Cógio fonte e principal para funcionalidade do programa 
{
	int opcao=0; //definindo as variáveis
	int laco=1;
	
	for (laco=1;laco=1;)
	
	{
	
	system("cls");
	
		
	setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	
	printf("###Cartório do Jhoni###\n\n"); //início do menu
	printf("Escolha a opção desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - deletar Nomes\n\n\n");
	printf("opção:"); //final do menu
	
	scanf("%d",&opcao); //armazenando as escolhas do usuário
	
	system("cls"); //Responsável por limpar a tela do que já foi escrito 
	
		switch(opcao) //início ad seleção do menu inicial 
	{
		case 1:
		registro(); //chamada de funções já cadastradas no main 
		break;		
		
		case 2:
		consulta();
	    break;
	    
	    case 3:
	    deletar();
		break;	
		
		default:
		system("pause");
		break;	
	}
}
 } 
 
