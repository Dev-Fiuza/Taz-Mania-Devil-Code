/*----------Declara��o das Bibliotecas----------*/
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctype.h>
#include "analisadorLexico.h"
/*----------------------------------------------*/

/*----------Declara��o das vari�veis----------*/
char *vetor; //Pointeiro que armazena o arquivo

/*----------In�cio da leitura do arquivo do programa----------*/
char leituraPrograma(char* nomePrograma){

    FILE *programa;//ponteiro do arquivo
    char caractere;//recebe um caracter lido do arquivo
    int contadorCaractere = 0; //Receber� o tanto de caracteres que o arquivo tem.
    int aux = 0; //Serve para auxiliar na inser��o de dados no vetor;
    int auxPalavra = 0;
    bool validaString = false;
    bool validaChar = false;

    //Abre o arquivo somente para leitura
/*-------------------------------------------
Se o arquivo n�o for encontrado ou n�o puder
se aberto retornara um mensagem de erro
--------------------------------------------*/
if((programa = fopen(nomePrograma,"r")) == NULL){
std::cout << ":.Erro na Abertura do Arquivo.:" << std::endl;
std::cout << "Verifique se o endereço do arquivo está correto..." << std::endl;
}
/*-------------------------------------------
Enquanto o caractere for diferente do ultimo caractere do arquivo,
ele ir� contar quantos caracteres existem.
--------------------------------------------*/
while((caractere = getc(programa)) != EOF){
    contadorCaractere++;
}

/*--------------------------------------------
Alocando vetor dinamicamente com a quantidade
de caracteres que contem no arquivo
--------------------------------------------*/
vetor = new char[contadorCaractere];
char vetorPalavra[contadorCaractere];

/*--------------------------------------------
Limpeza do vetor para garantir que ele esteja limpo, evitando que
caracteres antigos ou indesejados atrapalhem o novo conte�do.
--------------------------------------------*/
for(int i = 0; i < contadorCaractere; i++){
    vetor[i]=NULL;
}


//Retorna o ponteiro ao in�cio do arquivo
rewind(programa);


//Nova leitura de caracteres do arquivo, por�m agora inserindo caracteres no vetor
while((caractere = getc(programa)) != EOF){

    //Verificando se é início de string
    if(caractere == '"'  && validaString == false){
        //Condicionar a palavra até o último aspas
        vetorPalavra[auxPalavra] = caractere;
        auxPalavra++;
        validaString = true;
    }

    //Verificação para juntar valores dentro da string
    else if (validaString == true){
        //Verificação para saber se é o final da string
        if(caractere == '"'){
            vetorPalavra[auxPalavra] = caractere;
            analisadorLexico(vetorPalavra);
             memset(vetorPalavra,0,sizeof(vetorPalavra));
            auxPalavra = 0;
            validaString = false;
        } else{
            vetorPalavra[auxPalavra] = caractere;
            auxPalavra++;
        }
    }

    //Fazendo a mesma validação de cima, só que para CHAR
    else if(caractere == '\''  && validaChar == false){
        //Condicionar a palavra até o último aspas
        vetorPalavra[auxPalavra] = caractere;
        auxPalavra++;
        validaChar = true;
    }
    //Verificação para juntar valores dentro da string
    else if (validaChar == true){
        //Verificação para saber se é o final da string
        if(caractere == '\''){
            vetorPalavra[auxPalavra] = caractere;
            analisadorLexico(vetorPalavra);
             memset(vetorPalavra,0,sizeof(vetorPalavra));
            auxPalavra = 0;
            validaChar = false;
        } else{
            vetorPalavra[auxPalavra] = caractere;
            auxPalavra++;
        }
    }

    //Validando se é final de escopo
    else if(caractere == 'º'){
        //Analisando ultima palavra antes de fechar a linha
        analisadorLexico(vetorPalavra);
        memset(vetorPalavra,0,sizeof(vetorPalavra));
        auxPalavra = 0;
        //Analisando simbolo de º
        vetorPalavra[0] = caractere;
        analisadorLexico(vetorPalavra);
        memset(vetorPalavra,0,sizeof(vetorPalavra));

    }
    //Validando se é um espaço para fazer a validação do token separado por espaço
    else if(isspace(caractere)){
        analisadorLexico(vetorPalavra);
        memset(vetorPalavra,0,sizeof(vetorPalavra));
        auxPalavra = 0;
    } else{
        vetorPalavra[auxPalavra] = caractere;
        auxPalavra++;
    }
    vetor[aux] = caractere;
    aux++;
}
/*--------------------------------------------
Insere '\0' no final do vetor para
que possa identificar o final.
--------------------------------------------*/
vetor[contadorCaractere] = '\0';

//Fecha o arquivo
fclose(programa);
}
/*----------Fim da leitura do arquivo do programa----------*/
