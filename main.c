#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para salvar o caso em um arquivo bínario
void SalvarCaso(const char *nome, const char *historia) {

    FILE *arquivo = fopen(nome, "wb");
    fwrite(historia, sizeof(char), strlen(historia), arquivo);
    fclose(arquivo);

}




int main(void) {

    char historia[] = "Na tradicional festa de Natal da Família Müller, todos estão reunidos na grandiosa mansão para celebrar.\n"
                      "Durante a noite, o anfitrião, Hans Müller, decide buscar uma garrafa de whiskey especial guardada em um local isolado, próximo à despensa.\n"
                      "Quando chega a hora do amigo secreto, percebem que Hans ainda não voltou.\n"
                      "A busca por ele leva os convidados a uma cena de horror: Hans foi encontrado morto no chão do depósito,\n"
                      "com o whiskey derramado ao seu lado e a garrafa quebrada em mil pedaços.";
                      
    SalvarCaso("historia.bin", historia);

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