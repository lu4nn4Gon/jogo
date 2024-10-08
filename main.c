#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char nome[50];

    printf("Digite seu nome: ");
    fgets(nome, 50, stdin); 

    int tamanho = strlen(nome);
    if (nome[tamanho - 1] == '\n') {
        nome[tamanho - 1] = '\0';
    }

    if (strlen(nome) > 0) {
        printf("Seu nome é: %s\n", nome);
        printf("Que comecem os jogos!!!!!!!\n");
    } else {
        printf("Nome não pode ser vazio!\n");
    }




    return 0;
}