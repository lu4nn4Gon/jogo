#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>   
#include <unistd.h>  

typedef struct {
    char nome[30];        
    char perguntas[3][100]; 
    char arquivo[30];    
} Testemunha;

typedef struct {
    char nome[50];
    char descricao[200];
} Evidencia;

// Função para criar a pasta "dialogos"
void CriarPastaDialogos() {
    struct stat st = {0}; 

    if (stat("dialogos", &st) == -1) {
        mkdir("dialogos", 0700); 
    }
}

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

//funcao para ler arquivos em txt
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
            printf("\n- Digite p para descobrir a primeira pista\n");
            printf("- Digite s para descobrir a segunda pista\n");
            printf("Escolha: ");
            scanf(" %c", &pista);  
            if (pista == 'p' || pista == 'P') {
                printf("\nPista encontrada: ");
                LerArquivo("pistas/garagem_pista1.txt");
                printf("\n");
            } else if (pista == 's' || pista == 'S') {
                printf("\nPista encontrada: ");
                LerArquivo("pistas/garagem_pista2.txt");
                printf("\n");
            } 
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

void CriarArquivosBinarios() {

    CriarPastaDialogos();  
    // Esposa
    FILE *file = fopen("dialogos/dialogos_esposa.bin", "wb");
    if (file == NULL) {
        printf("Erro ao criar o arquivo binário para a esposa.\n");
        return;
    }
    char respostasEsposa[3][300] = {
        "Me cortei enquanto preparava o jantar. Estava distraída, pensando em como a festa poderia ser perfeita. Eu... nunca faria isso com meu marido!",
        "Estava sozinha arrumando os presentes, que os convidados haviam trazido, embaixo da árvore.",
        "Não sei, meu marido não deixava ninguém mexer na caixa de ferramentas."
    };
    fwrite(respostasEsposa, sizeof(respostasEsposa), 1, file);
    fclose(file);

    // Filha
    file = fopen("dialogos/dialogos_filha.bin", "wb");
    if (file == NULL) {
        printf("Erro ao criar o arquivo binário para a filha.\n");
        return;
    }
    char respostasFilha[3][300] = {
        "Ultimamente, sim. Minha mãe descobriu uma traição... foi devastador para ela. Eles estavam sempre discutindo.",
        "Eu estava no meu quarto, ouvindo música alta e fumando. As brigas dos meus pais me deixaram nervosa.",
        "Roupa?… eu nunca usei a máquina, para isso temos empregados."
    };
    fwrite(respostasFilha, sizeof(respostasFilha), 1, file);
    fclose(file);

    // Irmão da Vítima
    file = fopen("dialogos/dialogos_irmao.bin", "wb");
    if (file == NULL) {
        printf("Erro ao criar o arquivo binário para o irmão da vítima.\n");
        return;
    }
    char respostasIrmao[3][300] = {
        "Porque ele estava demorando com a bebida que eu pedi.",
        "Colocando presentes embaixo da árvore.",
        "Com a minha sobrinha, ele não aprovava o seu namoro e isso causava várias brigas."
    };
    fwrite(respostasIrmao, sizeof(respostasIrmao), 1, file);
    fclose(file);
}

void LerDialogo(char *arquivo, int perguntaEscolhida) {
    FILE *file = fopen(arquivo, "rb");
    if (file == NULL) {
        printf("Erro ao abrir o arquivo %s\n", arquivo);
        return;
    }

    fseek(file, (perguntaEscolhida - 1) * sizeof(char) * 300, SEEK_SET);

    char resposta[300];
    fread(resposta, sizeof(char), 300, file);

    printf("Resposta: %s\n\n", resposta);

    fclose(file);
}

void InterrogarTestemunha(Testemunha *testemunhas, int numTestemunhas) {
    int opcaoTestemunha, opcaoPergunta;

    printf("\nEscolha a testemunha para interrogar:\n");
    for (int i = 0; i < numTestemunhas; i++) {
        printf("%d - %s\n", i + 1, testemunhas[i].nome);
    }
    printf("Escolha: ");
    scanf("%d", &opcaoTestemunha);
    getchar();  

    if (opcaoTestemunha < 1 || opcaoTestemunha > numTestemunhas) {
        printf("Opção inválida!\n");
        return;
    }

    Testemunha *testemunha = &testemunhas[opcaoTestemunha - 1];
    printf("\nVocê escolheu: %s\n", testemunha->nome);


    printf("Escolha uma pergunta para fazer:\n");
    for (int i = 0; i < 3; i++) {
        printf("%d - %s\n", i + 1, testemunha->perguntas[i]);
    }
    printf("Escolha: ");
    scanf("%d", &opcaoPergunta);
    getchar();  

    if (opcaoPergunta < 1 || opcaoPergunta > 3) {
        printf("Opção inválida!\n");
        return;
    }

    LerDialogo(testemunha->arquivo, opcaoPergunta);
}

void Evidencias(Evidencia *evidencias, int numEvidencias) {
    int opcaoEvidencia;

    printf("\nEscolha a evidência para examinar:\n");
    for (int i = 0; i < numEvidencias; i++) {
        printf("%d - %s\n", i + 1, evidencias[i].nome);
    }

    printf("Escolha: ");
    scanf("%d", &opcaoEvidencia);
    getchar();  // Limpa o buffer

    if (opcaoEvidencia < 1 || opcaoEvidencia > numEvidencias) {
        printf("Opção inválida!\n");
        return;
    }

    Evidencia *evidencia = &evidencias[opcaoEvidencia - 1];
    printf("\nVocê escolheu: %s\n", evidencia->nome);
    printf("Descrição: %s\n", evidencia->descricao);
}


int main(void) {

        Testemunha testemunhas[3] = {
        {
            "Esposa",
            {
                "Por que tem uma faca com seu sangue na cozinha?",
                "Onde você estava quando seu marido foi pegar a bebida?",
                "Alguém usou uma ferramenta ultimamente?"
            },
            "dialogos/dialogos_esposa.bin"
        },
        {
            "Filha",
            {
                "Seus pais brigavam muito?",
                "O que você estava fazendo antes de se reunir para a troca de presentes?",
                "Por que tinha apenas uma roupa sua na máquina?"
            },
            "dialogos/dialogos_filha.bin"
        },
        {
            "Irmão da Vítima",
            {
                "Por que você ligou várias vezes para o seu irmão?",
                "O que vocês estavam fazendo antes dele ir pegar a bebida?",
                "Ele estava tendo problemas com alguém ultimamente?"
            },
            "dialogos/dialogos_irmao.bin"
        }
    };

       Evidencia evidenciasArray[5] = {
        {"Celular Notificação", "O celular da vítima contém notificações do banco sobre transações feitas para uma conta fantasma"},
        {"Celular Ligação", "O celular da vítima possuia muitas ligações entre ele e o irmão nos últimos dias"},
        {"Faca", "A faca encontrada contém o sangue da esposa da vítima"},
        {"Cigarro", "Um cigarro apagado proximo ao local da morte"},
        {"Camisa", "Uma camisa que pertence a filha foi encontrada na lavadora com sangue"}
    };

    int numEvidenciasCarregadas = 5;

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
                        CriarArquivosBinarios();
                        InterrogarTestemunha(testemunhas, 3);
                        break;
                    case 4:
                        Evidencias(evidenciasArray, numEvidenciasCarregadas);
                        printf("\n");
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