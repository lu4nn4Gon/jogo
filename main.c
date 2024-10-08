#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char nome[50];

    //entrada
    printf("Digite seu nome: ");
    fgets(nome, 50, stdin); 

    //tira o espaço
    int tamanho = strlen(nome);
    if (nome[tamanho - 1] == '\n') {
        nome[tamanho - 1] = '\0';
    }

    //verifica se o nome é vazio ou não
    if (strlen(nome) > 0) {
        printf("Seu nome é: %s\n", nome);
        printf("Que comecem os jogos!!!!!!!\n");
    } else {
        printf("Nome não pode ser vazio!\n");
    }




    return 0;
}