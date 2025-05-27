#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main() {
    menu();
    return 0;
}

void menu() {
    int escolha;
    do {
        printf("\n=== Arcade de Minijogos ===\n");
        printf("1. Pergunta e Resposta\n");
        printf("2. Cobra na Caixa!\n");
        printf("3. Gousmas War\n");
        printf("4. Sair\n");
        printf("Escolha um jogo: ");
        scanf("%d", &escolha);
        
        switch (escolha) {
            case 1:
                perguntaEResposta();
                break;
            case 2:
                cobraNaCaixa();
                break;
            case 3:
                gousmasWar();
                break;
            case 4:
                printf("Saindo do arcade...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (escolha != 4);
}

void perguntaEResposta() {
    char *perguntas[5] = {
        "O que um ornitorrinco tem em comum com um réptil?\n1) Ele tem escamas\n2) Ele muda de pele\n3) Ele bota ovos\n4) Ele não tem pulmões", //pergunta criada pelo chatGPT
        "Qual desses filmes NÃO é da Pixar?\n1)  Toy Story\n2) Shrek\n3) Procurando Nemo\n4)  Os Incríveis", //pergunta criada pelo chatGPT
        "Qual dessas frutas flutua na água?\n1)Banana\n2) Melancia\n3) Uva\n4) Abacate", //pergunta criada pelo chatGPT
        "O que acontece se você gritar no espaço?\n1) O som se espalha normalmente\n2) O som fica mais alto\n3) Nada, porque o som não se propaga no vácuo\n4) Você perde a voz imediatamente", //pergunta criada pelo chatGPT
        "Se um pinguim usasse sapatos, qual seria o tamanho do pé dele?\n1) 38\n2) 42\n3) Nenhum, pinguins não precisam de sapatos\n4) 45" //pergunta criada pelo chatGPT
    };
    int respostas[5] = {3, 2, 2, 3, 3};
    int resposta, acertos = 0;
    
    for (int i = 0; i < 5; i++) {
        printf("\n%s\nResposta: ", perguntas[i]);
        scanf("%d", &resposta);
        if (resposta == respostas[i]) {
            printf("Correto!\n");
            acertos++;
        } else {
            printf("Incorreto! A resposta certa era %d.\n", respostas[i]);
        }
    }
    printf("Você acertou %d de 5 perguntas!\n", acertos);
}

void cobraNaCaixa() {
    srand(time(NULL));
    int botao, cobra, escolha, jogador = 0;
    char jogadores[2][50];
    
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogadores[0]);
    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogadores[1]);
    
    do {
        botao = rand() % 5 + 1;
        cobra = rand() % 5 + 1;
    } while (botao == cobra);
    
    while (1) {
        printf("\n%s, escolha uma caixa (1 a 5): ", jogadores[jogador]);
        scanf("%d", &escolha);
        if (escolha == botao) {
            printf("%s encontrou o botão e venceu!\n", jogadores[jogador]);
            break;
        } else if (escolha == cobra) {
            printf("%s encontrou a cobra e perdeu!\n", jogadores[jogador]);
            break;
        } else {
            printf("A caixa estava vazia. Próximo jogador!\n");
            jogador = 1 - jogador;
        }
    }
}

void gousmasWar() {
    int gousmas[2][2] = {{1, 1}, {1, 1}};
    int turno = 0, escolha, ataque, origem;
    char jogadores[2][50];
    
    printf("Digite o nome do Jogador 1: ");
    scanf("%s", jogadores[0]);
    printf("Digite o nome do Jogador 2: ");
    scanf("%s", jogadores[1]);
    
    while (gousmas[0][0] + gousmas[0][1] > 0 && gousmas[1][0] + gousmas[1][1] > 0) {
        printf("\nTurno de %s\n", jogadores[turno]);
        printf("Suas Gousmas: Esquerda (%d), Direita (%d)\n", gousmas[turno][0], gousmas[turno][1]);
        printf("1. Atacar\n2. Dividir Gousma\nEscolha: ");
        scanf("%d", &escolha);
        
        if (escolha == 1) {
            printf("Escolha com qual Gousma atacar (1-Esquerda, 2-Direita): ");
            scanf("%d", &origem);
            if (gousmas[turno][origem - 1] > 0) {
                printf("Escolha qual Gousma inimiga atacar (1-Esquerda, 2-Direita): ");
                scanf("%d", &ataque);
                gousmas[1 - turno][ataque - 1] += gousmas[turno][origem - 1];
                gousmas[turno][origem - 1] = 0;
            } else {
                printf("Essa Gousma não pode atacar pois está zerada!\n");
            }
        } else if (escolha == 2) {
            printf("Escolha qual Gousma dividir (1-Esquerda, 2-Direita): ");
            scanf("%d", &origem);
            if (gousmas[turno][origem - 1] > 1) {
                int metade = gousmas[turno][origem - 1] / 2;
                gousmas[turno][origem - 1] -= metade;
                gousmas[turno][1 - (origem - 1)] += metade;
            } else {
                printf("Essa Gousma não pode ser dividida!\n");
            }
        }
        
        for (int i = 0; i < 2; i++) {
            if (gousmas[0][i] > 5) gousmas[0][i] = 0;
            if (gousmas[1][i] > 5) gousmas[1][i] = 0;
        }
        
        if (gousmas[turno][0] + gousmas[turno][1] == 0) {
            printf("%s perdeu todas as Gousmas! %s venceu!\n", jogadores[turno], jogadores[1 - turno]);
            break;
        }
        
        turno = 1 - turno;
    }
}
