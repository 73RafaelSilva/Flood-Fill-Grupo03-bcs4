#include "imagem.h"
#include <stdio.h>
#include <stdlib.h>

int LoadBMP(ImagemBMP* img, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "rb"); 
    if (!arquivo) return 0;
    
    unsigned char iniciais[54]; 
    fread(iniciais, sizeof(unsigned char), 54, arquivo);
    
    img->largura = *(int*)&iniciais[18];
    img->altura = *(int*)&iniciais[22];
    
    int padding = (4 - (img->largura * 3) % 4) % 4; 
    
    img->pixeis = (Cor*)malloc(img->largura * img->altura * sizeof(Cor));
    
    for (int y = img->altura - 1; y >= 0; y--) {
        for (int x = 0; x < img->largura; x++) {
            fread(&img->pixeis[y * img->largura + x], 3, 1, arquivo);
        }
        fseek(arquivo, padding, SEEK_CUR);
    }
    fclose(arquivo);
    return 1;
}

int SaveBMP(ImagemBMP* img, const char* nomeArquivo) {
    FILE* arquivo = fopen(nomeArquivo, "wb");
    if (!arquivo) return 0;
    
    unsigned char iniciais[54] = { 'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0, 40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 24,0 };
    int padding = (4 - (img->largura * 3) % 4) % 4;
    int TamArq = 54 + (img->largura * 3 + padding) * img->altura; 
    
    *(int*)&iniciais[2] = TamArq;
    *(int*)&iniciais[18] = img->largura;
    *(int*)&iniciais[22] = img->altura;
    
    fwrite(iniciais, sizeof(unsigned char), 54, arquivo);
    unsigned char pad[3] = {0, 0, 0};
    
    for (int y = img->altura - 1; y >= 0; y--) {
        for (int x = 0; x < img->largura; x++) {
            fwrite(&img->pixeis[y * img->largura + x], 3, 1, arquivo);
        }
        fwrite(pad, sizeof(unsigned char), padding, arquivo);
    }
    fclose(arquivo);
    return 1;
}

Cor GetPixel(ImagemBMP* img, int x, int y) { 
    return img->pixeis[y * img->largura + x]; 
}

void SetPixel(ImagemBMP* img, int x, int y, Cor c) { 
    img->pixeis[y * img->largura + x] = c; 
}

int VerifCores(Cor c1, Cor c2) { 
    return c1.r == c2.r && c1.g == c2.g && c1.b == c2.b; 
}

void SalvarPasso(ImagemBMP* img, int passo, const char* prefixo) {
    char formatacao[256]; 
    sprintf(formatacao, "%s_passo_%04d.bmp", prefixo, passo);
    SaveBMP(img, formatacao);
}

void Limpeza(ImagemBMP* img) { 
    free(img->pixeis); 
}
