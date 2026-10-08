#ifndef imagem.h
#define imagem.h

typedef struct {
    unsigned char r, g, b; 
} Cor;

typedef struct {
    int largura, altura;
    Color* pixeis; 
} ImagemBMP;

int loadBMP(ImageBMP* img, const char* filename);
int saveBMP(ImageBMP* img, const char* filename);

#endif
