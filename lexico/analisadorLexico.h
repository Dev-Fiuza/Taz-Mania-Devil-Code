//IMPLEMENTAÇÃO DO ANALISADOR
/*----------Declaração das Bibliotecas----------*/
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <regex>
#include <map>
/*----------------------------------------------*/
 std::vector<std::string> palavrasRejeitadas;
 std::vector<std::pair<std::string, std::string>> palavrasAceitasComChave;

/*----------Início Regex dos Tokens----------*/
void validarTokensRegex(char vetorPalavra[]) {

    std::map<std::string, std::regex*> regexToken;
    regexToken["Reservadas"] = new std::regex("ublabu|ublubu|bluble|bleblu|bloo|bleble|weblebleu|uabawababin|uabawababou|uablublu\\?|ueblublableb\\!|wablubluwablubluwablublu|waeblableblibloblu|ablubluble");
    regexToken["Aritmeticos"] = new std::regex("/-\\\\\?|/+\\\\\?");
    regexToken["Logicos"] = new std::regex("`=D´|`D=´|`>=<D´|`D>=<´|`>=<´|´<=>`|u\\.u|o\\.O");
    regexToken["Escopos"] = new std::regex("#`|´#|º|:\\(|\\):|_/|\\_");
    regexToken["Atribuicao"] = new std::regex("-><-");
    regexToken["Variavel"] = new std::regex("[a-zA-Z0-9]+");
    regexToken["ValorNumerico"] = new std::regex("^[+-]?\\d+(\\.\\d+)?$");
    regexToken["ValorBool"] = new std::regex("true|false");
    regexToken["ValorChar"] = new std::regex("'.'");
    regexToken["ValorString"] = new std::regex("\".*?\"");


    for (const auto& entry : regexToken) {
        const std::string& key = entry.first;
        const std::regex& regexRef = *(entry.second);

           if (std::regex_search(vetorPalavra, regexRef)) {
            palavrasAceitasComChave.push_back(std::make_pair(key, vetorPalavra));
            break;
        }
    }

    //Verificando se palavra foi aceita:
    bool validacaoPalavra= false;
    for(const auto& palavra : palavrasAceitasComChave){
        if(palavra.second == vetorPalavra){
            validacaoPalavra = true;
        }
    }
    if(validacaoPalavra == false){
        palavrasRejeitadas.push_back(vetorPalavra);
    }

    // Liberando a memória alocada
    for (const auto& entry : regexToken) {
        delete entry.second;
    }
}

/*----------Fim Regex dos Tokens----------*/

//LÓGICA DO ANALISADOR
void analisadorLexico(char vetorPalavra[]){
    //string palavra = vetorPalavra;
    validarTokensRegex(vetorPalavra);
}

