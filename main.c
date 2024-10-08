#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char nome[50];
    char resposta;

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
        printf("Bem-vindo Detetive %s\n", nome);
        printf("Tem um caso novo, deseja investigar: (S/N) \n");
        scanf("%c", &resposta);
        if (resposta == 'S' || resposta == 's'){
            printf("caso aceito \n");
        } else if (resposta == 'N' || resposta == 'n'){
            printf("caso recusado \n");
        } else {
            printf("Resposta inválida \n");
        }
    } else {
        printf("Nome não pode ser vazio!\n");
    }




    return 0;
}