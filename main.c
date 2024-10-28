#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nome[30];
    char perguntas[3][100];
    char arquivo[30];
} Testemunha;

typedef struct {
    char nome[50];
    char descricao[200];
} Evidencia;

typedef struct {
    char nome[50];
    int culpado;
} Suspeito;

// Função para criar a pasta "dialogos" - versão para Replit
void CriarPastaDialogos() {
    system("mkdir -p dialogos"); // Comando que funciona no Replit para criar pastas
}

// Função para ler um arquivo binário com a história
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

// Função para ler arquivos txt
void LerArquivo(char *nome) {
    char linha[1000];

    FILE *arquivo = fopen(nome, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo para leitura!\n");
        return;
    }

    printf("\033[0;31m"); // Texto em vermelho
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        printf("%s", linha);
    }
    printf("\033[0m"); // Resetar a cor

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

  
    printf("\033[0;31m");  
    printf("Resposta: %s\n\n", resposta);
    printf("\033[0m");     

    fclose(file);
}


void InterrogarTestemunha(Testemunha *testemunhas, int numTestemunhas) {
    char nomeTestemunha[30];

    while (1) {
        printf("\nDigite o nome da testemunha que deseja interrogar (esposa, filha, irmao) ou 'sair' para encerrar: ");
        scanf("%s", nomeTestemunha);

        if (strcmp(nomeTestemunha, "sair") == 0) {
            printf("Saindo da interrogação...\n");
            break;
        }

        int testemunhaEncontrada = -1;
        for (int i = 0; i < numTestemunhas; i++) {
            // Verificando se o nome fornecido é uma parte do nome completo da testemunha
            if (strcmp(nomeTestemunha, "esposa") == 0 && strstr(testemunhas[i].nome, "Esposa") != NULL) {
                testemunhaEncontrada = i;
                break;
            } else if (strcmp(nomeTestemunha, "filha") == 0 && strstr(testemunhas[i].nome, "Filha") != NULL) {
                testemunhaEncontrada = i;
                break;
            } else if (strcmp(nomeTestemunha, "irmao") == 0 && strstr(testemunhas[i].nome, "Irmão") != NULL) {
                testemunhaEncontrada = i;
                break;
            }
        }

        if (testemunhaEncontrada == -1) {
            printf("Testemunha não encontrada. Tente novamente.\n");
            continue;
        }

        Testemunha *testemunha = &testemunhas[testemunhaEncontrada];

        printf("\nVocê escolheu: %s\n", testemunha->nome);

        while (1) {
            printf("Escolha uma pergunta para fazer:\n");
            for (int i = 0; i < 3; i++) {
                printf("%d - %s\n", i + 1, testemunha->perguntas[i]);  // Exibe as perguntas
            }
            printf("Digite o número da pergunta (1, 2 ou 3) ou '0' para encerrar: ");
            
            int opcaoPergunta;
            scanf("%d", &opcaoPergunta);

            if (opcaoPergunta == 0) {
                printf("Encerrando interrogação desta testemunha...\n");
                break;
            }

            if (opcaoPergunta < 1 || opcaoPergunta > 3) {
                printf("Opção inválida! Escolha uma pergunta válida.\n");
                continue;
            }

            LerDialogo(testemunha->arquivo, opcaoPergunta);
        }
    }
}



void Evidencias(Evidencia *evidencias, int numEvidencias) {
    char nomeEvidencia[50];

    while (1) {
        printf("\nDigite o nome da evidência que deseja examinar (celular, faca, cigarro, camisa) ou 'sair' para encerrar: ");
        scanf("%s", nomeEvidencia);

        if (strcmp(nomeEvidencia, "sair") == 0) {
            printf("Saindo da análise de evidências...\n");
            break;
        }

        int evidenciaEncontrada = -1;
        for (int i = 0; i < numEvidencias; i++) {
            // Verificando se o nome da evidência corresponde exatamente
            if (strcmp(nomeEvidencia, "celular") == 0 && strstr(evidencias[i].nome, "Celular") != NULL) {
                evidenciaEncontrada = i;
                break;
            } else if (strcmp(nomeEvidencia, "faca") == 0 && strstr(evidencias[i].nome, "Faca") != NULL) {
                evidenciaEncontrada = i;
                break;
            } else if (strcmp(nomeEvidencia, "cigarro") == 0 && strstr(evidencias[i].nome, "Cigarro") != NULL) {
                evidenciaEncontrada = i;
                break;
            } else if (strcmp(nomeEvidencia, "camisa") == 0 && strstr(evidencias[i].nome, "Camisa") != NULL) {
                evidenciaEncontrada = i;
                break;
            }
        }

        if (evidenciaEncontrada == -1) {
            printf("Evidência não encontrada. Tente novamente.\n");
            continue;
        }

        Evidencia *evidencia = &evidencias[evidenciaEncontrada];

        
        printf("\033[0;31m");  
        printf("\nVocê escolheu: %s\n", evidencia->nome);
        printf("Descrição: %s\n", evidencia->descricao);
        printf("\033[0m");    
    }
}




