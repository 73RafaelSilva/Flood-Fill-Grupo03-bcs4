#ifndef imagem_h
#define imagem_h

typedef struct {
    unsigned char b, g, r; 
} Cor;

typedef struct {
    int largura, altura;
    Cor* pixeis; 
} ImagemBMP;

int LoadBMP(ImagemBMP* img, const char* NomeArq); 
int SaveBMP(ImagemBMP* img, const char* NomeArq);
Cor GetPixel(ImagemBMP* img, int x, int y); 
void SetPixel(ImagemBMP* img, int x, int y, Cor c); 
void SalvarPasso(ImagemBMP* img, int passo, const char* prefixo);
void Limpagem(ImagemBMP* img);
int VerifCores(Cor c1, Cor c2);

#endif
