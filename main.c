#include <stdio.h>
#include <string.h>
#include "imagem.h"
#include "flood_fill.h"

void clearBuffer() { 
    int c; 
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    int opcao = -1; 
    char nome[256] = ""; 
    int startX = -1, startY = -1; 
    Cor SubsColor = {255, 0, 255}; 
    ImagemBMP img; 

    while (opcao != 0) {
        printf("\nFlood Fill\n");
        printf("1 Executar com pilha\n");
        printf("2 Executar com fila\n");
        printf("3 Escolher imagem\n");
        printf("4 Escolher coordenada inicial\n");
        printf("0 Encerrar\n");
        printf("Opcao: ");
        
        if (scanf("%d", &opcao) != 1) {
            clearBuffer();
            printf("Opcao invalida.\n");
            continue;
        }

        if (opcao == 1) {
            if (strlen(nome) == 0 || startX == -1 || startY == -1) {
                printf("Erro: Primeiro configure a imagem e as coordenadas.\n");
            } else if (!loadBMP(&img, nome)) { 
                printf("Erro: Não foi possível carregar a imagem.\n");
            } else {
                printf("Iniciando Flood Fill com pilha\n");
                floodFillStack(&img, startX, startY, SubsColor);
                Limpeza(&img); 
                printf("Concluido!\n");
            }
        }
        else if (opcao == 2) {
            if (strlen(nome) == 0 || startX == -1 || startY == -1) {
                printf("Erro: Primeiro configure a imagem e as coordenadas.\n");
            } else if (!loadBMP(&img, nome)) {
                printf("Erro: Não foi possível carregar a imagem.\n");
            } else {
                printf("Iniciando Flood Fill com fila...\n");
                floodFillQueue(&img, startX, startY, SubsColor);
                Limpeza(&img);
                printf("Concluido.\n");
            }
        }
        else if (opcao == 3) {
            printf("Digite o caminho da imagem (precisa ser BMP): ");
            scanf("%255s", nome);
        }
        else if (opcao == 4) {
            printf("Digite X (coluna): ");
            scanf("%d", &startX);
            printf("Digite Y (linha): ");
            scanf("%d", &startY);
        }
        else if (opcao != 0) {
            printf("Opcao invalida.\n");
        }
    }
    return 0;
}
