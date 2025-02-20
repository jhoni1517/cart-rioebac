#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��es de texto por regi�o
#include <string.h> //biblioteca respons�vel por cuidar dos strings 


int registro() //Fun��o respons�vel por cadastrar o usu�rio
{ 
    //in�cio da cria��o de vari�veis(string)
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    //final da cria��o das vari�veis (strings) 
    
    printf("Digite o CPF a ser cadastrado:");
    scanf("%s",cpf); //"%s" se refere a strings

    strcpy(arquivo,cpf); //Respons�vel por copiar os valores dos arquivos

    FILE *file; //cria o arquivo 
    file= fopen(arquivo,"w"); //"w" � write // cria o arquivo 
    fprintf(file,cpf);// salva o valor da vari�vel 
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

int consulta()  //Fun��o respons�vel por consultar o usu�rio
{
	setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	
	char cpf[40];
	char conteudo[200];
	
    printf("Digite o CPF a ser consultado:");
    scanf("%s",cpf); //"%s" se refere a strings
    
    FILE *file;
    file = fopen(cpf,"r"); // "r" � read que significa ler 
    
    if(file==NULL) //"file==NULL significa caso n�o encontre o objetivo
    { 
    
    printf("N�o foi poss�vel localizar o aquivo!\n");
    
	}
	
	while(fgets(conteudo,200, file)!=NULL)
	{
		printf("\n Essas s�o as informa��es do usu�rio");
		printf("%s", conteudo);
		printf("\n\n\n");
	
	}
	system("pause");
	
}
int deletar()  //Fun��o respons�vel por deletar o cadastro do usu�rio
{
	char cpf[40];
	printf("Digite o cpf a ser deletado:");
	scanf("%s",cpf);

    remove(cpf);
    
    FILE *file;
    file=fopen(cpf,"r");
    
    if(file==NULL)
    {
    	printf("O usu�rio n�o se encontra no sistema!.\n");
    	system("pause");
	}

    

}
int main() //C�gio fonte e principal para funcionalidade do programa 
{
	int opcao=0; //definindo as vari�veis
	int laco=1;
	
	for (laco=1;laco=1;)
	
	{
	
	system("cls");
	
		
	setlocale(LC_ALL,"Portuguese"); //definindo as linguagens
	
	printf("###Cart�rio do Jhoni###\n\n"); //in�cio do menu
	printf("Escolha a op��o desejada do menu:\n\n");
	printf("\t1 - Registrar nomes\n");
	printf("\t2 - Consultar Nomes\n");
	printf("\t3 - deletar Nomes\n\n\n");
	printf("op��o:"); //final do menu
	
	scanf("%d",&opcao); //armazenando as escolhas do usu�rio
	
	system("cls"); //Respons�vel por limpar a tela do que j� foi escrito 
	
		switch(opcao) //in�cio ad sele��o do menu inicial 
	{
		case 1:
		registro(); //chamada de fun��es j� cadastradas no main 
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
 
