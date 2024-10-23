#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//função para salvar o caso em um arquivo bínario
void SalvarCaso(char *nome,char *historia) {

    FILE *arquivo = fopen(nome, "wb");
    fwrite(historia, sizeof(char), strlen(historia), arquivo);
    fclose(arquivo);

}

void LerCaso(char *nome) {
    char historia[1000];  
    int caracteres_lidos = 0;  

    FILE *arquivo = fopen(nome, "rb");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    caracteres_lidos = fread(historia, sizeof(char), 999, arquivo); 
    historia[caracteres_lidos] = '\0';

    printf("\nCaso:\n%s\n", historia);

    fclose(arquivo);
}

void LerArquivo(char *nome) {
    char linha[1000];  

    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);  
    }

    fclose(arquivo);
}

void Pistas() {
    char comodo[20];
    char pista;
    
    while (1) {
        printf("\nDigite o cômodo que deseja investigar (cozinha, garagem, deposito) ou 'sair' para encerrar: ");
        scanf("%s", comodo);

        if (strcmp(comodo, "sair") == 0) {
            printf("Saindo da investigação...\n");
            break;
        }

        if (strcmp(comodo, "cozinha") == 0) {
            printf("\n- Digite p para descobrir a primeira pista\n");
            printf("- Digite s para descobrir a segunda pista\n");
            printf("Escolha: ");
            scanf(" %c", &pista); 
            if (pista == 'p' || pista == 'P') {
                printf("\nPista encontrada: ");
                LerArquivo("pistas/cozinha_pista1.txt");
                printf("\n");
            } else if (pista == 's' || pista == 'S') {
                printf("\nPista encontrada: ");
                LerArquivo("pistas/cozinha_pista2.txt");
                printf("\n");
            } else {
                printf("\nPista não encontrada\n");
            }
        } else if (strcmp(comodo, "garagem") == 0) {
            printf("\nPista encontrada: ");
            LerArquivo("pistas/garagem_pista1.txt");
            printf("\n");
        } else if (strcmp(comodo, "deposito") == 0) {
            printf("\n- Digite p para descobrir a primeira pista\n");
            printf("- Digite s para descobrir a segunda pista\n");
            printf("- Digite t para descobrir a terceira pista\n");
            printf("Escolha: ");
            scanf(" %c", &pista);  
            if (pista == 'p' || pista == 'P') {
                printf("\nPista encontrada: ");
                LerArquivo("pistas/deposito_pista1.txt");
                printf("\n");
            } else if (pista == 's' || pista == 'S') {
                printf("\nPista encontrada: ");
                LerArquivo("pistas/deposito_pista2.txt");
                printf("\n");
            } else if (pista == 't' || pista == 'T') {
                printf("\nPista encontrada: ");
                LerArquivo("pistas/deposito_pista3.txt");
                printf("\n");
            } else {
                printf("\nPista não encontrada\n");
            }
        } else {
            printf("Cômodo não reconhecido. Tente novamente.\n");
        }
    }
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

    printf("Digite seu nome: ");
    fgets(nome, 50, stdin); 

    int tamanho = strlen(nome);
    if (nome[tamanho - 1] == '\n') {
        nome[tamanho - 1] = '\0';
    }


    if (strlen(nome) > 0) {
        printf("\nBem-vindo Detetive %s,", nome);
        printf(" você um caso novo, deseja investigar? (S/N) ");
        scanf("%c", &resposta);
        if (resposta == 'S' || resposta == 's'){
            int opcao = 1;
            while (opcao != 0){
                printf("\n\t1 - Ler o arquivo do caso\n");
                printf("\t2 - Investigar cena do crime\n");
                printf("\t3 - Interrogar testemunhas\n");
                printf("\t4 - Verificar Evidências\n");
                printf("\t5 - Acusar\n");
                printf("\t0 - Sair\n");
                printf("\nO que deseja fazer agora, Detetive %s? ", nome);
                scanf(" %d", &opcao);


                switch (opcao) {
                    case 1:
                        LerCaso("historia.bin");
                        printf("\n");
                        break;
                    case 2:
                        Pistas();
                        printf("\n");
                        break;
                    case 3:
                        printf("interrogar....\n");
                        break;
                    case 4:
                        printf("verificar...\n");
                        break;
                    case 5:
                        printf("acuse alguem....\n");
                        break;
                     case 0:
                        printf("Saindo...\n");
                        break;
                     default:
                         printf("Opção inválida\n");
                         break;

                }
            }
             printf("\n");
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