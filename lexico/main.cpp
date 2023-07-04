/*----------Declaração das Bibliotecas----------*/
#include <iostream>
#include "buffer.h"
/*----------------------------------------------*/
int main(){

     leituraPrograma("testeSimbolos.tmcd");

    //Leitura do arquivo com o programa
       for (const auto& palavra : palavrasAceitasComChave) {
        std::cout << "Chave: " << palavra.first << ", Palavra: " << palavra.second << std::endl;
    }

    std::cout<< std::endl << std::endl;

    //std::cout << "Palavras Aceitadas: " << palavrasAceitasComChave;
    std::cout<< "Palavras Rejeitadas: ";

    std::cout<< std::endl << std::endl;

    for (const auto& palavra : palavrasRejeitadas) {
        std::cout << palavra << std::endl;
     }

   return 0;
}