void AcusarSuspeito(Suspeito *suspeitos, int numSuspeitos) {
    int opcaoSuspeito;
    int evidenciasCorretas = 1;  

    printf("\nEscolha o suspeito para acusar:\n");
    for (int i = 0; i < numSuspeitos; i++) {
        printf("%d - %s\n", i + 1, suspeitos[i].nome);
    }

    printf("Escolha: ");
    scanf("%d", &opcaoSuspeito);
    getchar(); 

    if (opcaoSuspeito < 1 || opcaoSuspeito > numSuspeitos) {
        printf("Opção inválida!\n");
        return;
    }

    Suspeito *suspeitoEscolhido = &suspeitos[opcaoSuspeito - 1];

    if (suspeitoEscolhido->culpado == 1 && evidenciasCorretas) {
        // Código ANSI para cor verde (acertou)
        printf("\033[0;32m");  
        printf("\nParabéns! Você acusou corretamente %s.\n", suspeitoEscolhido->nome);
        printf("História resolvida: O irmão, enfurecido, atacou Hans Müller com um martelo e tentou encobrir o crime.\n");
        printf("Ele transferiu o dinheiro e tentou limpar as evidências na máquina de lavar.\n");
    } else {
        // Código ANSI para cor vermelha (errou)
        printf("\033[0;31m");  
        printf("\nVocê acusou %s, mas esta não é a pessoa culpada.\n", suspeitoEscolhido->nome);
        printf("O verdadeiro culpado ainda está à solta.\n");
    }

    printf("\033[0m");
}


int main(void) {

        Testemunha testemunhas[3] = {
        {
            "Esposa - Olga Müller",
            {
                "Por que tem uma faca com seu sangue na cozinha?",
                "Onde você estava quando seu marido foi pegar a bebida?",
                "Alguém usou uma ferramenta ultimamente?"
            },
            "dialogos/dialogos_esposa.bin"
        },
        {
            "Filha - Sofie Müller",
            {
                "Seus pais brigavam muito?",
                "O que você estava fazendo antes de se reunir para a troca de presentes?",
                "Por que tinha apenas uma roupa sua na máquina?"
            },
            "dialogos/dialogos_filha.bin"
        },
        {
            "Irmão - Erik Müller",
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

        Suspeito suspeitos[] = {
        {"Erik Müller, o irmão", 1},  
        {"Sofie Müller, a filha", 0},
        {"Olga Müller, a esposa", 0}
    };

    int numSuspeitos = sizeof(suspeitos) / sizeof(suspeitos[0]);

    char historia[] = "Na tradicional festa de Natal da Família Müller, todos estão reunidos na grandiosa mansão para celebrar.\n"
                      "Durante a noite, o anfitrião, Hans Müller, decide buscar uma garrafa de whiskey especial guardada em um local isolado, próximo à despensa.\n"
                      "Quando chega a hora do amigo secreto, percebem que Hans ainda não voltou.\n"
                      "A busca por ele leva os convidados a uma cena de horror: Hans foi encontrado morto no chão do depósito,\n"
                      "com o whiskey derramado ao seu lado e a garrafa quebrada em mil pedaços.";
                      

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
        printf(" você possiu um caso novo, deseja investigar? (S/N) ");
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
                        LerArquivo("historia.txt");
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
                        AcusarSuspeito(suspeitos, numSuspeitos);
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